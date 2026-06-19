#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sobel(int width, int height, unsigned char *input, unsigned char *output);

#define ASSERT(cond, msg) \
    if (!(cond)) { \
        printf("FAIL: %s\n", msg); \
        return 1; \
    }

int main() {
    int width = 4;
    int height = 4;

    unsigned char input[16] = {
        0, 0, 255, 255,
        0, 0, 255, 255,
        0, 0, 255, 255,
        0, 0, 255, 255
    };

    unsigned char output[16];
    memset(output, 0, sizeof(output));

    sobel(width, height, input, output);

    // Vérifie qu'on détecte bien des bords
    int found = 0;
    for (int i = 0; i < 16; i++) {
        if (output[i] > 0) found = 1;
    }

    ASSERT(found == 1, "Sobel did not detect edges");

    printf("PASS: sobel unit test\n");
    return 0;
}
