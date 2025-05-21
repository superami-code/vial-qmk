#include QMK_KEYBOARD_H

enum layers {
    BASE,
    GAME,
    QWER,
    NMPD,
    FUNC,
    MOUS
};

#define LT_NMPD LT(NMPD, KC_EQL)
#define LT_FUNC LT(FUNC, KC_L)
#define LT_MOUS LT(MOUS, KC_SCLN)

#define RGB_MF RGB_MODE_FORWARD
#define RGB_MR RGB_MODE_REVERSE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_INS,                         TG(NMPD), KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_BSLS,
    KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Z,    KC_6,                            KC_NUBS, KC_Y,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    TT(FUNC),                       TT(FUNC), KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, LT_MOUS, KC_Q,    KC_J,    KC_K,    KC_X,                                              KC_B,    KC_M,    KC_W,    KC_V,    KC_F,    LT_NMPD,
    KC_LCTL, KC_QUOT, KC_NUBS, KC_LGUI, KC_LALT,          KC_F4,   KC_F10,        KC_LEFT, KC_RGHT,          KC_RALT, KC_UP,   KC_DOWN, KC_APP,  KC_RCTL,
                                                 KC_SPC,  KC_DEL,  KC_HOME,       KC_PGUP, KC_ENT,  KC_BSPC,
                                                                   KC_END,        KC_PGDN
  ),
  [GAME] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_N,                            _______, _______, _______, _______, _______, _______, _______,
    _______, KC_6,    KC_Q,    KC_W,    KC_E,    KC_9,    KC_P,                            _______, _______, _______, _______, _______, _______, _______,
    _______, KC_7,    KC_A,    KC_S,    KC_D,    KC_0,    LT_FUNC,                         _______, _______, _______, _______, _______, _______, _______,
    _______, KC_8,    KC_Z,    KC_X,    KC_C,    KC_V,                                              _______, _______, _______, _______, _______, _______,
    _______, KC_H,    KC_J,    KC_K,    _______,          KC_M,    KC_Y,          _______, _______,          _______, _______, _______, KC_RGUI, _______,
                                                 _______, _______, KC_T,          _______, _______, _______,
                                                                   KC_G,          _______
  ),
  [QWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_6,                            _______, _______, _______, _______, _______, KC_MINS, KC_EQL,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                         KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                         _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT,
    _______, _______, _______, _______, _______,          _______, _______,       _______, _______,          _______, _______, _______, _______, _______,
                                                 _______, _______, _______,       _______, _______, _______,
                                                                   _______,       _______
  ),
  [NMPD] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                         _______,  KC_NUM, KC_CALC, KC_PSLS, KC_PAST, KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, _______,
    _______, _______, _______, _______, _______, _______,                                           _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
    _______, _______, _______, _______, _______,          _______, _______,       _______, _______,          KC_P0,   _______, _______, _______, _______,
                                                 _______, _______, _______,       _______, _______, _______,
                                                                   _______,       _______
  ),
  [FUNC] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                         _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RGB_HUI, RGB_SAI, KC_MSTP, KC_VOLU, KC_MPLY, RGB_VAI, KC_F6,                           _______, RGB_VAI, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_SYSTEM_SLEEP,
    RGB_HUD, RGB_SAD, KC_MPRV, KC_VOLD, KC_MNXT, RGB_VAD, TT(FUNC),                        _______, RGB_VAD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_SYSTEM_WAKE,
    _______, _______,RGB_M_SN, KC_MUTE, RGB_MF,  RGB_TOG,                                           RGB_TOG, RGB_MF,  _______,RGB_M_SN, _______, KC_SYSTEM_POWER,
    _______, EE_CLR,  RGB_M_P, RGB_M_TW,RGB_MR,           KC_PSCR, _______,       _______, _______,          RGB_MR,  RGB_M_TW, RGB_M_P, EE_CLR, _______,
                                                 _______,TG(GAME),TG(NMPD),      TG(NMPD),TG(GAME), _______,
                                                                  TG(QWER),      TG(QWER)
  ),
  [MOUS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_U, _______, KC_WH_U, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______, _______,       _______, _______,          _______, _______, _______, _______, _______,
                                                 KC_BTN1, KC_BTN2, _______,       _______, _______, _______,
                                                                   KC_BTN3,       _______
  )
};

//https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
/*
Tips
  [GAME] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______, _______,       _______, _______,          _______, _______, _______, _______, _______,
                                                 _______, _______, _______,       _______, _______, _______,
                                                                   _______,       _______
   )
   */

#ifdef RAW_ENABLE
#include "raw_hid.h"
#include "qmk_rc.h"

#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);;
}
#endif // RAW_ENABLE
