/* Copyright 2023 Yiancar-Designs
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
#include "../../../lib/rdr_lib/rdr_common.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
};

//Tap Dance Declarations
enum {
  TD_OB = 0,
  TD_CB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
// activates _NAV layer when held - sends tab when tapped
#define NAV LT(_NAV, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |NavTab|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   \  | GUI  | Alt  |Lower |    Space    |Raise | ([{  | )]}  |   -  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_tkl_ansi(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    NAV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENTER),
    KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER,           KC_SPC,  RAISE,   TD(TD_OB), TD(TD_CB), KC_MINUS,   KC_EQUAL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   {  |   }  |  ¬   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  [   |  ]   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_tkl_ansi(
    KC_TRANSPARENT, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR, KC_RCBR, S(KC_GRAVE),
    KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRANSPARENT, KC_LBRC, KC_RBRC, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  `   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   #  |   ~  |      |      |      |      |   #  |      |   .  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   # |       |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_tkl_ansi(
    KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    KC_TRANSPARENT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRAVE,
    KC_TRANSPARENT, KC_NUHS, S(KC_NUHS), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NUHS, KC_TRANSPARENT, KC_DOT, KC_NUBS, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NUHS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Nav (media keys and navigation - hold tab)
 * ,-----------------------------------------------------------------------------------.
 * |      | Prev | Play | Next |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ | Mute |      | Home | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  End |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_tkl_ansi(
    KC_TRANSPARENT, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRANSPARENT, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_END,  KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Adjust (Lower + Raise) - this one differs from planck - it uses specific geonix codes
 * ,-----------------------------------------------------------------------------------.
 * | USB  | BT1  | BT2  | BT3  |2.4ghz|RGBMd+|      |      |      |      |      |RGBTog|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |Brigh+|Batter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | reset       |      |      |Speed-|Brigh-|Speed+|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_tkl_ansi(
        MD_USB, MD_BLE1, MD_BLE2, MD_BLE3, MD_24G, RGB_MOD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_RTOG,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAI , QK_BAT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, U_EE_CLR, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SPD, RGB_VAD, RGB_SPI
    )

};

// turn on _Adjust layer if two layers are pressed together
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


/** Tap Dances
 *  ------------------------------------------------------------------------------------------------
 *  Tap Brackets:
 *    - cycles through ( [ { and ) ] }
 *    - let's you over tap (i.e 5 taps goes back to `[` )
**/
void td_open_brackets (tap_dance_state_t *state, void *user_data) {
  if (state->count % 3 == 0) {
    // 3 taps for {
    register_code (KC_LSFT);
    register_code (KC_LBRC);
    unregister_code (KC_LSFT);
    unregister_code (KC_LBRC);
  } else if (state->count % 3 == 2) {
    // 2 taps for [
    register_code (KC_LBRC);
    unregister_code (KC_LBRC);
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

void td_close_brackets (tap_dance_state_t *state, void *user_data) {
  if (state->count % 3 == 0) {
    // 3 taps for }
    register_code (KC_LSFT);
    register_code (KC_RBRC);
    unregister_code (KC_LSFT);
    unregister_code (KC_RBRC);
  } else if (state->count % 3 == 2) {
    // 2 taps for ]
    register_code (KC_RBRC);
    unregister_code (KC_RBRC);
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

tap_dance_action_t tap_dance_actions[] = {
 [TD_OB] = ACTION_TAP_DANCE_FN (td_open_brackets),
 [TD_CB] = ACTION_TAP_DANCE_FN (td_close_brackets)
};
