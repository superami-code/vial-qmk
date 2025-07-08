/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more detaiqmk reset to bootloader key codels.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum king_adept_keycodes{
    SNIPER = DRAG_SCROLL + 1, // This key uses first DPI level + MOUSE2
    SHOOTER                   // Activates secont DPI level + MOUSE1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( LT(1, KC_BTN2), TD(0), LT(2, KC_BTN5), DRAG_SCROLL, KC_BTN1, KC_BTN3 ),
    [1] = LAYOUT( KC_TRNS, LCTL(KC_C), LCTL(KC_V), TD(1), LCTL(KC_A), LCTL(KC_X) ),
    [2] = LAYOUT( KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_W), KC_TRNS ),
    [3] = LAYOUT( KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ),
    [4] = LAYOUT( KC_I, TD(31), KC_R, DRAG_SCROLL, SHOOTER, SNIPER ),
    [5] = LAYOUT( TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ),
    [6] = LAYOUT( KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ),
    [7] = LAYOUT( QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS )
};

#define TAP_TAPPING_TERM 200
void install_tap_dance_entries(void) {
    vial_tap_dance_entry_t td_0 = {
        KC_BTN4,
        KC_NO,
        DPI_CONFIG,
        KC_NO,
        TAP_TAPPING_TERM
    };
    vial_tap_dance_entry_t td_1 = {
        TO(4),
        KC_NO,
        OSL(7),
        KC_NO,
        TAP_TAPPING_TERM
    };
    vial_tap_dance_entry_t td_31 = {
        KC_BSPC,
        MO(5),
        KC_NO,
        KC_NO,
        TAP_TAPPING_TERM
    };
    dynamic_keymap_set_tap_dance(0, &td_0);
    dynamic_keymap_set_tap_dance(1, &td_1);
    dynamic_keymap_set_tap_dance(31, &td_31);
}

void keyboard_post_init_user(void) {
    install_tap_dance_entries();
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
#endif

uint16_t king_dpi_array[] = PLOOPY_DPI_OPTIONS;
bool sniper = false;
bool shooter = false;
uint8_t last_dpi = 2;
/* SHOOTER and SNIPER buttons act like MOUSE2 and MOUSE1, but they also auto adjust the DPI for more accuracy */
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint8_t dpi;
    uint16_t button;

    if (keycode == SNIPER) {
        sniper = record->event.pressed;
        button = KC_BTN2;
    } else if (keycode == SHOOTER) {
        shooter = record->event.pressed;
        button = KC_BTN1;
    } else {
        return true;
    }

    // SNIPER takes precence on the DPI
    dpi = sniper ? 0 : shooter ? 1 : 2;
    if (dpi != last_dpi) {
        pointing_device_set_cpi(king_dpi_array[dpi]);
        last_dpi = dpi;
    }
    if (record->event.pressed) {
        register_code16(button);
    } else {
        unregister_code16(button);
    }
    return false;
}
