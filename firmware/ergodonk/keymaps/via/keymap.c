// Copyright 2022 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

/* Defines macros for use with the configurators "Any" key. (These are non-standard macros). */
/* Move active application right half. */
#define KC_CSGRA LCTL(LSFT(LGUI(KC_RGHT)))
/* Move active application to left half. */
#define KC_CSGLA LCTL(LSFT(LGUI(KC_LEFT)))
/* Maximize active application. */
#define KC_MAXI LCTL(LSFT(LGUI(KC_UP)))
/* Minimize active application. */
#define KC_MINI LCTL(LSFT(LGUI(KC_DOWN)))

/* Rotary encoder variables used to hold down Command (GUI) key while cycling through open programs. */
bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;  

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    CMD_TAB_CW,
    CMD_TAB_CCW,
};

/**
 * Tap Dance declarations
 */
enum tapdances {
    _TD_FIVE_ENTER,
};

/* Tapdance */
#define TD_ENT5 TD(_TD_FIVE_ENTER)

/**
 * Tap Dance definitions
 *
 * NOTE - if your not using tapdance, comment out:
 * TAP_DANCE_ENABLE = yes in rules.mk
 * define TAPPING_TERM 175 in config.h
 * else you'll get a compile error.
 *
 * To use this in the configurator, enter the name 'TD_ENT5' in the "Any" key.
 */
qk_tap_dance_action_t tap_dance_actions[] = {
    /* Tap once for 5, twice for Enter. */
    [_TD_FIVE_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ergodonk(
                  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                          KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11  , KC_F12  , KC_DEL ,
		          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , TD_ENT5, KC_VOLU,        KC_PSCR, KC_INS , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, 
		          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,        KC_SLCK, KC_DEL , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, 
		          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,        KC_NO  , KC_5   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT, 
		          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MINI, KC_HOME,        KC_PGUP, KC_MAXI, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_LSFT,
	    KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                          KC_PGDN, KC_LSFT, KC_ENT , KC_UP  , KC_DOWN, KC_NO  , KC_LGUI, KC_LCTL,        
		                                     QK_GESC,                   KC_ENT   ,                        KC_6   ,                   KC_LALT
    ),
    [_LOWER] = LAYOUT_ergodonk(
                  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , TD_ENT5, KC_VOLU,                          KC_PSCR, KC_INS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,                          KC_SLCK, KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,                          KC_NO, KC_5, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_HOME,                          KC_PGUP, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
	    KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                   KC_PGDN, KC_LSFT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_LCTL,        
		                                     QK_GESC,                   KC_ENT   ,                                   KC_6, KC_LALT
    ),
    [_RAISE] = LAYOUT_ergodonk(
                  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , TD_ENT5, KC_VOLU,                          KC_PSCR, KC_INS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,                          KC_SLCK, KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,                          KC_NO, KC_5, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_HOME,                          KC_PGUP, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
	    KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                   KC_PGDN, KC_LSFT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_LCTL,        
		                                     QK_GESC,                   KC_ENT   ,                                   KC_6, KC_LALT
    ),
    [_ADJUST] = LAYOUT_ergodonk(
                  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , TD_ENT5, KC_VOLU,                          KC_PSCR, KC_INS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,                          KC_SLCK, KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,                          KC_NO, KC_5, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_HOME,                          KC_PGUP, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
	    KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                   KC_PGDN, KC_LSFT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_LCTL,        
		                                     QK_GESC,                   KC_ENT   ,                                   KC_6, KC_LALT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case CMD_TAB_CW:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CMD_TAB_CCW:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

/**
 * Rotary Encoder.
 *
 * This can't be programmed through configurator. You must do it here.
 *
 * This uses the amazing "Encoder map" feature which replicates the normal keyswitch layer handling functionality, but with encoders.
 * https://docs.qmk.fm/#/feature_encoders?id=encoder-map 
 * 
 * Uses a variant of the Super-alt-tab macro to switch between open applications on a mac. (Command-tab)
 * https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
 */
#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        /* Left Hand */                                                     /* Right Hand */
        /* Switch between tabs. (Control + Tab). */                         /* Switch between open apps on Mac. (Command + Tab + timer logic) */
        [_QWERTY] =  { ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB)),             ENCODER_CCW_CW(CMD_TAB_CCW, CMD_TAB_CW)  },
        /* Scrolls left & right. (Shift + Mouse Wheel Up). */               /* Scrolls up and down. (Page Down & Page Up - mouse wheel scroll incraments are too small) */
        [_LOWER] =  { ENCODER_CCW_CW(S(KC_MS_WH_UP), S(KC_MS_WH_DOWN)),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
        /* Selects adjacent words. (Command + Shift + Right Arrow). */      /* Jumps to end/start of line. Hold shift to select. (Gui + arrow). */
        [_RAISE] =  { ENCODER_CCW_CW(C(S(KC_LEFT)), C(S(KC_RGHT))),         ENCODER_CCW_CW(G(KC_LEFT), G(KC_RGHT))  },
        /* Scroll through RGB Modes */                                      /* Right & left arrow */
        [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),                    ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    };
#endif


/**
 * Helper function for rotary encoder.
 *
 * If the timer has elapsed, the Command/Gui tab will be released.
 * You can adjust the milliseconds to speed up the CMD key release.
 */
void matrix_scan_user(void) {
    if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 900) {
            unregister_code(KC_LGUI);
            is_cmd_tab_active = false;
        }
    }
}

