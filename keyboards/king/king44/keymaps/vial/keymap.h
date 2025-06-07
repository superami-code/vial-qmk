#pragma once

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
    _MOUSE
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
