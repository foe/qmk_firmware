/* Copyright 2015-2021 Jack Humbert
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


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATION,
  _NUMBERS,
  _GUI
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  BACKLIT,
};

#define LOWER      MO(_LOWER)
#define RAISE      MO(_RAISE)
#define NUM        MO(_NUMBERS)
#define GUI        TG(_GUI)
#define CTRL_ESC   LCTL_T(KC_ESC)
#define NAV        MO(_NAVIGATION)
#define SFT_ENT    RSFT_T(KC_ENT)
#define RAI_SPC    LT(_RAISE, KC_SPC)
#define NAV_A      LT(_NAVIGATION, KC_A)
#define NAV_O      LT(_NAVIGATION, KC_O)
#define NAV_SCLN   LT(_NAVIGATION, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    CTRL_ESC, NAV_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NAV_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUM,  LOWER,   KC_ENT,  KC_BSPC,  RAI_SPC,  NUM, KC_RALT, KC_RGUI, GUI
),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    CTRL_ESC,NAV_A,   KC_R,    KC_S,   KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    NAV_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_D,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, NUM,    LOWER,   KC_ENT, KC_BSPC,  RAI_SPC,  NUM,     KC_RALT, KC_RGUI, GUI
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILDE, KC_TRNS, KC_TRNS, KC_LT, KC_GT, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TILDE, KC_PIPE, KC_EQUAL,
    KC_TRNS, KC_EQL, KC_PPLS, KC_UNDS, KC_MINS, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_BSLS, KC_COLN, KC_DQT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_COLN, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS),


[_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,     KC_9,     KC_0,     KC_TRNS,
    KC_TRNS, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,   KC_ASTR,  KC_MINUS, KC_EQUAL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLASH,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_NAVIGATION] = LAYOUT_planck_grid(
    LSFT(KC_F9), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), KC_PSCR, LSFT(KC_INS),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_NUMBERS] = LAYOUT_planck_grid(
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PAST,
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PSLS,
    KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS,
    KC_TRNS, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_P0, KC_P0, KC_PDOT, KC_PCMM, KC_TRNS),


[_GUI] = LAYOUT_planck_grid(
   KC_NO,   KC_NO,   KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SLEP,
   KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
   KC_NO,   KC_NO,   KC_BTN2, KC_BTN3, KC_BTN1, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAVIGATION, KC_A):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LT(_NAVIGATION, KC_SCLN):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LT(_RAISE, KC_SPC):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}
