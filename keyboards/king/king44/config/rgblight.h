#pragma once

#ifdef RGBLIGHT_LAYERS
/*  RGBLIGHT LAYOUT
 *
 *  19 18 13 12  7  6          28 29 34 35 40 41
 *  20 17 14 11  8  5          27 30 33 36 39 42
 *  21 16 15 10  9  4          26 31 32 37 38 43
 *            3  2  1  0    22 23 24 25
 */

const rgblight_segment_t PROGMEM _alpha_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,43, HSV_OFF }
);

const rgblight_segment_t PROGMEM _numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // white => numbers, teal => symbols
    {  3,  1, HSV_RED },
    {  4, 16, HSV_TEAL },
    { 19,  1, HSV_TEAL },
    { 21,  1, HSV_TEAL },

    { 24,  2, HSV_WHITE },
    { 29,  9, HSV_WHITE },
    { 26,  3, HSV_TEAL },
    { 38,  3, HSV_TEAL },
    { 41,  1, HSV_RED },
    { 43,  1, HSV_TEAL }
);

const rgblight_segment_t PROGMEM _func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // Safe buttons
    {  4,  7, HSV_YELLOW },
    { 13,  2, HSV_YELLOW },
    { 18,  2, HSV_YELLOW },

    // Mode switch
    { 21,  1, HSV_PURPLE },
    { 16,  1, HSV_PURPLE },
    { 15,  1, HSV_PURPLE },

    { 26,  3, HSV_GREEN },
    { 22,  1, HSV_RED },
    { 29, 12, HSV_RED },
    { 41,  3, HSV_YELLOW }
);

const rgblight_segment_t PROGMEM _105_keys_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  4,  2, HSV_WHITE },
    {  8,  4, HSV_WHITE },
    { 13,  2, HSV_GREEN },
    { 17,  2, HSV_GREEN },

    { 27,  2, HSV_GREEN },
    { 29,  2, HSV_YELLOW },
    { 32,  5, HSV_YELLOW },
    { 39,  2, HSV_GREEN }
);

const rgblight_segment_t PROGMEM _gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // WASD
    {  8,1, HSV_PURPLE },
    { 11,2, HSV_PURPLE },
    { 14,1, HSV_PURPLE },

    // Leaning, crouch, lay
    {  7, 1, HSV_CYAN },
    { 13, 1, HSV_CYAN },
    { 16, 1, HSV_CYAN },
    { 21, 1, HSV_CYAN },

    // Boosts
    { 4, 1, HSV_ORANGE },

    // Heals
    { 5, 1, HSV_GREEN },

    // Gernades and Weapons
    {  9, 1, HSV_RED },
    { 15, 1, HSV_RED },

    // Other
    { 22, 1, HSV_PINK },
    { 25, 1, HSV_GREEN },
    { 41, 2, HSV_GOLD }
);

const rgblight_segment_t PROGMEM _gaming2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,43, HSV_MAGENTA }
);

const rgblight_segment_t PROGMEM _qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,43, HSV_ORANGE }
);

const rgblight_segment_t PROGMEM _qwerty2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,43, HSV_GOLD }
);

const rgblight_segment_t PROGMEM _gaming_short_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  8,1, HSV_PURPLE },
    { 11,2, HSV_PURPLE },
    { 14,1, HSV_PURPLE },

    // Leaning, crouch, lay
    {  7, 1, HSV_CYAN },
    { 13, 1, HSV_CYAN },
    { 16, 1, HSV_CYAN },
    { 21, 1, HSV_CYAN },

    // Boosts
    { 4, 1, HSV_ORANGE },

    // Heals
    { 5, 1, HSV_GREEN },

    // Gernades and Weapons
    {  9, 1, HSV_RED },
    { 15, 1, HSV_RED },

    // Other
    { 22, 1, HSV_PINK },
    { 25, 1, HSV_GREEN },
    { 41, 2, HSV_GOLD },

    // marker
    { 32, 3, HSV_PURPLE }
);

const rgblight_segment_t PROGMEM _gaming_short2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,43, HSV_MAGENTA }
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    _alpha_layer,
    _numbers_layer,
    _func_layer,
    _105_keys_layer,
    _gaming_layer,
    _gaming2_layer,
    _qwerty_layer,
    _qwerty2_layer,
    _gaming_short_layer,
    _gaming_short2_layer
);

#endif
