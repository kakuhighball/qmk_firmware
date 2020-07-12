/* Copyright 2015-2017 Jack Humbert
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

enum custom_keycodes {
  SNIP = SAFE_RANGE,
  EMDASH,
  ENDASH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SNIP:
      if (record->event.pressed) {
        // when keycode SNIP is pressed
        SEND_STRING(SS_LGUI(SS_LSFT("s")));
      } else {
        // when keycode SNIP is released
      }
    break;
    case EMDASH:
      if (record->event.pressed) {
        // when keycode EMDASH is pressed
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
      } else {
        // when keycode EMDASH is released
      }
    break;
    case ENDASH:
      if (record->event.pressed) {
        // when keycode ENDASH is pressed
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0)));
      } else {
        // when keycode ENDASH is released
      }
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * | Esc  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  | Del |
 * |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Tab  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Backspace |
 * |------------------------------------------------------------------------------------------|
 * | Control |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    |
 * |------------------------------------------------------------------------------------------|
 * |   L Shift  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  R Shift  |  Fn |
 * |------------------------+-----------------------------------------------------------------|
 * |  Ctrl  |  GUI  |  Alt  |              Space                    |   GUI  |  Menu |  Ctrl  |
 * `------------------------------------------------------------------------------------------'
 */

[0] = LAYOUT_60_ansi_split_bs_rshift( \
  KC_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,      KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,    KC_SLSH, KC_RSFT, MO(1), \
  MO(1),   KC_LGUI, KC_LALT,             KC_SPC,     XXXXXXX,                  MO(2),   KC_RGUI, KC_RCTL \
),

/* Function
 * ,------------------------------------------------------------------------------------------.
 * |   ~  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
 * |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |      |     |  Up |     |     | Vol+|     |     | Prnt| PgUp|PgDwn|  Up |     |           |
 * |------------------------------------------------------------------------------------------|
 * |   Caps  | left| down|right|     | Vol-|     |     | Home| End | left|right|              |
 * |------------------------------------------------------------------------------------------|
 * |            |GBTOG|GBMOD|GBHUD|GBHUI|GBSAD|GBSAI|GBVAD|GBVAI|     | down|           |  Fn |
 * |------------------------+-----------------------------------------------------------------|
 * | Backlit|       |       |                                        |       |       |        |
 * `------------------------------------------------------------------------------------------'
 */

[1] = LAYOUT_60_ansi_split_bs_rshift( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  SNIP, \
  KC_CAPS, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
  _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, MO(3),   _______,
  _______, _______, _______,                   _______,          XXXXXXX,                   _______, _______, _______ \
),

[2] = LAYOUT_60_ansi_split_bs_rshift( \
  RGB_TOG, RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, _______, RESET,
  _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, RGB_RMOD, RGB_MOD, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
  _______, _______, _______,                   _______,          XXXXXXX,                   _______, _______,  _______ \
),

[3] = LAYOUT_60_ansi_split_bs_rshift( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ENDASH,  EMDASH,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,                   _______,          XXXXXXX,                   _______, _______, _______ \
)

};