// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 12

#if (defined OLED_ENABLE) || (defined HAPTIC_ENABLE)
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#endif

#define VIAL_KEYBOARD_UID {0x4B, 0x69, 0x6E, 0x67, 0x53, 0x70, 0x61, 0x6F}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define MATRIX_INPUT_PRESSED_STATE 1 // reverse default pressed, the IR detectors pull the pin low when not-pressed
#define MATRIX_SELECT_ROW_HIGH // Required for v1.0 with a custom matrix25
#define MATRIX_UNSELECT_DRIVE_HIGH
#define MATRIX_IO_DELAY_AFTER_UNSELECT 150
#define MATRIX_IO_DELAY_AFTER_SELECT 30

#ifdef HAPTIC_ENABLE
//#define HAPTIC_ENABLE_STATUS_LED GP17
#define HAPTIC_ENABLE_PIN GP22
#define HAPTIC_ENABLE_PIN_ACTIVE_LOW
#define DRV2605L_GREETING       DRV2605L_EFFECT_750_MS_ALERT_100
#define DRV2605L_DEFAULT_MODE   DRV2605L_EFFECT_SHARP_TICK_1_100
#endif

/* #define RGB_MATRIX_FRAMEBUFFER_EFFECTS #define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_LED_COUNT 1
#define RGB_MATRIX_SPLIT { 1, 0 }
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
*/

#define DEBOUNCE 5
#if 0
#define SPLIT_TRANSPORT_MIRROR
#define SELECT_SOFT_SERIAL_SPEED 2
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#ifdef OLED_ENABLE
#define SPLIT_OLED_ENABLE
#endif
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_HAPTIC_ENABLE
//#define SPLIT_ST7565_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_LED_STATE_ENABLE
#endif

//#define OLED_TIMEOUT 0
//#define NO_SUSPEND_POWER_DOWN
#define PERMISSIVE_HOLD

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#ifdef SIDE_LEFT
#define SOFT_SERIAL_PIN GP1
#else
#define SOFT_SERIAL_PIN GP0
#endif

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

#if defined(SOFT_SERIAL_PIN) || defined(SERIAL_USART_TX_PIN)
#else
#error SOFT_SERIAL_PIN NOT defined
#endif
