#include "logic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matrixtransformations.h"
#include <ctype.h>
#include <math.h>

void initializeContext(AppContext* context) {
    memset(context, 0, sizeof(AppContext));
    context->surfaceData.points = NULL;
    context->surfaceData.edges = NULL;
    context->scale = Constants::DEFAULT_SCALE;
    context->xRotation = Constants::DEFAULT_X_ROTATE;
    context->yRotation = Constants::DEFAULT_ROTATE;
    context->surfaceData.originalCols = Constants::DEFAULT_COUNT;
    context->surfaceData.originalRows = Constants::DEFAULT_COUNT;
    context->surfaceData.cols = Constants::DEFAULT_COUNT;
    context->surfaceData.rows = Constants::DEFAULT_COUNT;
    context->zRotation = Constants::DEFAULT_ROTATE;
    context->translation = {Constants::DEFAULT_TRANSLATE, Constants::DEFAULT_TRANSLATE, Constants::DEFAULT_TRANSLATE};
    context->surfaceData.step = Constants::DEFAULT_STEP;
    context->surfaceData.normA = Constants::DEFAULT_NORMA;
    context->surfaceData.normB = Constants::DEFAULT_NORMB;
}

void calculateFileSize(AppContext* context, FILE* file) {
    char line[Constants::MAX_SIZE_LINE];
    int rows = Constants::DEFAULT_COUNT;
    int cols = Constants::DEFAULT_COUNT;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        int currentCols = Constants::DEFAULT_COUNT;

        while (token) {
            currentCols++;
            token = strtok(NULL, ",");
        }

        if (currentCols > cols) {
            cols = currentCols;
        }
        rows++;
    }

    if (rows == Constants::DEFAULT_COUNT|| cols == Constants::DEFAULT_COUNT) {
        fclose(file);
        context->fileLoaded = INCORRECT;
    }

    context->surfaceData.originalCols = cols;
    context->surfaceData.originalRows = rows;

}

void loadDataFromFile(AppContext* context) {
    FILE* file = fopen(context->currentFilePath, "r");
    if (!file) {
        context->fileLoaded = INCORRECT;
    }

    freeResources(context);
    calculateFileSize(context, file);
    context->surfaceData.originalPoints = (SurfacePoint*)malloc(context->surfaceData.originalRows * context->surfaceData.originalCols * sizeof(SurfacePoint));
    context->surfaceData.points = (SurfacePoint*)malloc(context->surfaceData.originalRows * context->surfaceData.originalCols * sizeof(SurfacePoint));
    context->surfaceData.edges = (SurfaceEdge*)malloc((context->surfaceData.originalRows-1)*context->surfaceData.originalCols*2 * sizeof(SurfaceEdge));

    if (!context->surfaceData.originalPoints || !context->surfaceData.points || !context->surfaceData.edges) {
        freeResources(context);
        fclose(file);
        context->fileLoaded = INCORRECT;
    }

    rewind(file);
    createPoints(context, file);
    createEdges(context);
    context->surfaceData.step = Constants::DEFAULT_STEP;

    fclose(file);
    context->fileLoaded = CORRECT;
}

void createPoints(AppContext* context, FILE* file) {
    char line[Constants::MAX_SIZE_LINE];

    int pointIndex = Constants::DEFAULT_COUNT;
    float minZ = INFINITY, maxZ = -INFINITY;

    for (int row = Constants::DEFAULT_COUNT; row < context->surfaceData.originalRows; row++) {
        if (!fgets(line, sizeof(line), file)) break;

        char* token = strtok(line, ",");
        int col = Constants::DEFAULT_COUNT;

        while (token && col < context->surfaceData.originalCols) {
            char* endptr;
            float z = strtof(token, &endptr);

            if (endptr == token) {
                z = Constants::DEFAULT_VALUE;
            }

            context->surfaceData.points[pointIndex].point = {(float)col, (float)row, z};
            context->surfaceData.points[pointIndex].row = row;
            context->surfaceData.points[pointIndex].col = col;

            if (z < minZ) minZ = z;
            if (z > maxZ) maxZ = z;

            pointIndex++;
            col++;
            token = strtok(NULL, ",");
        }
    }

    memcpy(context->surfaceData.originalPoints, context->surfaceData.points, context->surfaceData.originalRows * context->surfaceData.originalCols * sizeof(SurfacePoint));
    context->surfaceData.originalPointsCount = context->surfaceData.originalRows * context->surfaceData.originalCols;
    context->surfaceData.pointsCount = context->surfaceData.originalRows * context->surfaceData.originalCols;

    context->surfaceData.originalMinZ = minZ;
    context->surfaceData.originalMaxZ = maxZ;
    context->surfaceData.currentMinZ = minZ;
    context->surfaceData.currentMaxZ = maxZ;
}

void createEdges(AppContext* context) {
    int edgeIndex = Constants::DEFAULT_COUNT;
    for (int row = Constants::DEFAULT_COUNT; row < context->surfaceData.originalRows -1; row++) {
        for (int col = Constants::DEFAULT_COUNT; col < context->surfaceData.originalCols-1; col++) {
            int current = row * context->surfaceData.originalCols + col;
            int right = row * context->surfaceData.originalCols + (col + 1);
            int bottom = (row + 1) * context->surfaceData.originalCols + col;

            if (edgeIndex < (context->surfaceData.originalRows-1)*context->surfaceData.originalCols*2) {
                context->surfaceData.edges[edgeIndex].pointIndex1 = current;
                context->surfaceData.edges[edgeIndex].pointIndex2 = right;
                edgeIndex++;

                context->surfaceData.edges[edgeIndex].pointIndex1 = current;
                context->surfaceData.edges[edgeIndex].pointIndex2 = bottom;
                edgeIndex++;
            }
        }
    }

    context->surfaceData.edgesCount = edgeIndex;

}

void normalizeData(AppContext* context) {
    if (!context->fileLoaded) return;

    float minVal = context->surfaceData.originalMinZ;
    float maxVal = context->surfaceData.originalMaxZ;
    float a = context->surfaceData.normA;
    float b = context->surfaceData.normB;

    if (maxVal == minVal) return;

    for (int i = Constants::DEFAULT_COUNT; i < context->surfaceData.originalPointsCount; i++) {
        float z = context->surfaceData.originalPoints[i].point.z;
        float normalizedZ = a + (z - minVal) / (maxVal - minVal) * (b - a);
        context->surfaceData.originalPoints[i].point.z = normalizedZ;
    }

    context->surfaceData.originalMinZ = a;
    context->surfaceData.originalMaxZ = b;
    context->surfaceData.currentMinZ = a;
    context->surfaceData.currentMaxZ = b;

    applyStep(context);
}

void calculateBorderZ(AppContext* context) {
    int totalPoints = context->surfaceData.originalPointsCount;
    int side = (int)sqrt(totalPoints);
    int newRows = Constants::DEFAULT_COUNT;
    int newCols = Constants::DEFAULT_COUNT;
    for (int row = Constants::DEFAULT_COUNT; row < side; row += context->surfaceData.step)
        newRows++;
    for (int col = Constants::DEFAULT_COUNT; col < side; col += context->surfaceData.step)
        newCols++;
    if (context->surfaceData.points)
        free(context->surfaceData.points);
    SurfacePoint* newPoints = (SurfacePoint*)malloc(newRows * newCols * sizeof(SurfacePoint));
    if (!newPoints) return;

    float newMinZ = INFINITY, newMaxZ = -INFINITY;
    int newIndex = Constants::DEFAULT_COUNT;
    for (int row = Constants::DEFAULT_COUNT; row < side; row += context->surfaceData.step) {
        for (int col = Constants::DEFAULT_COUNT; col < side; col += context->surfaceData.step) {
            int oldIndex = row * side + col;
            newPoints[newIndex] = context->surfaceData.originalPoints[oldIndex];

            float z = newPoints[newIndex].point.z;
            if (z < newMinZ) newMinZ = z;
            if (z > newMaxZ) newMaxZ = z;

            newIndex++;
        }
    }
    context->surfaceData.points = newPoints;
    context->surfaceData.pointsCount = newRows * newCols;
    context->surfaceData.cols = newCols;
    context->surfaceData.rows = newRows;
    context->surfaceData.currentMinZ = newMinZ;
    context->surfaceData.currentMaxZ = newMaxZ;
}

void applyStep(AppContext* context) {
    if (!context->fileLoaded || context->surfaceData.step <= Constants::DEFAULT_COUNT) return;
    calculateBorderZ(context);

    free(context->surfaceData.edges);
    context->surfaceData.edges = (SurfaceEdge*)malloc((context->surfaceData.rows-1)*context->surfaceData.cols*2 * sizeof(SurfaceEdge));
    if (!context->surfaceData.edges) return;

    int edgeIndex = Constants::DEFAULT_COUNT;
    for (int row = Constants::DEFAULT_COUNT; row < context->surfaceData.rows-1; row++) {
        for (int col = Constants::DEFAULT_COUNT; col < context->surfaceData.cols-1; col++) {
            int current = row * context->surfaceData.cols + col;
            int right = row * context->surfaceData.cols + (col + 1);
            int bottom = (row + 1) * context->surfaceData.cols + col;

            if (edgeIndex < (context->surfaceData.rows-1)*context->surfaceData.cols*2) {
                context->surfaceData.edges[edgeIndex].pointIndex1 = current;
                context->surfaceData.edges[edgeIndex].pointIndex2 = right;
                edgeIndex++;

                context->surfaceData.edges[edgeIndex].pointIndex1 = current;
                context->surfaceData.edges[edgeIndex].pointIndex2 = bottom;
                edgeIndex++;
            }
        }
    }
    context->surfaceData.edgesCount = edgeIndex;
}

float normalizeAngle(float angle) {
    float newAngle = angle;
    if (angle > Constants::MAX_ANGLE)
        newAngle = (angle - Constants::MAX_ANGLE);
    if (angle < 0)
        newAngle = (angle + Constants::MAX_ANGLE);
    return newAngle;
}

float limitTranslate(float translate) {
    float newTranslate = translate;
    if(translate > Constants::MAX_TRANSLATE)
        newTranslate = Constants::MAX_TRANSLATE;
    else if(translate < Constants::MIN_TRANSLATE)
        newTranslate = Constants::MIN_TRANSLATE;
    return newTranslate;
}

void rotateX(AppContext* context, float angle) {
    context->xRotation = normalizeAngle(context->xRotation += angle);
}

void rotateY(AppContext* context, float angle) {
    context->yRotation = normalizeAngle(context->yRotation += angle);
}

void rotateZ(AppContext* context, float angle) {
    context->zRotation = normalizeAngle(context->zRotation += angle);
}

void translateX(AppContext* context, float value) {
    context->translation.x = limitTranslate(context->translation.x += value);
}

void translateY(AppContext* context, float value) {
    context->translation.y = limitTranslate(context->translation.y += value);
}

void translateZ(AppContext* context, float value) {
    context->translation.z = limitTranslate(context->translation.z += value);
}

void zoom(AppContext* context, float factor) {
    context->scale *= factor;
    if (context->scale < Constants::MIN_SCALE) context->scale = Constants::MIN_SCALE;
    if (context->scale > Constants::MAX_SCALE) context->scale = Constants::MAX_SCALE;
}

void resetView(AppContext* context) {
    context->translation = {Constants::DEFAULT_TRANSLATE, Constants::DEFAULT_TRANSLATE, Constants::DEFAULT_TRANSLATE};
    context->scale = Constants::DEFAULT_SCALE;
    context->xRotation = Constants::DEFAULT_X_ROTATE;
    context->yRotation = Constants::DEFAULT_ROTATE;
    context->zRotation = Constants::DEFAULT_ROTATE;
}

void freeResources(AppContext* context) {
    if (!context) return;

    if (context->surfaceData.originalPoints) {
        free(context->surfaceData.originalPoints);
        context->surfaceData.originalPoints = NULL;
    }

    if (context->surfaceData.points) {
        free(context->surfaceData.points);
        context->surfaceData.points = NULL;
    }

    if (context->surfaceData.edges) {
        free(context->surfaceData.edges);
        context->surfaceData.edges = NULL;
    }

    context->surfaceData.pointsCount = Constants::DEFAULT_COUNT;
    context->surfaceData.edgesCount = Constants::DEFAULT_COUNT;
    context->surfaceData.originalPointsCount = Constants::DEFAULT_COUNT;
    context->fileLoaded = false;
    context->currentFilePath[0] = '\0';
}
