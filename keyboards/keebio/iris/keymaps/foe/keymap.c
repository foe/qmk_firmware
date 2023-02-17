#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NAV 4
#define _APPLICATIONS 5

#define KC_CTESC   LCTL_T(KC_ESC)
#define KC_RASPC   LT(_RAISE, KC_SPC)
#define KC_NUBSPC   LT(_NUMBERS, KC_BSPC)
#define KC_LOBSP   LT(_LOWER, KC_BSPC)
#define ANAV   LT(_NAV, KC_A)
#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define SCLNAPP     LT(_APPLICATIONS, KC_SCLN)
#define CAPT    LSFT(KC_F9)
#define SHINS   LSFT(KC_INS)
#define SHBSP   LSFT_T(KC_BSPC)
#define SHSPC   LSFT_T(KC_SPC)
#define SHENT   LSFT_T(KC_ENT)
#define KC_SFTDEL  LSFT_T(KC_DEL)

// Tap Dance declarations
enum smallint{
  TD_DASH_UND
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
  CLJ_TF,
  CLJ_TL,
  CLJ_HM,
  CLJ_KEY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
                     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
                     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LSFT,
                     KC_CTESC, ANAV,  LALT_T(KC_S),    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    SCLNAPP, KC_ENT,
                     KC_LSFT , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_HOME,            KC_END,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                        KC_LALT, LOWER, SHBSP,            SHENT,  KC_RASPC,   KC_RWIN
                     ),

  [_LOWER] = LAYOUT(
                    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LSA(KC_BSPC),
                    QK_BOOT, LSA(KC_Q) , _______, _______, _______, KC_PIPE,                             _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_DQT,
                    _______, _______, _______, KC_PLUS, KC_DQT,  KC_BSLS,                             KC_PERC, KC_LPRN, KC_RPRN, KC_MINS, KC_COLON,_______,
                    _______, _______, _______, _______, KC_QUOT, _______, _______,          _______,  KC_PLUS, KC_LBRC, KC_RBRC, _______, _______, _______,
                                                         _______, _______, _______,          KC_LSFT,  _______, _______
                    ),

  [_RAISE] = LAYOUT(
                    KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                    RGB_TOG, KC_F11,  KC_F12, _______, CLJ_TL,  _______,                            _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_BSLS,
                    RGB_MOD, _______, _______, CLJ_HM,  CLJ_TF,  _______,                            KC_PERC, KC_LPRN, KC_RPRN, KC_MINS, KC_COLON, KC_PIPE,
                    KC_MUTE, _______, _______, _______, CLJ_KEY, _______, _______,          _______, KC_PLUS, KC_LBRC, KC_RBRC, _______, _______, _______,
                                                         _______, _______, _______,         _______,  _______, _______
                    ),

  [_ADJUST] = LAYOUT(
                     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SLEP,
                     RGB_TOG, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_PSCR, _______,
                     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, _______, _______,                            _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
                     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, _______, _______, _______,          _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                     _______, _______, _______,          _______, _______, _______),
  [_NAV] = LAYOUT(
                  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, CAPT,    _______, SHINS,
                  _______, _______, _______, _______, _______, _______,                            _______, KC_HOME, KC_END,  _______, _______, _______,
                  _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT, _______,
                  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                  _______, _______, _______,          _______, _______, _______
                  ),
  [_APPLICATIONS] = LAYOUT(
                           A(KC_F21), A(KC_F1)  ,A(KC_F2),  A(KC_F3),  A(KC_F4),  A(KC_F5),                        _______, _______, _______, _______, _______, _______,
                           A(KC_F22), A(KC_F6), A(KC_F7), A(KC_F8), A(KC_F9), A(KC_F10),                           _______, _______, _______, _______, _______, _______,
                           A(KC_F23), A(KC_F11), A(KC_F12), A(KC_F13), A(KC_F14), A(KC_F15),                       _______, _______, _______, _______, _______, _______,
                           A(KC_F24), A(KC_F16), A(KC_F17), A(KC_F18), A(KC_F19), A(KC_F20),_______,     _______,  _______, _______, _______, _______, _______, _______,
                                                                  _______, _______, _______,             _______,  _______, _______
                           )

  };


uint16_t get_tapping_term (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ANAV:
            return LONG_TAPPING_TERM;
        case KC_RASPC:
            return LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ANAV:
            return true;
        default:
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case CLJ_TF:
      if (record->event.pressed) {
          SEND_STRING("(-> )" SS_TAP(X_LEFT));
      }
      return true;
      break;
    case CLJ_TL:
      if (record->event.pressed) {
          SEND_STRING("(->> )" SS_TAP(X_LEFT));
      }
      return true;
      break;
    case CLJ_HM:
      if (record->event.pressed) {
          SEND_STRING("{:}" SS_TAP(X_LEFT));
      }
      return true;
      break;
    case CLJ_KEY:
      if (record->event.pressed) {
          SEND_STRING("{:keys []}" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      return true;
      break;
    case KC_BSPC:
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
      if (record->event.pressed) {
          // Detect the activation of either shift keys
          if (mod_state & MOD_MASK_SHIFT) {
              // First temporarily canceling both shifts so that
              // shift isn't applied to the KC_DEL keycode
              del_mods(MOD_MASK_SHIFT);
              register_code(KC_DEL);
              // Update the boolean variable to reflect the status of KC_DEL
              delkey_registered = true;
              // Reapplying modifier state so that the held shift key(s)
              // still work even after having tapped the Backspace/Delete key.
              set_mods(mod_state);
              return false;
          }
      } else { // on release of KC_BSPC
          // In case KC_DEL is still being sent even after the release of KC_BSPC
          if (delkey_registered) {
              unregister_code(KC_DEL);
              delkey_registered = false;
              return false;
          }
      }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
      return true;
      break;
  }

  return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return true;
}


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DASH_UND] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
};
