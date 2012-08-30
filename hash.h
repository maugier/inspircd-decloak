#include <stdlib.h>

void segment_hash(char *out, 
                  size_t out_len, 
                  const char *key,
                  size_t key_len,
                  const unsigned char *data,
                  size_t in_len,
                  unsigned char id);
