/* crypto/evp/e_ssf33.c */
/*
 * Written by caichenghang for the TaSSL project.
 */
/* ====================================================================
 * Copyright (c) 2016 - 2018 Beijing JN TASS Technology Co.,Ltd.  All 
 * rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by Beijing JN TASS 
 *    Technology Co.,Ltd. TaSSL Project.(http://www.tass.com.cn/)"
 *
 * 4. The name "TaSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    TaSSL@tass.com.cn.
 *
 * 5. Products derived from this software may not be called "TaSSL"
 *    nor may "TaSSL" appear in their names without prior written
 *    permission of the TaSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by Beijing JN TASS 
 *    Technology Co.,Ltd. TaSSL Project.(http://www.tass.com.cn/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE TASSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE TASSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes software developed by the TaSSL Project
 * for use in the OpenSSL Toolkit (http://www.openssl.org/).
 *
 */

#include <openssl/opensslconf.h>
#ifndef OPENSSL_NO_CNSM
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <assert.h>
#include <openssl/objects.h>
#include "evp_locl.h"

#define SSF33_KEY_LENGTH          16
#define SSF33_BLOCK_SIZE          16
#define SSF33_IV_LENGTH           SSF33_BLOCK_SIZE

typedef struct
{
    unsigned char ks[SSF33_KEY_LENGTH];
} EVP_SSF33_KEY;

static int ssf33_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc)
{
    if (enc)
        EVPerr(EVP_F_SSF33_ENCRYPT_INIT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);
    else
        EVPerr(EVP_F_SSF33_ENCRYPT_INIT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);

    return 0;
}

static int ssf33_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t inl)
{
    if (ctx->encrypt)
        EVPerr(EVP_F_SSF33_CBC_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);
    else
        EVPerr(EVP_F_SSF33_CBC_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);

    return 0;
}

static int ssf33_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t inl)
{
    if (ctx->encrypt)
        EVPerr(EVP_F_SSF33_ECB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);
    else
        EVPerr(EVP_F_SSF33_ECB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);

    return 0;
}

static int ssf33_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t inl)
{
    if (ctx->encrypt)
        EVPerr(EVP_F_SSF33_CFB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);
    else
        EVPerr(EVP_F_SSF33_CFB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);

    return 0;
}

static int ssf33_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t inl)
{
    if (ctx->encrypt)
        EVPerr(EVP_F_SSF33_OFB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);
    else
        EVPerr(EVP_F_SSF33_OFB_ENCRYPT, EVP_R_METHOD_NEED_HARDWARE_SUPPORT);

    return 0;
}

static const EVP_CIPHER ssf33_ecb = {
    NID_ssf33_ecb,
    SSF33_BLOCK_SIZE,
    SSF33_KEY_LENGTH,
    0,
    0 | EVP_CIPH_ECB_MODE,
    ssf33_init_key,
    ssf33_ecb_cipher,
    NULL,
    sizeof(EVP_SSF33_KEY),
    NULL,
    NULL,
    NULL,
    NULL
};
const EVP_CIPHER *EVP_ssf33_ecb(void)
{
    return &ssf33_ecb;
}

static const EVP_CIPHER ssf33_cbc = {
    NID_ssf33_cbc,
    SSF33_BLOCK_SIZE,
    SSF33_KEY_LENGTH,
    SSF33_IV_LENGTH,
    0 | EVP_CIPH_CBC_MODE,
    ssf33_init_key,
    ssf33_cbc_cipher,
    NULL,
    sizeof(EVP_SSF33_KEY),
    NULL,
    NULL,
    NULL,
    NULL
};
const EVP_CIPHER *EVP_ssf33_cbc(void)
{
    return &ssf33_cbc;
}

static const EVP_CIPHER ssf33_ofb = {
    NID_ssf33_ofb,
    1,
    SSF33_KEY_LENGTH,
    SSF33_IV_LENGTH,
    0 | EVP_CIPH_OFB_MODE,
    ssf33_init_key,
    ssf33_ofb_cipher,
    NULL,
    sizeof(EVP_SSF33_KEY),
    NULL,
    NULL,
    NULL,
    NULL
};
const EVP_CIPHER *EVP_ssf33_ofb(void)
{
    return &ssf33_ofb;
}

static const EVP_CIPHER ssf33_cfb = {
    NID_ssf33_cfb,
    1,
    SSF33_KEY_LENGTH,
    SSF33_IV_LENGTH,
    0 | EVP_CIPH_CFB_MODE,
    ssf33_init_key,
    ssf33_cfb_cipher,
    NULL,
    sizeof(EVP_SSF33_KEY),
    NULL,
    NULL,
    NULL,
    NULL
};
const EVP_CIPHER *EVP_ssf33_cfb(void)
{
    return &ssf33_cfb;
}

#endif



