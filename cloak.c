#include "hash.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

    unsigned char quad[4];
    char buf[7];
    size_t key_len;

    if (argc != 3) {
        fprintf(stderr,"Usage: cloak <secret> <ip address>\n");
        return 1;
    }

    key_len = strlen(argv[1]);

    if (4 != sscanf(argv[2], "%hhd.%hhd.%hhd.%hhd", quad, quad+1, quad+2, quad+3)) {
        fprintf(stderr,"IP address must be in dotted quad format\n");
        return 2;
    }

    segment_hash(buf, 3, argv[1], key_len, quad, 4, 10);
    printf("%s.", buf);    
    segment_hash(buf, 3, argv[1], key_len, quad, 3, 11);
    printf("%s.", buf);
    segment_hash(buf, 6, argv[1], key_len, quad, 2, 13);
    printf("%s\n", buf);

    return 0;    
}
