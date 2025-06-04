#pragma once

#define PS2_MOUSE_L_MULTIPLIER 2
#define PS2_MOUSE_R_MULTIPLIER 3
#define PS2_MOUSE_U_MULTIPLIER 2
#define PS2_MOUSE_D_MULTIPLIER 2
#define PS2_MOUSE_ADJUST (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_R_MULTIPLIER) || \
                         (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_U_MULTIPLIER) || \
                         (PS2_MOUSE_L_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER) || \
                         (PS2_MOUSE_R_MULTIPLIER != PS2_MOUSE_U_MULTIPLIER) || \
                         (PS2_MOUSE_R_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER) || \
                         (PS2_MOUSE_U_MULTIPLIER != PS2_MOUSE_D_MULTIPLIER)

// Borrowed From Buzzard
#ifdef PS2_DRIVER_INTERRUPT
#define PS2_CLOCK_PIN   GP11
#define PS2_DATA_PIN    GP10

#define PS2_INT_INIT()  do {    \
    EICRB |= ((1<<ISC61) |      \
              (0<<ISC60));      \
    } while (0)
#define PS2_INT_ON()  do {      \
     EIMSK |= (1<<INT6);        \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT6);        \
} while (0)
#define PS2_INT_VECT   INT6_vect

#endif

#ifdef PS2_DRIVER_BUSYWAIT
#define PS2_CLOCK_PIN   GP11
#define PS2_DATA_PIN    GP10
#endif

#ifdef PS2_DRIVER_VENDOR
#define PS2_PIO_USE_PIO1
#define PS2_CLOCK_PIN   GP11
#define PS2_DATA_PIN    GP10
#endif

#ifdef POINTING_DEVICE_POSITION_LEFT
#define PS2_MOUSE_ROTATE 270
#endif
#ifdef POINTING_DEVICE_POSITION_RIGHT
#define PS2_MOUSE_ROTATE 90
#endif
#if defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_MIDDLE)
#endif

