/* https://www.reddit.com/r/ErgoMechKeyboards/comments/w169sa/a_simple_34key_layout_with_oneshot_mods/
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
	 * -----------|  MO(_ACT) |  KC_LSFT  |   | KC_SPC |  MO(_SYM)  |-----------
	 */
	[_ABC] = LAYOUT(
			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
			KC_A,    KC_R,    KC_S,    KC_T,    KC_G,         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SCLN,
			MO(_ACT), KC_LSFT,                       KC_SPC,  MO(_SYM)
		       ),

	/* ACT - ACTION LAYER (Navigation & Standard Modifiers)
	 * ----------------------------------------   ----------------------------------------
	 * |      |       |       |      | P UP |           |      |CTL+BS|  ↑   | TAB  |      |
	 * | CTRL |  ALT  |  GUI  | SHIFT| P DN |           | BKSP |  ←   |  ↓   |  →   | DEL  |
	 * |      |       |       |      |      |           |      | HOME |      | END  |      |
	 * -----------| _______| _______|                   | KC_ENT | KC_ESC |-----------
	 */
	[_ACT] = LAYOUT(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,      XXXXXXX, LCTL(KC_BSPC), KC_UP,   KC_TAB,  XXXXXXX,
			KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_PGDN,      KC_BSPC, KC_LEFT,       KC_DOWN, KC_RGHT, KC_DEL,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_HOME,       XXXXXXX, KC_END,  XXXXXXX,
			_______, _______,                        KC_ENT,  KC_ESC
		       ),

	/* SYM - SYMBOL & NUMBER LAYER (Standard Modifiers Mirrored)
	 * ----------------------------------------   ----------------------------------------
	 * |  \  |  1  |  2  |  3  |  /  |           |  F1  |  F2  |  F8  |  F10 |  F12 |
	 * |  [  |  4  |  5  |  6  |  ]  |           |TG_MSE| SHIFT|  GUI |  ALT | CTRL |
	 * |  `  |  7  |  8  |  9  |  0  |           | CAPS |      |      |      |      |
	 * -----------| KC_MINS | KC_EQL |           | _______| _______|-----------
	 */
	[_SYM] = LAYOUT(
			KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH,      KC_F1,       KC_F2,   KC_F8,   KC_F10,  KC_F12,
			KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC,      TG(_MOUSE),  KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
			KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,         CW_TOGG,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			KC_MINS, KC_EQL,                         _______,     _______
		       ),

	/* MOUSE - MOUSE CONTROLLER LAYER
	 * ----------------------------------------   ----------------------------------------
	 * |      |      |      |      |      |           |      | WH_UP| MS_UP| WH_DN|      |
	 * |      |      |      |      |      |           |TG_MSE| MS_LFT| MS_DN| MS_RGT|     |
	 * |      |      |      |      |      |           |      | BTN1 | BTN3 | BTN2 |      |
	 * -----------| _______| _______|                   | _______| _______|-----------
	 */
	[_MOUSE] = LAYOUT(
			  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,    MS_WHLU, MS_UP,   MS_WHLD, XXXXXXX,
			  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      TG(_MOUSE), MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,
			  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,    MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX,
			  _______, _______,                                    _______, _______
			 )
};
