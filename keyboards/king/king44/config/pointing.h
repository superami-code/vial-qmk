#pragma once

#if 1
// Borrowed From Buzzard
#ifdef PS2_DRIVER_INTERRUPT
#error PS2_DRIVER_INTERRUPT
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

#else
// King Span method
#ifdef POINTING_DEVICE_TRACKPOINT_VENDOR

#ifdef POINTING_DEVICE_POSITION_LEFT
#define POINTING_DEVICE_ROTATION_270
#endif
#ifdef POINTING_DEVICE_POSITION_RIGHT
#define POINTING_DEVICE_ROTATION_90
#endif
#if defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_MIDDLE)
#endif

// The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
#define PS2_MOUSE_USE_REMOTE_MODE

// Serial uses PIO0, change PS2 to PIO1.
#define PS2_PIO_USE_PIO1

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y
#define PS2_DATA_PIN    GP10 // TODO double check, and make use of TP_RST
#define PS2_CLOCK_PIN   GP11
#define PS2_POWER       GP4

// Start faster when keyboard resets.
#define PS2_MOUSE_INIT_DELAY 500
#endif

// Common settings to both busywait and interrupt.
#if defined(PS2_DRIVER_BUSYWAIT) || defined(PS2_DRIVER_INTERRUPT)
#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

#define PS2_MOUSE_USE_REMOTE_MODE
#endif

#ifdef PS2_DRIVER_INTERRUPT
#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC31) |      \
              (0<<ISC30));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT3);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT3);        \
} while (0)
#define PS2_INT_VECT   INT3_vect
#endif

#endif
