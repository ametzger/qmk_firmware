/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#define BASE 0
#define HHKB 1

enum custom_keycodes {
    ASMIO = SAFE_RANGE,
    JF_EMAIL,
    ASM_EMAIL,
    GMAIL_EMAIL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

    [BASE] = LAYOUT( //  default layer
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9, KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O, KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(HHKB),
        KC_LALT, KC_LGUI, /*        */ KC_SPC, KC_RGUI, KC_RALT),

    /* Layer HHKB: HHKB mode (HHKB Fn)
      |-----------+----------+-------+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr       | F1       | F2    | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |-----------+----------+-------+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | ASM_EMAIL | JF_EMAIL | ASMIO |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |-----------+----------+-------+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |           | VoD      | VoU   | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |-----------+----------+-------+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |           | reg-qr   | mctl  |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |-----------+----------+-------+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [HHKB] = LAYOUT(
        KC_TRNS,   KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        ASM_EMAIL, JF_EMAIL,  ASMIO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   KC_TRNS, KC_BSPC,
        KC_TRNS,   KC_VOLD,   KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS,   MEH(KC_5), KC_MCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,                             KC_MPLY,                   KC_TRNS, KC_TRNS)};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ASMIO:
    if (record->event.pressed) {
      SEND_STRING("https://asm.io/i/");
    }
    break;
  case JF_EMAIL:
    if (record->event.pressed) {
      SEND_STRING("asm@jellyfish.co");
    }
    break;
  case ASM_EMAIL:
    if (record->event.pressed) {
      SEND_STRING("asm@asm.io");
    }
    break;
  case GMAIL_EMAIL:
    if (record->event.pressed) {
      SEND_STRING("alex.metzger@gmail.com");
    }
    break;
  }

  return true;
};
