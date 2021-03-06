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
#include "muse.h"

extern keymap_config_t keymap_config;

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
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    NAV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   TD(TD_OB), TD(TD_CB), KC_MINUS,   KC_EQUAL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Play |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   {  |   }  |  ¬   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  [   |  ]   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_MPLY, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, _______,    KC_LCBR, KC_RCBR, S(KC_GRAVE),
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_LBRC, KC_RBRC, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Play |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Esc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  `   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   #  |   ~  |      |      |      |      |   #  |      |   .  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   # |       |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_MPLY,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
    KC_DEL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_GRAVE,
    _______,  KC_NUHS, S(KC_NUHS), _______, _______, _______, _______, KC_NUHS, _______, KC_DOT, KC_NUBS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, _______, _______, _______
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
[_NAV] = LAYOUT_planck_grid(
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_UP,    _______, _______, _______,
    _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_END,  _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | MuMod|Aud on|Audoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG, _______, _______, _______, _______, _______, _______,  _______, _______, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

// defining songs
// we aren't actually playing these anymore but leaving it here in case I want to do similar
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// turn on _Adjust layer if two layers are pressed together
uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/** Rotary Encoder
 *  ------------------------------------------------------------------------------------------------
 *  Media controls: https://www.reddit.com/r/olkb/comments/9jzbg1/help_with_rotary_encoder_code/
 *  - turns out volume control doesn't work if you just register/unregister.
 *  - followed advice from reddit thread to add a 10ms delay...
**/
// wait DELAY ms before unregistering media keys
#define MEDIA_KEY_DELAY 10
// currently the encoder controls volume when raised or when lowered
// we could do something more fun with it in one of these states?
void encoder_update(bool clockwise) {
  uint16_t held_keycode_timer = timer_read();

  if (IS_LAYER_ON(_RAISE)) {
    if (clockwise) {
      register_code(KC_VOLU);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        // no-op
      }
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        // no-op
      }
      unregister_code(KC_VOLD);
    }
  } else if (IS_LAYER_ON(_LOWER)) {
    if (clockwise) {
      register_code(KC_VOLU);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        // no-op
      }
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        // no-op
      }
      unregister_code(KC_VOLD);
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

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

// removed muse and dip switch options here as I'm not using them.
// refer to the default keymap if you want to implement a DIP switch

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
