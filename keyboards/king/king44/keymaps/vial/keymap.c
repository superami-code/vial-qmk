// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    _ALPHA,   // default
    _NUMBERS, // numbers
    _SPECIAL, // special characters
    _FUNC,
    _MOUSE,
    _GAMING,
    _GAMING2,
    _QWERTY,
    _QWERTY2,
    _GAMING_SHORT,
    _GAMING_SHORT2,
    _EMPTY
};

/*
#define KC_CTL_A  MT(MOD_LCTL, KC_A)     // Tap for A, hold for Control
#define KC_CTL_CL MT(MOD_LCTL, KC_SCLN)  // Tap for colon, hold for Control
#define KC_SFT_Z  MT(MOD_RSFT, KC_Z)     // Tap for Z, hold for Shift
#define KC_SFT_SL MT(MOD_RSFT, KC_SLSH)  // Tap for slash, hold for Shift

#define KC_GUI_ESC MT(MOD_LGUI, KC_ESC)  // Tap for Esc, hold for GUI (Meta, Command, Win)
#define KC_ALT_ENT MT(MOD_LALT, KC_ENT)  // Tap for Enter, hold for Alt (Option)
#define KC_SPE_SPC LT(_SPECIAL, KC_SPC)  // Tap for Space, hold for Special layer
#define KC_NUM_SPC LT(_NUMBERS, KC_SPC)  // Tap for Space, hold for Numbers layer
#define KC_SFT_TAB MT(MOD_RSFT, KC_TAB)  // Tap for Tab, hold for Right Shift
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [1] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [2] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [3] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [4] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [5] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [6] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J),
  [7] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J)
    /*
,
  [4] = LAYOUT(KC_J, KC_J, KC_J, KC_J, KC_J, KC_WH_U, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_WH_D, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_J, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS),
  [5] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_M, KC_J, KC_J, KC_J, KC_J, KC_J, KC_LCTL, KC_A, KC_S, KC_D, KC_7, KC_J, KC_J, KC_J, KC_J, KC_J, KC_LSFT, KC_1, KC_P, KC_C, KC_0, KC_J, KC_J, KC_J, KC_J, RSFT(KC_N), KC_L, KC_SPC, KC_F, TO(0), KC_J, KC_J, KC_TRNS, KC_TRNS, KC_TRNS),
  [6] = LAYOUT(LALT(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_J, KC_J, KC_J, KC_J, KC_J, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_P, KC_J, KC_J, KC_J, KC_J, KC_J, KC_TRNS, KC_J, KC_TRNS, KC_K, KC_TRNS, KC_J, KC_J, KC_J, KC_J, KC_J, KC_TRNS, KC_TRNS, KC_TRNS, KC_J, KC_J, KC_J, KC_TRNS, KC_TRNS, KC_TRNS),
  [7] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), KC_F, KC_G, KC_H, KC_J, RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), LT(8,KC_ESC), KC_DEL, KC_SPC, KC_ENT, KC_BSPC, LT(8,KC_DEL), KC_TRNS, KC_TRNS, KC_TRNS),
  [8] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, KC_RCTL, KC_TRNS, OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  */
};

#ifdef POINTING_DEVICE_TRACKPOINT_VENDOR
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

layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef HSV_WHITE
    switch (get_highest_layer(state)) {
        case _NUMBERS:
            rgblight_sethsv(HSV_WHITE);
            break;
        case _FUNC:
            rgblight_sethsv(HSV_RED);
            break;
        case _SPECIAL:
            rgblight_sethsv(HSV_GREEN);
            break;
        case _MOUSE:
            rgblight_sethsv(HSV_YELLOW);
            break;
        case _GAMING:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _QWERTY:
        case _QWERTY2:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case _GAMING_SHORT:
            rgblight_sethsv(HSV_PURPLE);
            break;
        case _GAMING2:
        case _GAMING_SHORT2:
            rgblight_sethsv(HSV_RED);
            break;
        default: // for any other layers, or the default layer
            rgblight_sethsv (HSV_OFF);
            break;
    }
    #endif
  return state;
}


