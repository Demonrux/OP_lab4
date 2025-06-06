#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "appcontext.h"

typedef enum {
    Init,
    LoadData,
    RotateX,
    RotateY,
    RotateZ,
    TranslateX,
    TranslateY,
    TranslateZ,
    ZoomIn,
    ZoomOut,
    ResetView,
    Clear,
    Normalize,
    ApplyStep
} Operation;

void doOperation(Operation operation, AppContext* context, float param = 0); //

#endif // ENTRYPOIN
