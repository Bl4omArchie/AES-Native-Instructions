#include <wmmintrin.h>
#include <stdio.h>
#include "src/include.h"

void aes_encrypt(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext) {
    __m128i block = _mm_loadu_si128((__m128i*)plaintext);
    __m128i round_key = _mm_loadu_si128((__m128i*)key);

    block = _mm_xor_si128(block, round_key);

    for (int i = 0; i < 9; ++i) {
        round_key = _mm_aeskeygenassist_si128(round_key, 0x01);
        block = _mm_aesenc_si128(block, round_key);
    }

    round_key = _mm_aeskeygenassist_si128(round_key, 0x01);
    block = _mm_aesenclast_si128(block, round_key);

    _mm_storeu_si128((__m128i*)ciphertext, block);
}


int main() {
    const unsigned char plaintext[16] = "Hello, AES-NI!";
    const unsigned char key[16] = "0123456789ABCDEF";
    unsigned char ciphertext[16];

    // Appel de la fonction assembleur aes_encrypt
    aes_encrypt(plaintext, key, ciphertext);

    printf ("%s", ciphertext);


    return 0;
}