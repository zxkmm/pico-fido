/*
 * This file is part of the Pico FIDO distribution (https://github.com/polhenarejos/pico-fido).
 * Copyright (c) 2022 Pol Henarejos.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _FIDO_H_
#define _FIDO_H_

#include <stdlib.h>
#include "pico/stdlib.h"
#include "common.h"
#include "mbedtls/ecdsa.h"
#include "ctap_hid.h"

#define CTAP_PUBKEY_LEN (65)
#define KEY_PATH_LEN (32)
#define KEY_PATH_ENTRIES (KEY_PATH_LEN / sizeof(uint32_t))
#define SHA256_DIGEST_LENGTH (32)
#define KEY_HANDLE_LEN (KEY_PATH_LEN + SHA256_DIGEST_LENGTH)

extern int scan_files();
extern int derive_key(const uint8_t *app_id, bool new_key, uint8_t *key_handle, mbedtls_ecdsa_context *key);
extern bool wait_button_pressed();
extern CTAPHID_FRAME *ctap_req, *ctap_resp;

#define FIDO2_ALG_ES256     -7 //ECDSA-SHA256 P256
#define FIDO2_ALG_EDDSA     -8 //EdDSA
#define FIDO2_ALG_ES384     -35 //ECDSA-SHA384 P384
#define FIDO2_ALG_ES512     -36 //ECDSA-SHA512 P521


#endif //_FIDO_H
