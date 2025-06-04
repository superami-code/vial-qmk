#pragma once

// #define SPLIT_TRANSPORT_MIRROR // mirrors master side matrix to slave, not really needed
#define SPLIT_LAYER_STATE_ENABLE // needed or OLED and RGB layer state display
// #define SPLIT_LED_STATE_ENABLE // probably don't need this
// #define SPLIT_MODS_ENABLE // probably don't need this
#define SPLIT_WPM_ENABLE // for cat animation

#ifdef OLED_ENABLE
#define SPLIT_OLED_ENABLE // this is just on/off state of OLED
#endif
//#define SPLIT_ST7565_ENABLE
//#define SPLIT_POINTING_ENABLE
#define SPLIT_HAPTIC_ENABLE // we do this explicitly based on state
#define SPLIT_ACTIVITY_ENABLE

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#ifdef SIDE_LEFT
#define SOFT_SERIAL_PIN GP1
#else
#define SOFT_SERIAL_PIN GP0
#endif

#ifdef POINTING_DEVICE_LEFT
#define MASTER_LEFT
#else
#define MASTER_RIGHT
#endif

#define SELECT_SOFT_SERIAL_SPEED 4

