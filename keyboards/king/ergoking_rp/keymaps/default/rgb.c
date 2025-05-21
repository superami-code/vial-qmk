#include QMK_KEYBOARD_H
#include "rgb.h"

#define INDICATOR_LEFT 29
#define RIGHT 38
#define INDICATOR_RGHT RIGHT + 29
#define WASD_A 12
#define WASD_WS 16
#define WASD_D 22

#define LEFT_THUMB 32

#define LED_ADJUST 0xC0

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,0,HSV_BLUE - LED_ADJUST}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // WASD
    {WASD_A, 1,HSV_PURPLE - LED_ADJUST},
    {WASD_WS,2,HSV_PURPLE - LED_ADJUST},
    {WASD_D, 1,HSV_PURPLE - LED_ADJUST},

    // Lean
    {WASD_A-1,1, HSV_CYAN - LED_ADJUST},
    {WASD_D-1,1, HSV_CYAN - LED_ADJUST},

    // Weapons
    /*
    {10, 1, HSV_ORANGE - LED_ADJUST},
    {15, 1, HSV_ORANGE - LED_ADJUST},
    {20, 1, HSV_ORANGE - LED_ADJUST},
    {25, 1, HSV_ORANGE - LED_ADJUST},
    */

    // Boosts
    {26, 3, HSV_ORANGE - LED_ADJUST},

    // Heals
    {6, 3, HSV_GREEN - LED_ADJUST},

    // Gernades
    {13, 1, HSV_RED - LED_ADJUST},
    {18, 1, HSV_RED - LED_ADJUST},
    {23, 1, HSV_RED - LED_ADJUST},

    {INDICATOR_RGHT,1,HSV_PURPLE - LED_ADJUST}
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_LEFT, 1, HSV_CYAN - LED_ADJUST},
    {INDICATOR_RGHT, 1, HSV_CYAN - LED_ADJUST},

    {7,  1,HSV_CYAN - LED_ADJUST},
    {11, 2,HSV_CYAN - LED_ADJUST},
    {17, 1,HSV_CYAN - LED_ADJUST}
);
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_LEFT, 1, HSV_GREEN - LED_ADJUST},
    {INDICATOR_RGHT, 1, HSV_GREEN - LED_ADJUST},

    {RIGHT+5,  4, HSV_YELLOW - LED_ADJUST},
    {RIGHT+10, 4, HSV_YELLOW - LED_ADJUST},
    {RIGHT+15, 4, HSV_YELLOW - LED_ADJUST},
    {RIGHT+20, 5, HSV_YELLOW - LED_ADJUST}
);
const rgblight_segment_t PROGMEM func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_LEFT, 1, HSV_RED - LED_ADJUST},
    {INDICATOR_RGHT, 1, HSV_RED - LED_ADJUST},

    // Audio Controls
    {WASD_A,    1, HSV_BLUE - LED_ADJUST},
    {WASD_WS,   1, HSV_GREEN - LED_ADJUST},
    {WASD_WS+1, 1, HSV_ORANGE - LED_ADJUST},
    {WASD_WS+2, 1, HSV_RED - LED_ADJUST},
    {WASD_D,    1, HSV_BLUE - LED_ADJUST},
    {WASD_A-1,  1, HSV_RED - LED_ADJUST},
    {WASD_D-1,  1, HSV_GREEN - LED_ADJUST}
);
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_LEFT, 1, HSV_ORANGE - LED_ADJUST},
    {INDICATOR_RGHT, 1, HSV_ORANGE - LED_ADJUST},

    {WASD_A, 1,HSV_ORANGE - LED_ADJUST},
    {WASD_WS,2,HSV_ORANGE - LED_ADJUST},
    {WASD_D, 1,HSV_ORANGE - LED_ADJUST},

    {WASD_WS+10, 2, HSV_GREEN - LED_ADJUST},
    {LEFT_THUMB, 2, HSV_BLUE - LED_ADJUST},
    {LEFT_THUMB+5, 1, HSV_PURPLE - LED_ADJUST}
);

const rgblight_segment_t PROGMEM numlock[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_RGHT-4,1, HSV_GREEN - LED_ADJUST},

    {RIGHT+5,  4, HSV_GREEN - LED_ADJUST},
    {RIGHT+10, 4, HSV_GREEN - LED_ADJUST},
    {RIGHT+15, 4, HSV_GREEN - LED_ADJUST},
    {RIGHT+20, 5, HSV_GREEN - LED_ADJUST}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    game_layer,
    qwerty_layer,
    numpad_layer,
    func_layer,
    mouse_layer,
    numlock/*,
    rgb_cpus
    */
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
//      rgblight_set_layer_state(0, true);
}

static layer_state_t LAST_STATE = 0;
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(NMLK, layer_state_cmp(LAST_STATE, NMPD) && led_state.num_lock);
    return true;
}

#define NUMLOCK_ON (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))
layer_state_t layer_state_set_user( layer_state_t state ) {
    LAST_STATE = state;

    //uint8_t val = rgblight_get_val();
    // No indicator for base layeer
//    rgblight_set_layer_state(BASE, layer_state_cmp(state, BASE));
    rgblight_set_layer_state(GAME, layer_state_cmp(state, GAME));
    rgblight_set_layer_state(QWER, layer_state_cmp(state, QWER));
    rgblight_set_layer_state(NMPD, layer_state_cmp(state, NMPD));
    rgblight_set_layer_state(FUNC, layer_state_cmp(state, FUNC));
    rgblight_set_layer_state(MOUS, layer_state_cmp(state, MOUS));
    rgblight_set_layer_state(NMLK, layer_state_cmp(state, NMPD) && NUMLOCK_ON);
    // rgblight_set_layer_state(CPUS, true);
    return state;
}
