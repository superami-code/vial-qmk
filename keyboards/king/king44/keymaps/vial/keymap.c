// Copyright 2025 Jacob King (@superami-code)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "./keymap.h"

#include "../../config/pointing.h"
#include "../../config/rgblight.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif

#if PS2_MOUSE_ADJUST
#include "ps2_mouse.h"

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

#if (defined HSV_WHITE) || (defined HAPTIC_ENABLE)
uint8_t last_layer = 255;

void layer_effect_haptic(const uint8_t haptic) {
#ifdef HAPTIC_ENABLE
    drv2605l_pulse(haptic);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
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

    uint8_t current_layer = get_highest_layer(state);
    if (last_layer != current_layer) {
        last_layer = current_layer;
        switch (get_highest_layer(state)) {
            case _NUMBERS:
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            case _FUNC:
                layer_effect_haptic(DRV2605L_EFFECT_STRONG_CLICK_1_100);//DRV2605L_EFFECT_SHORT_DOUBLE_SHARP_TICK_1_100);
                break;

            case _105_KEYS:
                layer_effect_haptic(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
                break;

            case _QWERTY:
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _QWERTY2:
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            case _GAMING:
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _GAMING_SHORT:
                layer_effect_haptic(DRV2605L_EFFECT_PULSING_SHARP_1_100);
                break;

            case _GAMING2:
            case _GAMING_SHORT2:
                layer_effect_haptic(DRV2605L_EFFECT_SOFT_BUMP_100);
                break;

            default: // for any other layers, or the default layer
                break;
        }
    }

    return state;
}
#endif

void keyboard_post_init_user(void){
    rgblight_layers = my_rgb_layers;
}



