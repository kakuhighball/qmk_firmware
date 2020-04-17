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

	// Default layer
	[0] = LAYOUT_all(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_PSCR,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_HOME,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_END,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   MO(1),
		MO(1),   KC_LGUI, KC_LALT,                            KC_SPC,                                      MO(2),            KC_LEFT, KC_DOWN, KC_RGHT),

	// Fn1 Layer
	[1] = LAYOUT_all(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,  SNIP,
		KC_CAPS, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,		_______, _______,          _______,
		_______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,                   _______,
		_______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, MO(3),                   	_______, _______,
		_______, _______, _______,                            _______,                                     _______,          _______, _______, _______),

	// Fn2 Layer
	[2] = LAYOUT_all(
		_______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  _______, _______, RESET,
		_______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
		_______, _______, _______,                            _______,                                     _______,          _______, _______, _______),

	// Fn3 Layer
	[3] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ENDASH, 	EMDASH,	 _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
		_______, _______, _______,                            _______,                                     _______,          _______, _______, _______),
};
