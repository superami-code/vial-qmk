#include "raw_hid.h"
#include "qmk_rc.h"

#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);;
}
