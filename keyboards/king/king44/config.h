// Copyright 202  King (@SuperAmi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "./config/vial.h"
#include "./config/matrix.h"
#include "./config/split.h"
#include "./config/pointing.h"
#include "./config/haptic.h"

#define DYNAMIC_KEYMAP_LAYER_COUNT 12
#define DEBOUNCE 5

//#define OLED_TIMEOUT 0
//#define NO_SUSPEND_POWER_DOWN
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 3

#define LUNA_ANIMATE

#define RGB_DIM
#include "./config/rgb.h"

#define DRV2605L_GREETING       DRV2605L_EFFECT_750_MS_ALERT_100
#define DRV2605L_DEFAULT_MODE   DRV2605L_EFFECT_SHARP_TICK_1_100
