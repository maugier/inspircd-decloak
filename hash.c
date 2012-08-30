// Copyright 2012 Maxime Augier
// Distributed under the terms of the GNU General Public License

#include "hash.h"
#include <openssl/md5.h>

static const char base32[] = "0123456789abcdefghijklmnopqrstuv";


void segment_hash(char *out, 
                  size_t out_len, 
                  const char *key,
                  size_t key_len,
                  const unsigned char *data,
                  size_t in_len,
                  unsigned char id) {

    unsigned char buf[MD5_DIGEST_LENGTH];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, &id, 1);
    MD5_Update(&ctx, (const unsigned char *)key, key_len);
    MD5_Update(&ctx, "\0", 1);
    MD5_Update(&ctx, data, in_len);
    MD5_Final(buf, &ctx);

    out[out_len] = '\0';

    while(out_len--) {
        out[out_len] = base32[buf[out_len] & 0x1f];
    }

}

