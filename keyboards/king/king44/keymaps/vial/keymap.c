// Copyright 2025 Jacob King (@superami-code)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "./keymap.h"

#include "../../config/pointing.h"
#include "../../config/rgblight.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif

#if (defined PS2_MOUSE_SLOW_SCROLL || PS2_MOUSE_ADJUST)
#include "ps2_mouse.h"

bool slow_scroll = false;
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_BTN4) {
        slow_scroll = record->event.pressed;
    }
    return true;
}

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
#if PS2_MOUSE_ADJUST
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
#endif
#ifdef PS2_MOUSE_SLOW_SCROLL
    // If the middle button is down, then reduce X/Y movement
    if (slow_scroll) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report->x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report->y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report->h = (int8_t)scroll_accumulated_h;
        mouse_report->v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report->x = 0;
        mouse_report->y = 0;
    }
#endif
}
#endif

#if (defined HSV_WHITE) || (defined HAPTIC_ENABLE)
uint8_t last_layer = 255;

void layer_effect_hsv(uint8_t h, uint8_t s, uint8_t v) {
#ifdef HSV_WHITE
    rgblight_sethsv(h,s,v);
#endif
}

void layer_effect_haptic(const uint8_t haptic) {
#ifdef HAPTIC_ENABLE
    drv2605l_pulse(haptic);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(_ALPHA, layer_state_cmp(state, _ALPHA));
    rgblight_set_layer_state(_GAMING, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(_GAMING2, layer_state_cmp(state, _GAMING2));
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(_QWERTY2, layer_state_cmp(state, _QWERTY2));
    rgblight_set_layer_state(_GAMING_SHORT, layer_state_cmp(state, _GAMING_SHORT));
    rgblight_set_layer_state(_GAMING_SHORT2, layer_state_cmp(state, _GAMING_SHORT2));
    rgblight_set_layer_state(_NUMBERS, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(_FUNC, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(_105_KEYS, layer_state_cmp(state, _105_KEYS));
#endif

    uint8_t current_layer = get_highest_layer(state);
    if (last_layer != current_layer) {
        last_layer = current_layer;
        switch (get_highest_layer(state)) {
            case _NUMBERS:
                layer_effect_hsv(HSV_WHITE);
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            case _FUNC:
                layer_effect_hsv(HSV_RED);
                layer_effect_haptic(DRV2605L_EFFECT_STRONG_CLICK_1_100);//DRV2605L_EFFECT_SHORT_DOUBLE_SHARP_TICK_1_100);
                break;

            case _105_KEYS:
                layer_effect_hsv(HSV_GREEN);
                layer_effect_haptic(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
                break;

            case _QWERTY:
                layer_effect_hsv(HSV_ORANGE);
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _QWERTY2:
                layer_effect_hsv(HSV_GOLD);
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            case _GAMING:
                layer_effect_hsv(HSV_TEAL);
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _GAMING_SHORT:
                layer_effect_hsv(HSV_CHARTREUSE);
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _GAMING2:
            case _GAMING_SHORT2:
                layer_effect_hsv(HSV_MAGENTA);
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            default: // for any other layers, or the default layer
                layer_effect_hsv(HSV_OFF);
                break;
        }
    }

    return state;
}
#endif

void keyboard_post_init_user(void){
#ifdef  RGBLIGHT_LAYERS
#error we should not be here
    rgblight_layers = my_rgb_layers;
#endif
}


