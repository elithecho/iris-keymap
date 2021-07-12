#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLED_NUM 10
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define TAPPING_TERM 200

// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_DELAY 0
// #define MOUSEKEY_TIME_TO_MAX 60
// #define MOUSEKEY_MAX_SPEED 7
// #define MOUSEKEY_WHEEL_DELAY 0

#define AUTO_SHIFT_TIMEOUT 135
// #define NO_AUTO_SHIFT_SPECIAL

// #define COMBO_COUNT 1
//
// Optimizations
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
