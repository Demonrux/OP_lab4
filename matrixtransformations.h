#ifndef MATRIXTRANSFORMATIONS_H
#define MATRIXTRANSFORMATIONS_H

#include "appcontext.h"

typedef struct {
    float matrix[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE];
} Matrix4x4;

Matrix4x4 matrixIdentity();
Point3D matrixMultPoint(Matrix4x4* mat, Point3D* point);
Point2D projectPoint(Point3D* point, AppContext* context, float width, float height);
void matrixScale(Matrix4x4* mat, float scale);
void matrixTranslate(Matrix4x4* mat, float translateX, float translateY, float translateZ);
void matrixRotateX(Matrix4x4* mat, float angle);
void matrixRotateY(Matrix4x4* mat, float angle);
void matrixRotateZ(Matrix4x4* mat, float angle);

#endif // MATRIXTRANSFORMATIONS_H
