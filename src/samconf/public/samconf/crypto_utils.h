// SPDX-License-Identifier: MIT
#ifndef SAMCONF_CRYPTO_UTILS_H
#define SAMCONF_CRYPTO_UTILS_H

#include <openssl/evp.h>

#include "samconf/samconf.h"

__BEGIN_DECLS

samconfConfigStatusE_t samconfLoadPublicKey(EVP_PKEY **pKey);
samconfConfigStatusE_t samconfBase64Decode(const char *base64, uint8_t **buf, size_t *bufLen);
samconfConfigStatusE_t samconfCryptoUtilsVerify(const char *data, size_t lenght, const char *signature);

__END_DECLS

#endif /* SAMCONF_CRYPTO_UTILS_H */
