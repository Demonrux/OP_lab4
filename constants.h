#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
constexpr int LEN_PATH = 300;
constexpr int MAX_SIZE_LINE = 1204;
constexpr int MATRIX_SIZE = 4;
constexpr double PI = 3.141592653589793;
constexpr float AXIS_LENGTH = 300.0;
constexpr int DEFAULT_COUNT  = 0;
constexpr float DEFAULT_VALUE  = 0.0;
constexpr float COEFFICIENT_PERSPECTIVE = 0.001;
constexpr float COEFFICIENT_X_ZAXIS = 2.1;
constexpr float COEFFICIENT_Y_ZAXIS = 2.35;
constexpr float DIVISOR_FOR_CENTER = 2.0;
constexpr float  LINE_WIDTH = 1.5;
constexpr float  AXIS_WIDTH = 2.0;

constexpr float MAX_ANGLE  = 360;
constexpr float DEFAULT_X_ROTATE = 120.0;
constexpr float DEFAULT_ROTATE = 0.0;
constexpr float UNIT_OF_ROTATION = 30.0;

constexpr float DEFAULT_TRANSLATE = 0.0;
constexpr float UNIT_OF_TRANSLATE = 20.0;
constexpr float MAX_TRANSLATE = 280.0;
constexpr float MIN_TRANSLATE = -280.0;

constexpr float DEFAULT_SCALE  = 2.0;
constexpr float MIN_SCALE = 2.0;
constexpr float MAX_SCALE = 13.0;
constexpr float COEFFICIENT_ZOMM_IN = 1.2;
constexpr float COEFFICIENT_ZOMM_OUT = 0.9;

constexpr int MAX_STEP = 8;
constexpr float DEFAULT_STEP = 1.0;
constexpr float MIN_NORMA = 0.0;
constexpr float MAX_NORMB = 30.0;
constexpr float DEFAULT_NORMA = 0.0;
constexpr float DEFAULT_NORMB = 1.0;
}

#endif // CONSTANTS_H
