#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _GAMING 1
#define _LOWER 2
// #define _NAV 3

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  GAMING,
  LOWER,
};

// Aliases
// MOD_ prefix for MT(MOD, kc)
// KH_ prefix for Hold toggle
// KD_ prefix for Tapdance
// O prefix for One shot

#define HESC LT(_LOWER, KC_ESC)
#define MOD_Z MT(MOD_LCTL, KC_Z)
#define MOD_X MT(MOD_LALT, KC_X)
#define MOD_BSPC MT(MOD_LSFT, KC_BSPC)
#define MOD_SPC MT(MOD_RSFT, KC_SPC)
#define DLSFT TD(TD_LSFT)
#define HBSPC LT(_LOWER, KC_BSPC)
#define TGUI MT(MOD_LGUI, KC_TAB)
//#define KC_SENT MT(MOD_LSFT, KC_ENT)
#define SSPC MT(MOD_LSFT, KC_SPC)
#define KC_RGB_MOD RGB_MOD

#define OALT OSM(MOD_LALT)

// Define tapdance
enum {
  TD_LSFT = 0,
  SINGLE_TAP_SPACE = 1,
};

/* enum combos { */
/*   NT_ESC */
/* }; */
/*  */
/* const uint16_t PROGMEM nt_combo[] = {KC_N, KC_T, COMBO_END}; */
/*  */
/* combo_t key_combos[COMBO_COUNT] = { */
/*   [NT_ESC] = COMBO(nt_combo, KC_ESC) */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  // * MOD DH variant
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬───────┬──────┐
     KC_EQL,1,     2,     3,      4,    5,                           6,    7,     8,     9,     0,     KC_MINUS,
  //├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼───────┼──────┤
     KC_TAB,KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,                       KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN,KC_BSLASH,
  //├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼───────┼──────┤
     HESC,  KC_A,  KC_R,  KC_S,  KC_T,  KC_G,                       KC_K,  KC_N,  KC_E,  KC_I,  KC_O,   KC_QUOT,
  //├──────┼──────┼──────┼──────┼──────┼──────┼───────┐    ┌───────┼──────┼──────┼──────┼──────┼───────┼──────┤
     DLSFT, KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,  KC_LSFT,     KC_DEL, KC_M,  KC_H,  KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,
  //└──────┴──────┴──────┴───┬──┴──┬──┴───┬───┴───┬──┘     └───┬───┴──┬───┴───┬──┴───┬──┴──────┴───────┴──────┘
                              KC_LCTL,HBSPC,TGUI,               KC_ENT,SSPC,  KC_LALT
  //                         └─────┴──────┴───────┘            └──────┴───────┴──────┘
  ),

  [_LOWER] = LAYOUT(
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬───────┬──────┐
     KC_F12,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  //├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼───────┼──────┤
     KC_NO,RGB_MOD,KC_PSCR,KC_LCBR,KC_RCBR,KC_PIPE,                 KC_UP, 7,     8,     9,     KC_HOME,KC_VOLU,
  //├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼───────┼──────┤
     KC_NO,KC_PGUP,KC_PGDN,KC_LPRN,KC_RPRN, KC_GRAVE,               KC_DOWN,4,    5,     6,     KC_END,  KC_VOLD,
  //├──────┼──────┼──────┼──────┼──────┼──────┼───────┐    ┌───────┼──────┼──────┼──────┼──────┼───────┼──────┤
     KC_NO,KC_LCTL,OALT ,KC_LBRC,KC_RBRC,  KC_TILD,KC_NO,      KC_NO, KC_AMPR, 1,    2,     3,    KC_RALT, KC__MUTE,
  //└──────┴──────┴──────┴───┬──┴──┬──┴───┬───┴───┬──┘    └───┬───┴──┬───┴───┬──┴───┬──┴──────┴───────┴──────┘
                              KC_LCTL,KC_LALT,KC_NO,            KC_LEFT,KC_RGHT,0
  //                         └─────┴──────┴───────┘            └──────┴───────┴──────┘
  ),

  [_GAMING] = LAYOUT(

  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_M,    KC_M,    _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_SPC,  KC_SPC,                    KC_ENT,  KC_BSPC, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
  [_NAV] = LAYOUT(
  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                     M↑
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            M←       M↓        M→                                                     ←        ↓        ↑        →
  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                     LCLK     RCLK
  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                                                        PGUP     PGDOWN
                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    _______, _______,  _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    _______, _______,  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,                   _______, KC_PGUP, KC_PGDN
  )
  */

};

/*
  [_BLANK] = LAYOUT(
  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ 
  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),
*/
/*
  [_PLOVER] = LAYOUT(
  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   EXT_PLOVER
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            S        T        P        H        *                                   *        F        P        L        T        D
  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            S        K        W        R        *                                   *        R        B        G        S        Z
  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  A        O                                            E        U
                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    EXT_PLV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,                            STN_ST3, STN_FR, STN_PR , STN_LR , STN_TR , STN_DR ,
    XXXXXXX, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, XXXXXXX,          XXXXXXX, STN_ST4, STN_RR, STN_BR , STN_GR , STN_SR , STN_ZR ,
                                  STN_A, STN_O, _______,                   _______, STN_E, STN_U
  ),
*/

// Tap dance GAMING toggle
int GAMINGlayer = 0;

void dance_qwerty_toggle (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    if (GAMINGlayer == 1) {
      layer_off(_GAMING);
      GAMINGlayer = 0;
    } else {
      layer_on(_GAMING);
      GAMINGlayer = 1;
    }

    reset_tap_dance (state);
  } else {
    register_code(KC_LSFT);
  }
}

void dance_qwerty_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_LSFT);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSFT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qwerty_toggle, dance_qwerty_reset)
  // Other declarations would go here, separated by commas, if you have them
};
