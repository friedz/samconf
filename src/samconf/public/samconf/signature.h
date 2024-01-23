// SPDX-License-Identifier: MIT
#ifndef SAMCONF_SIGNATURE_H
#define SAMCONF_SIGNATURE_H

#include "samconf/samconf.h"

__BEGIN_DECLS

samconfConfigStatusE_t samconfSignatureLoaderGetSignatureFor(const char *file, char **signature, size_t *len);

__END_DECLS

#endif /* SAMCONF_SIGNATURE_H */
