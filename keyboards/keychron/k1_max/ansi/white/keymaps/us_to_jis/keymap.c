/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
enum jtu_custom_keycodes {
    MY_IME_OFF_LALT,
    JU_2 = SAFE_RANGE,
    JU_6,
    JU_7,
    JU_8,
    JU_9,
    JU_0,
    JU_MINS,
    JU_EQL,
    JU_LBRC,
    JU_RBRC,
    JU_BSLS,
    JU_SCLN,
    JU_QUOT,
    JU_GRV,
    JTU_SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_87(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_SIRI,  BL_STEP,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_87(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  BL_TOGG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_87(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_CTANA, BL_STEP,
        JU_GRV,   KC_1,     JU_2,     KC_3,     KC_4,     KC_5,     JU_6,     JU_7,     JU_8,     JU_9,     JU_0,     JU_MINS,  JU_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     JU_LBRC,  JU_RBRC,  JU_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     JU_SCLN,  JU_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  MY_IME_OFF_LALT,                                KC_SPC,                                   KC_INT4,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_87(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  BL_TOGG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______)
};
// clang-format on

// shift時のコードの制御
// jisの場合にshiftキー無しで押せる記号
void process_shift_non_tapped(uint16_t jis_code, uint16_t tapped_code) {
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
    if (lshift || rshift) {
        if (lshift) unregister_code(KC_LSFT);
        if (rshift) unregister_code(KC_RSFT);
        register_code(jis_code);
        unregister_code(jis_code);
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    } else {
        register_code(tapped_code);
        unregister_code(tapped_code);
    }
}

// shift時のコードの制御
void process_shift_tapped(uint16_t jis_code, uint16_t tapped_code) {
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
    if (lshift || rshift) {
        if (lshift) unregister_code(KC_LSFT);
        if (rshift) unregister_code(KC_RSFT);
        register_code(KC_LSFT);
        register_code(jis_code);
        unregister_code(jis_code);
        unregister_code(KC_LSFT);
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    } else {
        register_code(tapped_code);
        unregister_code(tapped_code);
    }
}

// jisキーボードにおいてもshiftを押しながら入力する必要がある文字
void process_shift_jis_tapped(uint16_t jis_code, uint16_t tapped_code) {
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
    if (lshift || rshift) {
        if (lshift) unregister_code(KC_LSFT);
        if (rshift) unregister_code(KC_RSFT);
        register_code(KC_LSFT);
        register_code(jis_code);
        unregister_code(jis_code);
        unregister_code(KC_LSFT);
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    } else {
        register_code(KC_LSFT);
        register_code(tapped_code);
        unregister_code(tapped_code);
        unregister_code(KC_LSFT);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static bool     lshift            = false;
    // static bool     rshift            = false;
    static bool     ime_toggle_active = false;
    static uint16_t ime_timer         = 0;
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case JU_2:
            if (record->event.pressed) {
                process_shift_non_tapped(KC_LBRC, KC_2);
            }
            return false;
        case JU_6:
            if (record->event.pressed) {
                process_shift_non_tapped(KC_EQL, KC_6);
            }
            return false;
        case JU_7:
            if (record->event.pressed) {
                process_shift_tapped(KC_6, KC_7);
            }
            return false;
        case JU_8:
            if (record->event.pressed) {
                process_shift_tapped(KC_QUOT, KC_8);
            }
            return false;
        case JU_9:
            if (record->event.pressed) {
                process_shift_tapped(KC_8, KC_9);
            }
            return false;
        case JU_0:
            if (record->event.pressed) {
                process_shift_tapped(KC_9, KC_0);
            }
            return false;
        case JU_MINS:
            if (record->event.pressed) {
                process_shift_tapped(KC_INT1, KC_MINS);
            }
            return false;
        case JU_EQL:
            if (record->event.pressed) {
                process_shift_jis_tapped(KC_SCLN, KC_MINS);
            }
            return false;
        case JU_LBRC:
            if (record->event.pressed) {
                process_shift_tapped(KC_RBRC, KC_RBRC);
            }
            return false;
        case JU_RBRC:
            if (record->event.pressed) {
                process_shift_tapped(KC_NUHS, KC_NUHS);
            }
            return false;
        case JU_BSLS:
            if (record->event.pressed) {
                process_shift_tapped(KC_INT3, KC_INT1);
            }
            return false;
        case JU_SCLN:
            if (record->event.pressed) {
                process_shift_non_tapped(KC_QUOT, KC_SCLN);
            }
            return false;
        case JU_QUOT:
            if (record->event.pressed) {
                process_shift_jis_tapped(KC_2, KC_7);
            }
            return false;
        case JU_GRV:
            if (record->event.pressed) {
                process_shift_jis_tapped(KC_EQL, KC_LBRC);
            }
            return false;
        case MY_IME_OFF_LALT: // Altキーの単押し
            if (record->event.pressed) {
                ime_timer         = timer_read(); // タイマー開始
                ime_toggle_active = true;
            } else {
                if (timer_elapsed(ime_timer) < TAPPING_TERM) {
                    // Alt単押しでIME切り替え（KC_LANG2を送信）
                    register_code(KC_INT5); // IMEオフ
                    unregister_code(KC_INT5);
                } else {
                    // Altキーとして動作
                    register_code(KC_LALT);
                    unregister_code(KC_LALT);
                }
                ime_toggle_active = false;
            }
            return false;
        // 他のキーとの組み合わせでAltとして機能
        default:
            if (ime_toggle_active && record->event.pressed) {
                // Altキーとして動作
                register_code(KC_LALT);
                ime_toggle_active = false;
            }
            break;
    }
    return true;
}
