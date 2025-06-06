#ifndef LOGIC_H
#define LOGIC_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "appcontext.h"

float normalizeAngle(float angle);
float limitTranslate(float translate);
void createPoints(AppContext* context, FILE* file);
void calculateFileSize(AppContext* context, FILE* file);
void calculateBorderZ(AppContext* context);
void loadDataFromFile(AppContext* context);
void createEdges(AppContext* context);
void initializeContext(AppContext* context);
void rotateX(AppContext* context, float angle);
void rotateY(AppContext* context, float angle);
void rotateZ(AppContext* context, float angle);
void translateX(AppContext* context, float value);
void translateY(AppContext* context, float value);
void translateZ(AppContext* context, float value);
void zoom(AppContext* context, float factor);
void resetView(AppContext* context);
void normalizeData(AppContext* context);
void applyStep(AppContext* context);
void freeResources(AppContext* context);

#endif // LOGIC_H
