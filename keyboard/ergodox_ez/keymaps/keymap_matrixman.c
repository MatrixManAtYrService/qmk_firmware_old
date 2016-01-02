#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAV 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Prose layer
 *
 * Layer switch keys:
 * [tap/toggle]
 * (momentary)
 * {toggle}
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | BSPC |           | Del  |   6  |   7  |   8  |   9  |   0  | BSPC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  | Ctrl/|           |Ctrl/ |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| Esc  |           |  ;   |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|Shift/|           |Shift/|------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |Tab   |           |Tab   |   N  |   M  |   ,  |   .  | /    | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctrl  |Super |  Alt |[Symb]| [Nav]|                                      |[Nav] |[Symb]|Super  | Ctxt | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |(Nav) |       | (Nav)|        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   |Alt/Ins|    |Alt/Caps|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_BSPC,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   CTL_T(KC_ESC),
        KC_LCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   SFT_T(KC_TAB),
        KC_LCTRL,       KC_LGUI,      KC_LALT,KC_FN1, KC_FN2,
                                              KC_NO,  KC_NO,
                                                              MO(NAV),
                                               KC_SPC,KC_BSPC,ALT_T(KC_INS),
        // right hand
             KC_DELETE,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             CTL_T(KC_SCLN),KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             SFT_T(KC_TAB), KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                    KC_FN2, KC_FN1, KC_RGUI,KC_MENU,          KC_RCTRL,
             KC_NO,   KC_NO,
             MO(NAV),
             ALT_T(KC_CAPS), KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |   [  |           |  ]   |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  `   |  ~   |   *  |   &  |   {  |  <   |           |  >   |   }  |   7  |   8  |   9  |   |  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   |  ^   |   %  |   $  |   (  |------|           |------|   )  |   4  |   5  |   6  |   -  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  =   |  #   |   @  |   !  |   \  |      |           |      |   /  |   1  |   2  |   3  |   +  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_LCBR,  KC_LSTH,
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,  
       KC_TRNS,  KC_EQL,   KC_HASH,  KC_AT,    KC_EXLM,  KC_BSLS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                               KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
       KC_RBRC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_GRTH,  KC_RCBR,  KC_7,     KC_8,     KC_9,     KC_PIPE,  KC_TRNS,
                 KC_RPRN,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_ENT,
       KC_TRNS,  KC_SLSH,  KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_ENT,
                           KC_0,     KC_TRNS,  KC_DOT,   KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 2: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |Break |           |PrntSc|  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ---  |MsLeft|MsUp  |MsDown|MsRght|------|           |------| Left | Down | Up   | Right|  F11 |   Enter|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ---  | Btn4 |ScrlDn|ScrlUp| Btn5 |      |           |      | Home | PgDwn| PgUp | End  |  F12 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
KEYMAP(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_PAUSE,
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_TRNS,
       KC_TRNS,  KC_BTN1,  KC_MS_L,        KC_MS_U,      KC_MS_D,  KC_MS_R,  
       KC_TRNS,  KC_BTN2,  KC_BTN4,        KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_BTN5,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,      KC_TRNS,            
                                           KC_TRNS,      KC_TRNS,
                                                         KC_TRNS,
                               KC_TRNS,    KC_TRNS,      KC_TRNS,    
       // right hand
       KC_PSCREEN,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
       KC_TRNS,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_ENT,
       KC_TRNS,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_TRNS,
                              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,     KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Tap/Toggle Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(NAV)                // FN2 - Tap/Toggle Layer 2 (Nav)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
