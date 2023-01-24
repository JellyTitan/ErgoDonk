// Copyright 2022 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

// VID and PID moved to .json
// #define VENDOR_ID 0x4A54 // “JT” = JellyTitan.
// #define PRODUCT_ID 0x0001 // Sequential numbering system.
// #define MANUFACTURER    JellyTitan
#define PRODUCT         Ergodonk

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 14
#define MATRIX_COLS 10
#define MATRIX_COL_PINS   { B8, B7, B10, B5, B4, A0, C15, C14, C13, NO_PIN} 
#define MATRIX_ROW_PINS  { B12, B13, B14, B15, A8, A15, B3 }
// RH has one more col then LH.
#define MATRIX_COL_PINS_RIGHT { C13, C14, C15, A0, B4, B5, B10, B7, B8, B9 }
#define MATRIX_ROW_PINS_RIGHT { B12, B13, B14, B15, A8, A15, B3 }
// #define UNUSED_PINS { A1, A2, A3, A9, A10, A11, A12}

// @todo - what does this do? It was in zv48 . . .
// #define MATRIX_IO_DELAY 5
#define SPLIT_USB_DETECT
#define SPLIT_HAND_PIN B0  // high = left, low = right
// @todo - this is a better way to determine handedness:
// #define SPLIT_HAND_MATRIX_GRID D0, F1

#define SOFT_SERIAL_PIN B6

// If you’re having issues with serial communication, you can change this value, 
// as it controls the communication speed for serial. 
// The default is 1, and the possible values are:
// 0: about 189kbps (Experimental only)
// 1: about 137kbps (default)
// 2: about 75kbps
// 3: about 39kbps
// 4: about 26kbps
// 5: about 20kbps
#define SELECT_SOFT_SERIAL_SPEED 2

// This sets the maximum number of failed communication attempts (one per scan cycle) 
// from the master part before it assumes that no slave part is connected. 
// This makes it possible to use a master part without the slave part connected.
// Set to 0 to disable the disconnection check altogether.
#define SPLIT_MAX_CONNECTION_ERRORS 0

/* Set 0 if debouncing isn't needed  - cribbed from zv48*/
#define DEBOUNCE 5


#define ENCODERS_PAD_A { A13 }
#define ENCODERS_PAD_B { A14 }

#define SOLENOID_PIN B1
#define SOLENOID_ACTIVE true
#define SOLENOID_DEFAULT_DWELL 12 // default is 12.
#define SOLENOID_DWELL_STEP_SIZE 2         //      |The step size to use when `HPT_DWL*` keycodes are sent.
#define SOLENOID_MIN_DWELL 4 // 4 is default
#define SOLENOID_MAX_DWELL 100 // 100 is default

// Prevents thumper on mods like shift/Ctrl/Alt
// #define NO_HAPTIC_MOD

// Bootmagic lite
// LH Hold ESC on boot to enter bootloader
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1
// RH Hold DEL on boot to enter bootloader 
// @todo this is only needed when using SPLIT_HAND_PIN or EE_HANDS
// https://docs.qmk.fm/#/feature_bootmagic?id=split-keyboards
#define BOOTMAGIC_LITE_ROW_RIGHT 7
#define BOOTMAGIC_LITE_COLUMN_RIGHT 7

/* If you type too fast, it confuses the Mod key combos. This resolves it: */
#define IGNORE_MOD_TAP_INTERRUPT
/* Set tapdance speed */
#define TAPPING_TERM 210

/* Allows for the setting of constant mouse speed levels. */
/* Delay between pressing a movement key and cursor movement */
#define MOUSEKEY_DELAY 10
/* Time between cursor movements in milliseconds */
#define MOUSEKEY_INTERVAL 16
/* Step size */
#define MOUSEKEY_MOVE_DELTA 8
/* Maximum cursor speed at which acceleration stops */
#define MOUSEKEY_MAX_SPEED 2
/* Time until maximum cursor speed is reached */
#define MOUSEKEY_TIME_TO_MAX 40
/* Maximum number of scroll steps per scroll action */
#define MOUSEKEY_WHEEL_MAX_SPEED 42
/* Time until maximum scroll speed is reached */
#define MOUSEKEY_WHEEL_TIME_TO_MAX 15


// #define XXX KC_NO
#define XXX KC_NO

// @todo tweak the thumb clusters to look more like the hardware
#define LAYOUT_ergodonk( \
       L01, L02, L03, L04, L05, L06, L07,                    R01, R02, R03, R04, R05, R06, R07, \
       L11, L12, L13, L14, L15, L16, L17, L18,          R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, \
       L21, L22, L23, L24, L25, L26, L27, L28,          R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, \
       L31, L32, L33, L34, L35, L36, L37, L38,          R30, R31, R32, R33, R34, R35, R36, R37, R38, \
       L41, L42, L43, L44, L45, L46, L47, L48,          R40, R41, R42, R43, R44, R45, R46,      R48, \
  L50, L51, L52, L53, L54,      L56, L57, L58,          R50, R51, R52,      R54, R55, R56, R57, R58, \
                           L65,           L68,          R60,           R63 \
) \
{ \
    { XXX, L01, L02, L03, L04, L05, L06, L07, XXX, XXX }, \
    { XXX, L11, L12, L13, L14, L15, L16, L17, L18, XXX }, \
    { XXX, L21, L22, L23, L24, L25, L26, L27, L28, XXX }, \
    { XXX, L31, L32, L33, L34, L35, L36, L37, L38, XXX }, \
    { XXX, L41, L42, L43, L44, L45, L46, L47, L48, XXX }, \
    { L50, L51, L52, L53, L54, XXX, L56, L57, L58, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, L65, XXX, XXX, L68, XXX }, \
\
    { XXX, R01, R02, R03, R04, R05, R06, R07, XXX, XXX }, \
    { R10, R11, R12, R13, R14, R15, R16, R17, R18, R19 }, \
    { R20, R21, R22, R23, R24, R25, R26, R27, R28, R29 }, \
    { R30, R31, R32, R33, R34, R35, R36, R37, R38, XXX }, \
    { R40, R41, R42, R43, R44, R45, R46, XXX, R48, XXX }, \
    { R50, R51, R52, XXX, R54, R55, R56, R57, R58, XXX }, \
    { R60, XXX, XXX, R63, XXX, XXX, XXX, XXX, XXX, XXX }  \
}
