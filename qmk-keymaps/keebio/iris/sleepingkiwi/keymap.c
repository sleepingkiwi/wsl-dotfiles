#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _RAISE 1
#define _NAV 2

//Tap Dance Declarations
enum {
  TD_OB = 0,
  TD_CB
};

// ref: https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
// activates _RAISE layer when held - sends space when tapped
#define RAISE LT(_RAISE, KC_SPC)
// activates _NAV layer when held - sends tab when tapped
#define NAV LT(_NAV, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     NAV,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, TD(TD_OB),        TD(TD_CB),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT,   RAISE,                     RAISE, KC_MINUS, KC_EQUAL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

//   [_LOWER] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,                          RGB_VAI, RGB_VAD, _______, _______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                               KC_6,    KC_7,    KC_8,   KC_9,    KC_0,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRAVE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_NUHS, S(KC_NUHS), _______, _______, _______, _______,     _______, _______, KC_NUHS, S(KC_NUHS), KC_DOT, KC_NUBS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,                            _______, _______, KC_UP, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_END, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


/** Tap Dances
 *  ------------------------------------------------------------------------------------------------
 *  Tap Brackets:
 *    - cycles through ( [ { and ) ] }
 *    - let's you over tap (i.e 5 taps goes back to `[` )
**/
void td_open_brackets (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count % 3 == 0) {
    // 3 taps for {
    register_code (KC_LSFT);
    register_code (KC_LBRACKET);
    unregister_code (KC_LSFT);
    unregister_code (KC_LBRACKET);
  } else if (state->count % 3 == 2) {
    // 2 taps for [
    register_code (KC_LBRACKET);
    unregister_code (KC_LBRACKET);
  } else {
    // 1 tap for (
    register_code (KC_LSFT);
    register_code (KC_9);
    unregister_code (KC_LSFT);
    unregister_code (KC_9);
  }
  // reset state
  reset_tap_dance (state);
}

void td_close_brackets (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count % 3 == 0) {
    // 3 taps for }
    register_code (KC_LSFT);
    register_code (KC_RBRACKET);
    unregister_code (KC_LSFT);
    unregister_code (KC_RBRACKET);
  } else if (state->count % 3 == 2) {
    // 2 taps for ]
    register_code (KC_RBRACKET);
    unregister_code (KC_RBRACKET);
  } else {
    // 1 tap for )
    register_code (KC_LSFT);
    register_code (KC_0);
    unregister_code (KC_LSFT);
    unregister_code (KC_0);
  }
  // reset state
  reset_tap_dance (state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_OB] = ACTION_TAP_DANCE_FN (td_open_brackets),
 [TD_CB] = ACTION_TAP_DANCE_FN (td_close_brackets)
};


// default encoder code left in place even though we don't have an encoder on the board...
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
