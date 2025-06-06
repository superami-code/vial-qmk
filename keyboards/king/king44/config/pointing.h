#pragma once

#define PS2_MOUSE_INIT_DELAY 500
#define PS2_MOUSE_SLOW_SCROLL
#define SCROLL_DIVISOR_H 64.0
#define SCROLL_DIVISOR_V 64.0

// The following allows adjusting the mouse pointer speed, if needed
#define PS2_MOUSE_L_MULTIPLIER 1
#define PS2_MOUSE_R_MULTIPLIER 2
#define PS2_MOUSE_U_MULTIPLIER 1
#define PS2_MOUSE_D_MULTIPLIER 1
#define PS2_MOUSE_ADJUST (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_R_MULTIPLIER) || \
                         (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_U_MULTIPLIER) || \
                         (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER) || \
                         (PS2_MOUSE_R_MULTIPLIER != PS2_MOUSE_U_MULTIPLIER) || \
                         (PS2_MOUSE_R_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER) || \
                         (PS2_MOUSE_U_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER)


// The following is for correcting the mouse rotation, base on right or left side mounting
#ifdef POINTING_DEVICE_POSITION_LEFT
#define PS2_MOUSE_ROTATE 270
#endif
#ifdef POINTING_DEVICE_POSITION_RIGHT
#define PS2_MOUSE_ROTATE 90
#endif

/*** Driver Selection ************************************************************/
#ifdef PS2_DRIVER_BUSYWAIT
#define PS2_CLOCK_PIN   GP11
#define PS2_DATA_PIN    GP10
#endif

#ifdef PS2_DRIVER_VENDOR
#define PS2_PIO_USE_PIO1
#define PS2_CLOCK_PIN   GP11
#define PS2_DATA_PIN    GP10
#endif

