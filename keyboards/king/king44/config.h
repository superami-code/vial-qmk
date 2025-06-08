// Copyright 202  King (@SuperAmi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "./config/vial.h"
#include "./config/matrix.h"
#include "./config/split.h"
#include "./config/pointing.h"
#include "./config/haptic.h"

#define DYNAMIC_KEYMAP_LAYER_COUNT 12
#define DEBOUNCE 5  // default is 5

//#define OLED_TIMEOUT 0
//#define NO_SUSPEND_POWER_DOWN
//#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 3

// LUNA is the littly kitty that will run for you.
// disabling this will keep luna from running, but might slightly improve performance.
// LUNA is not on any of the gaming layers, so it's only relevant for standard typing
#define LUNA_ANIMATE

#define DRV2605L_GREETING       DRV2605L_EFFECT_750_MS_ALERT_100
#define DRV2605L_DEFAULT_MODE   DRV2605L_EFFECT_SHARP_TICK_1_100

//#define RGBLIGHT_LAYERS
#ifdef RGBLIGHT_LAYERS
#error Why is this on, it is too slow
#define RGBLIGHT_MAX_LAYERS 10
#endif
