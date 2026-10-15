/* Original:
 * https://www.reddit.com/r/ErgoMechKeyboards/comments/w169sa/a_simple_34key_layout_with_oneshot_mods/
 * https://github.com/rizo
 */

#include QMK_KEYBOARD_H

#define KC_STAB LSFT(KC_TAB)

// Define Layer Names
enum custom_layers {
    _ABC = 0,
    _ACT,
    _SYM,
    _MOUSE
};

// Layout alias for readability (Standard 34-key split matrix)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ABC - BASE LAYER (Colemak-DH)
     * ----------------------------------------   ----------------------------------------
     * |  Q  |  W  |  F  |  P  |  B  |           |  J  |  L  |  U  |  Y  |  '  |
     * |  A  |  R  |  S  |  T  |  G  |           |  M  |  N  |  E  |  I  |  O  |
     * |  Z  |  X  |  C  |  D  |  V  |           |  K  |  H  |  ,  |  .  |  ;  |
     * -----------| MO(_ACT) | KC_LSHIFT |       | LT(_MOUSE, KC_SPC) | MO(_SYM) |-----------
     */
    [_ABC] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SCLN,
                 MO(_ACT), KC_LSFT,                       LT(_MOUSE, KC_SPC), MO(_SYM)
    ),

    /* Transparent keys to use? */
    /* ACT - ACTION LAYER (Navigation & Modifiers)
     * ----------------------------------------   ----------------------------------------
     * |      |       |       |      | P UP |           |      | B_TAB|  ↑   | TAB  |      |
     * | CTRL |  OPT  |  CMD  | SHIFT| P DN |           | BKSP |  ←   |  ↓   |  →   | DEL  |
     * |      |       |       |      |      |           |      | HOME |      | END  | CAPS |
     * -----------| XXXXXX | XXXXXX |                   | KC_ENT | KC_ESC |-----------
     */
    [_ACT] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,      XXXXXXX, KC_STAB, KC_UP,   KC_TAB,  XXXXXXX,
        KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, KC_PGDN,      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_HOME, XXXXXXX, KC_END,  KC_CAPS,
                 _______, _______,                        KC_ENT,  KC_ESC
    ),

    /* SYM - SYMBOL & NUMBER LAYER
     * ----------------------------------------   ----------------------------------------
     * |  \  |  1  |  2  |  3  |  /  |           |      |      |      |      |      |
     * |  [  |  4  |  5  |  6  |  ]  |           |      | SHIFT| CMD  | OPT  | CTRL |
     * |  `  |  7  |  8  |  9  |  0  |           |      |      |      |      |      |
     * -----------| KC_MINS | KC_EQL |           | XXXXXX | XXXXXX |-----------
     */
    [_SYM] = LAYOUT(
        KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC,      XXXXXXX, KC_LSFT, KC_LCMD, KC_LALT, KC_LCTL,
        KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_MINS, KC_EQL,                         _______, _______
    ),

    /* MOUSE - NEW MOUSE CONTROLLER LAYER
     * ----------------------------------------   ----------------------------------------
     * |      |      |      |      |      |           | WH_UP| M_LFT| M_UP | M_RGT|      |
     * |      |      |      |      |      |           | WH_DN| BTN1 | M_DN | BTN2 | BTN3 |
     * |      |      |      |      |      |           |      |      |      |      |      |
     * -----------| XXXXXX | XXXXXX |           | XXXXXX | XXXXXX |-----------
     */
    [_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MS_WHLU, MS_LEFT, MS_UP,   MS_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MS_WHLD, MS_BTN1, MS_DOWN, MS_BTN2, MS_BTN3,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, _______,                        _______, _______
    )
};

