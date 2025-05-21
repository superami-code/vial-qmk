#ifndef ERGOKING_H
#define ERGOKING_H

#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L15, L26,                R22, R13, R04, R05, R06, R07, R08, \
    L10, L11, L12, L13, L14, L25, L36,                R32, R23, R14, R15, R16, R17, R18, \
    L20, L21, L22, L23, L24, L35, L46,                R42, R33, R24, R25, R26, R27, R28, \
    L30, L31, L32, L33, L34, L45,                          R43, R34, R35, R36, R37, R38, \
    L40, L41, L42, L43, L44,      L27, L28,      R20, R21,      R44, R45, R46, R47, R48, \
                             L47, L37, L38,      R30, R31, R41, \
                                       L48,      R40 \
    ) { \
    { L00,   L01,     L02,   L03,     L04, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { L10,   L11,     L12,   L13,     L14, L15,   KC_NO, KC_NO, KC_NO }, \
    { L20,   L21,     L22,   L23,     L24, L25,   L26,   L27,   L28 }, \
    { L30,   L31,     L32,   L33,     L34, L35,   L36,   L37,   L38 }, \
    { L40,   L41,     L42,   L43,     L44, L45,   L46,   L47,   L48 }, \
    { KC_NO, KC_NO,   KC_NO, KC_NO,   R04, R05,   R06,   R07,   R08 }, \
    { KC_NO, KC_NO,   KC_NO, R13,     R14, R15,   R16,   R17,   R18 }, \
    { R20,   R21,     R22,   R23,     R24, R25,   R26,   R27,   R28 }, \
    { R30,   R31,     R32,   R33,     R34, R35,   R36,   R37,   R38 }, \
    { R40,   R41,     R42,   R43,     R44, R45,   R46,   R47,   R48 } \
}

#endif
