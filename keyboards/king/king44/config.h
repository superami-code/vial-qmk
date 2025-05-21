// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 12

#define VIAL_KEYBOARD_UID {0x4B, 0x69, 0x6E, 0x67, 0x53, 0x70, 0x61, 0x6F}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define MATRIX_INPUT_PRESSED_STATE 1 // reverse default pressed, the IR detectors pull the pin low when not-pressed
#define MATRIX_SELECT_ROW_HIGH // Required for v1.0 with a custom matrix.c
#define MATRIX_UNSELECT_DRIVE_HIGH
//#define MATRIX_IO_DELAY 30
#define MATRIX_IO_DELAY_AFTER_UNSELECT 120
#define MATRIX_IO_DELAY_AFTER_SELECT 15

/* #define RGB_MATRIX_FRAMEBUFFER_EFFECTS #define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_LED_COUNT 1
#define RGB_MATRIX_SPLIT { 1, 0 }
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
*/

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLECOL2ROW
//#define SPLIT_OLED_ENABLE
#define SPLIT_ACTIVITY_ENABLE
//define OLED_TIMEOUT 0
//#define SPLIT_ST7565_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_LED_STATE_ENABLE
//#define NO_SUSPEND_POWER_DOWN
#define PERMISSIVE_HOLD

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#ifdef POINTING_DEVICE_POSITION_LEFT
#define MASTER_LEFT
#else
#define MASTER_RIGHT
#endif

#define TAPPING_TOGGLE 3


#ifdef POINTING_DEVICE_POSITION_LEFT
#define POINTING_DEVICE_ROTATION_270
#endif
#ifdef POINTING_DEVICE_POSITION_RIGHT
#define POINTING_DEVICE_ROTATION_90
#endif
#if defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_MIDDLE)
#endif

#ifdef POINTING_DEVICE_TRACKPOINT_VENDOR
// The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
#define PS2_MOUSE_USE_REMOTE_MODE

// Serial uses PIO0, change PS2 to PIO1.
#define PS2_PIO_USE_PIO1

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y
#define PS2_DATA_PIN    GP10 // TODO double check, and make use of TP_RST
#define PS2_CLOCK_PIN   GP11

// Start faster when keyboard resets.
#define PS2_MOUSE_INIT_DELAY 500
#endif

// Common settings to both busywait and interrupt.
#if defined(PS2_DRIVER_BUSYWAIT) || defined(PS2_DRIVER_INTERRUPT)
#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

//#define PS2_CLOCK_PIN   D3
////#define PS2_DATA_PIN    B4

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

#ifdef OLED_ENABLE
#    define I2C_DRIVER I2CD1
#    define I2C1_SCL_PIN GP2
#    define I2C1_SDA_PIN GP3
#    define OLED_BRIGHTNESS 128
#    define OLED_FONT_H "keyboards/mlego/m65/lib/glcdfont.c"
#endif

//#define RP2040_FLASH_GD25Q64CS
