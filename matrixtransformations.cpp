#include "appcontext.h"
#include "matrixtransformations.h"
#include <math.h>
#include <cmath>


Matrix4x4 matrixIdentity() {
    Matrix4x4 mat = {{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    }};
    return mat;
}

Point2D projectPoint(Point3D* point, AppContext* context, float width, float height) {
    Point3D transformed = *point;

    Matrix4x4 transform = matrixIdentity();

    matrixScale(&transform, context->scale);
    matrixTranslate(&transform, context->translation.x, context->translation.y, context->translation.z);
    matrixRotateX(&transform, context->xRotation);
    matrixRotateY(&transform, context->yRotation);
    matrixRotateZ(&transform, context->zRotation);

    transformed = matrixMultPoint(&transform, &transformed);

    float centerX = width / Constants::DIVISOR_FOR_CENTER;
    float centerY = height / Constants::DIVISOR_FOR_CENTER;

    float perspective = 1.0 / (1.0 + transformed.z * Constants::COEFFICIENT_PERSPECTIVE);

    Point2D result;
    result.x = centerX + transformed.x * perspective;
    result.y = centerY - transformed.y * perspective;

    return result;
}

void matrixScale(Matrix4x4* mat, float scale) {
    mat->matrix[0][0] *= scale;
    mat->matrix[1][1] *= scale;
    mat->matrix[2][2] *= scale;
}

void matrixTranslate(Matrix4x4* mat, float translateX, float translateY, float translateZ) {
    mat->matrix[0][3] = translateX;
    mat->matrix[1][3] = translateY;
    mat->matrix[2][3] = translateZ;
}

void matrixRotateX(Matrix4x4* mat, float angle) {
    float rad = angle * Constants::PI / 180.0;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    Matrix4x4 rot = matrixIdentity();
    rot.matrix[1][1] = cosA;
    rot.matrix[1][2] = sinA;
    rot.matrix[2][1] = -sinA;
    rot.matrix[2][2] = cosA;

    Matrix4x4 result;
    for (int i = 0; i < Constants::MATRIX_SIZE; ++i) {
        for (int j = 0; j < Constants::MATRIX_SIZE; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < Constants::MATRIX_SIZE; ++k) {
                result.matrix[i][j] += mat->matrix[i][k] * rot.matrix[k][j];
            }
        }
    }
    *mat = result;
}

void matrixRotateY(Matrix4x4* mat, float angle) {
    float rad = angle * Constants::PI / 180.0;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    Matrix4x4 rot = matrixIdentity();
    rot.matrix[0][0] = cosA;
    rot.matrix[0][2] = -sinA;
    rot.matrix[2][0] = sinA;
    rot.matrix[2][2] = cosA;

    Matrix4x4 result;
    for (int i = 0; i < Constants::MATRIX_SIZE; ++i) {
        for (int j = 0; j < Constants::MATRIX_SIZE; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < Constants::MATRIX_SIZE; ++k) {
                result.matrix[i][j] += mat->matrix[i][k] * rot.matrix[k][j];
            }
        }
    }
    *mat = result;
}

void matrixRotateZ(Matrix4x4* mat, float angle) {
    float rad = angle * Constants::PI / 180.0;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    Matrix4x4 rot = matrixIdentity();
    rot.matrix[0][0] = cosA;
    rot.matrix[0][1] = sinA;
    rot.matrix[1][0] = -sinA;
    rot.matrix[1][1] = cosA;

    Matrix4x4 result;
    for (int i = 0; i < Constants::MATRIX_SIZE; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result.matrix[i][j] += mat->matrix[i][k] * rot.matrix[k][j];
            }
        }
    }
    *mat = result;
}

Point3D matrixMultPoint(Matrix4x4* mat, Point3D* point) {
    Point3D result;
    result.x = mat->matrix[0][0] * point->x + mat->matrix[0][1] * point->y + mat->matrix[0][2] * point->z + mat->matrix[0][3];
    result.y = mat->matrix[1][0] * point->x + mat->matrix[1][1] * point->y + mat->matrix[1][2] * point->z + mat->matrix[1][3];
    result.z = mat->matrix[2][0] * point->x + mat->matrix[2][1] * point->y + mat->matrix[2][2] * point->z + mat->matrix[2][3];
    return result;
}
