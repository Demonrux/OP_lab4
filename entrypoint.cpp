#include "entrypoint.h"
#include "logic.h"

void doOperation(Operation operation, AppContext* context, float param) {
    switch (operation) {
    case Init:
        initializeContext(context);
        break;
    case LoadData:
        loadDataFromFile(context);
        break;
    case RotateX:
        rotateX(context, param);
        break;
    case RotateY:
        rotateY(context, param);
        break;
    case RotateZ:
        rotateZ(context, param);
        break;
    case TranslateX:
        translateX(context, param);
        break;
    case TranslateY:
        translateY(context, param);
        break;
    case TranslateZ:
        translateZ(context, param);
        break;
    case ZoomIn:
        zoom(context, param);
        break;
    case ZoomOut:
        zoom(context, param);
        break;
    case ResetView:
        resetView(context);
        break;
    case Normalize:
        normalizeData(context);
        break;
    case ApplyStep:
        applyStep(context);
        break;
    case Clear:
        freeResources(context);
        break;
    }
}
