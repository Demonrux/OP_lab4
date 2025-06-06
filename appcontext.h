#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "constants.h"

typedef enum {
    INCORRECT,
    CORRECT
} ProgramStatus;

typedef struct {
    float x, y;
} Point2D;

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    Point3D point;
    int row, col;
} SurfacePoint;

typedef struct {
    int pointIndex1, pointIndex2;
} SurfaceEdge;

typedef struct {
    SurfacePoint* originalPoints;
    SurfacePoint* points;
    SurfaceEdge* edges;
    int originalRows, originalCols;
    int rows, cols;
    int pointsCount, edgesCount;
    int originalPointsCount;
    float originalMinZ, originalMaxZ;
    float currentMinZ, currentMaxZ;
    float step;
    float normA, normB;
} SurfaceData;

typedef struct {
    SurfaceData surfaceData;
    char currentFilePath[Constants::LEN_PATH];
    int fileLoaded;
    float scale;
    float xRotation, yRotation, zRotation;
    Point3D translation;
} AppContext;

#endif // APPCONTEXT_H
