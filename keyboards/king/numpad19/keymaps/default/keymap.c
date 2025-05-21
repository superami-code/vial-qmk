#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_0,              KC_3,   KC_8,   KC_D, \
    RGB_TOG,           KC_4,   KC_9,   KC_E, \
    RGB_MODE_REVERSE,  KC_5,   KC_A,   KC_F, \
    KC_1,              KC_6,   KC_B,   \
    KC_2,              KC_7,   KC_C,  KC_H \
  )
};
