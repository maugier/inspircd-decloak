// Copyright 2012 Maxime Augier
// Distributed under the terms of the GNU General Public License


#include "hash.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

    char w1[4], w2[4], w3[7], buf[7];
    unsigned char quad[4];
    size_t key_len;
    unsigned short *p1;
    unsigned char *p2;

    if (argc != 3) {
        fprintf(stderr,"Usage: cloak <secret> <cloaked host>\n");
        return 1;
    }

    key_len = strlen(argv[1]);

    if (3 != sscanf(argv[2], "%3s.%3s.%6s", w1, w2, w3)) {
        fprintf(stderr,"Host must be of format xxx.xxx.xxxxxx\n");
        return 2;
    }

    p1 = (unsigned short *) quad;

    for (*p1 = 1; *p1 != 0; (*p1)++) {
        segment_hash(buf, 6, argv[1], key_len, quad, 2, 13);
        if (!strcmp(buf, w3)) 
            break;
    }
    
    p2 = quad+2;

    for (*p2 = 1; *p2 != 0; (*p2)++) {
        segment_hash(buf, 3, argv[1], key_len, quad, 3, 11);
        if (!strcmp(buf, w2)) 
            break;
    }

    p2++;

    for (*p2 = 1; *p2 != 0; (*p2)++) {
        segment_hash(buf, 3, argv[1], key_len, quad, 4, 10);
        if (!strcmp(buf, w1)) 
            break;
    }

    printf("%d.%d.%d.%d\n", quad[0], quad[1], quad[2], quad[3]);

    return 0;    
}
