// Copyright 2025 Jacob King (@superami-code)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif

enum {
    _ALPHA,    // default
    _NUMBERS,  // numbers and symbols
    _FUNC,     // F1-F12, Mouse Scroll, PGUP/DWN, TO(4,6,8)
    _105_KEYS, // HOME, END, ARROWS, PGUP/DWN, INS, A-F
    _GAMING,   // PUBG
    _GAMING2,
    _QWERTY,   // Qwerty
    _QWERTY2,  // Copy of numbers
    _GAMING_SHORT,  // Gaming without tapdance
    _GAMING_SHORT2,
    _EMPTY,
    _EMPTY2
};

#define KC_RBRACKET KC_RBRC
#define KC_LBRACKET KC_LBRC
#define KC_BSPACE   KC_BSPC
#define KC_LSHIFT   KC_LSFT
#define KC_RSHIFT   KC_RSFT
#define KC_NONUS_BSLASH KC_NUBS
#define KC_PSCREEN  KC_PSCR
#define KC_SCROLLLOCK KC_SCRL
#define KC_PGDOWN   KC_PGDN
#define KC_LCTRL    KC_LCTL
#define KC_RCTRL    KC_RCTL
#define KC_SCOLON   KC_SCLN

#ifdef POINTING_DEVICE_TRACKPOINT_VENDOR
#error POINTING_DEVICE_TRACKPOINT_VENDOR is ACTIVE
#include "ps2_mouse.h"
#define PS2_MOUSE_L_MULTIPLIER 8
#define PS2_MOUSE_R_MULTIPLIER 5
#define PS2_MOUSE_U_MULTIPLIER 5
#define PS2_MOUSE_D_MULTIPLIER 5

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  // Moving left.
  if (mouse_report->x < 0) {
    mouse_report->x *= PS2_MOUSE_L_MULTIPLIER;
  } else {
    mouse_report->x *= PS2_MOUSE_R_MULTIPLIER;
  }
  // Moving down.
  if (mouse_report->y > 0) {
    mouse_report->y *= PS2_MOUSE_D_MULTIPLIER;
  } else {
    mouse_report->y *= PS2_MOUSE_U_MULTIPLIER;
  }
}

/*
void keyboard_pre_init_user(void) {
  //ps2_mouse_set_sample_rate(PS2_MOUSE_10_SAMPLES_SEC);
  //ps2_mouse_set_resolution(PS2_MOUSE_8_COUNT_MM);
  ps2_mouse_set_remote_mode();
}
*/
#endif

uint8_t last_layer = 255;
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    if (last_layer != current_layer) {
        last_layer = current_layer;
        switch (get_highest_layer(state)) {
            case _NUMBERS:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_WHITE);
#endif
#ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_SOFT_BUMP_100);
#endif
                break;
            case _FUNC:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_RED);
#endif
#ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_STRONG_CLICK_1_100);//DRV2605L_EFFECT_SHORT_DOUBLE_SHARP_TICK_1_100);
#endif
                break;
            case _105_KEYS:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_GREEN);
#endif
#ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
#endif
                break;
            case _GAMING:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_GREEN);
                rgblight_sethsv(HSV_CYAN);
#endif
#ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_SOFT_BUMP_100);
#endif
                break;
            case _QWERTY:
#ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_PULSING_SHARP_1_100);
#endif
            case _QWERTY2:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_ORANGE);
#endif
                break;
            case _GAMING_SHORT:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_BLUE);
#endif
                break;
            case _GAMING2:
            case _GAMING_SHORT2:
#ifdef HSV_WHITE
                rgblight_sethsv(HSV_MAGENTA);
#endif
                break;
            default: // for any other layers, or the default layer
#ifdef HSV_WHITE
                rgblight_sethsv (HSV_OFF);
#endif
                break;
        }
    }
  return state;
}



// ********************************************************************************
//
// This is close, but the mouse and thumb buttons are still off
//
// **You MUST LOAD the layout.vil file for a correct layout**
// Also TAP DANCE is not transfered
//
// ********************************************************************************
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(

         LT(2, KC_GRAVE),                   KC_Q,                   KC_W,                   KC_F,                   KC_P,                   KC_B,                    KC_J,                   KC_L,                   KC_U,                   KC_Y,            KC_RBRACKET,                KC_RALT,
     LCTL_T(KC_ESCAPE),                   KC_A,                   KC_R,                   KC_S,                   KC_T,                   KC_G,                    KC_M,                   KC_N,                   KC_E,                   KC_I,                   KC_O,       RCTL_T(KC_ENTER),
LALT_T(KC_APPLICATION),                   KC_Z,                   KC_X,                   KC_C,                   KC_D,                   KC_V,                    KC_K,                   KC_H,               KC_COMMA,                 KC_DOT,               KC_SLASH,         RSFT(KC_MINUS),
               KC_BTN1,                KC_BTN2,                KC_LSHIFT,         LT(1, KC_SPACE),              KC_BSPACE,               MO(1),                   MO(3),                   MO(2),               KC_BTN3,                KC_BTN2,                KC_BTN1,                KC_BTN2

  ),

  [1] = LAYOUT(

            LSFT(KC_5),             LSFT(KC_1),             RALT(KC_7),             LSFT(KC_2),             RALT(KC_0),  LSFT_T(KC_NONUS_HASH),          RSFT(KC_EQUAL),                   KC_7,                   KC_8,                   KC_9,            KC_RBRACKET,              KC_BSPACE,
               KC_TRNS,        KC_NONUS_BSLASH,             RSFT(KC_8),         RALT(KC_MINUS),             RSFT(KC_9),  RSFT(KC_NONUS_BSLASH),       RSFT(KC_RBRACKET),                   KC_4,                   KC_5,                   KC_6,             RSFT(KC_0),                KC_TRNS,
            LSFT(KC_6),             LSFT(KC_4),             RALT(KC_8),  RALT(KC_NONUS_BSLASH),             RALT(KC_9),          KC_NONUS_HASH,              RSFT(KC_7),                   KC_1,                   KC_2,                   KC_3,               KC_SLASH,               KC_COMMA,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                   KC_0,                 KC_DOT

  ),

  [2] = LAYOUT(

                 KC_NO,                KC_PGUP,                KC_WH_U,                  KC_NO,                KC_VOLU,                KC_MPLY,                KC_QUOTE,                  KC_F7,                  KC_F8,                  KC_F9,                 KC_F12,             KC_PSCREEN,
                 KC_NO,              KC_PGDOWN,                KC_WH_D,                  KC_NO,                KC_VOLD,                KC_MNXT,               KC_SCOLON,                  KC_F4,                  KC_F5,                  KC_F6,                 KC_F11,               KC_PAUSE,
                 TO(4),                  TO(6),                  TO(8),                KC_CALC,                KC_MUTE,                KC_MPRV,             KC_LBRACKET,                  KC_F1,                  KC_F2,                  KC_F3,                 KC_F10,          KC_SCROLLLOCK,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,              KC_DELETE,                KC_TRNS,                KC_TRNS,                KC_TRNS

  ),

  [3] = LAYOUT(

                 KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                   KC_NO,                KC_HOME,                  KC_UP,                 KC_END,                KC_PGUP,                KC_WH_U,
                 KC_NO,                  KC_NO,                   KC_D,                   KC_E,                   KC_F,                  KC_NO,                   KC_NO,                KC_LEFT,                KC_DOWN,               KC_RIGHT,              KC_PGDOWN,                KC_WH_D,
                 KC_NO,                  KC_NO,                   KC_A,                   KC_B,                   KC_C,                  KC_NO,                   KC_NO,                  KC_NO,              KC_INSERT,                  KC_NO,                  KC_NO,                  KC_NO,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,              KC_BSPACE,                KC_TRNS,                KC_TRNS,                KC_TRNS

  ),

  [4] = LAYOUT(

              KC_GRAVE,                 KC_TAB,                   KC_Q,                   KC_W,                   KC_E,                  TD(0),                   KC_NO,                  KC_F7,                  KC_F8,                  KC_F9,                 KC_F12,                KC_LALT,
                 TD(3),              KC_LSHIFT,                   KC_A,                   KC_S,                   KC_D,                  TD(1),                   KC_NO,                  KC_F4,                  KC_F5,                  KC_F6,                 KC_F11,                 KC_TAB,
                  KC_H,               KC_LCTRL,                  TD(4),                  TD(5),                  TD(6),                  TD(2),                   KC_NO,                  KC_F1,                  KC_F2,                  KC_F3,                 KC_F10,             LALT(KC_M),
                  KC_K,                   KC_J,                  MO(6),               KC_SPACE,                   KC_F,                   KC_G,                 KC_TRNS,                KC_TRNS,                  TO(0),                  KC_NO,                  KC_NO,                KC_MPLY

  ),

  [5] = LAYOUT(

                 KC_NO,                   KC_U,                KC_TRNS,                KC_TRNS,                KC_TRNS,               KC_COMMA,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
               KC_TRNS,              KC_ESCAPE,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_DOT,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
                 KC_NO,                  TD(7),                  TD(8),                  TD(9),                 TD(10),               KC_SLASH,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                   KC_X,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO

  ),

  [6] = LAYOUT(

              KC_GRAVE,                   KC_Q,                   KC_W,                   KC_E,                   KC_R,                   KC_T,                    KC_Z,                   KC_U,                   KC_J,                   KC_O,                   KC_P,                KC_RALT,
     LCTL_T(KC_ESCAPE),                   KC_A,                   KC_S,                   KC_D,                   KC_F,                   KC_G,                    KC_H,                   KC_J,                   KC_K,                   KC_L,              KC_SCOLON,       RCTL_T(KC_ENTER),
LALT_T(KC_APPLICATION),                   KC_Y,                   KC_X,                   KC_C,                   KC_V,                   KC_B,                    KC_N,                   KC_M,               KC_COMMA,                 KC_DOT,               KC_SLASH,         RSFT(KC_MINUS),
               KC_BTN2,                KC_BTN3,                KC_LGUI,                KC_LALT,              KC_LSHIFT,               KC_SPACE,                 KC_TRNS,                KC_TRNS,              KC_BSPACE,                  MO(1),                  MO(7),                  TO(0)

  ),

  [7] = LAYOUT(

                 KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
                 KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
                 KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,
                 KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                   KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO

  ),

  [8] = LAYOUT(

                  KC_7,                 KC_TAB,                   KC_Q,                   KC_W,                   KC_E,                   KC_M,                 KC_TRNS,                  KC_F7,                  KC_F8,                  KC_F9,                 KC_F12,                KC_LALT,
                  KC_8,              KC_LSHIFT,                   KC_A,                   KC_S,                   KC_D,                   KC_H,                 KC_TRNS,                  KC_F4,                  KC_F5,                  KC_F6,                 KC_F11,                 KC_TAB,
                  KC_9,               KC_LCTRL,                   KC_1,                   KC_2,                   KC_C,                   KC_V,                 KC_TRNS,                  KC_F1,                  KC_F2,                  KC_F3,                 KC_F10,                KC_TRNS,
                  KC_K,                   KC_J,                  MO(9),               KC_SPACE,                   KC_F,                   KC_G,                 KC_TRNS,                KC_TRNS,                  TO(0),                KC_TRNS,                KC_TRNS,                KC_MPLY

  ),

  [9] = LAYOUT(

                  KC_0,                KC_TRNS,                   KC_X,                KC_TRNS,                   KC_V,                  KC_F1,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
              KC_MINUS,              KC_ESCAPE,                KC_TRNS,                KC_TRNS,                KC_TRNS,                   KC_N,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
              KC_EQUAL,                   KC_P,                   KC_4,                   KC_5,                   KC_6,                   KC_B,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS

  ),

  [10] = LAYOUT(

               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS

  ),

  [11] = LAYOUT(

               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
               KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                 KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS

  )
};
