section .text
global aes_encrypt, aes_decrypt

aes_encrypt:
    ; Load plaintext into xmm0
    movdqu xmm0, [rdi]

    ; Load round key into xmm1
    movdqu xmm1, [rsi]

    ; Initial XOR with round key
    pxor xmm0, xmm1

    ; AES Rounds
    ; Round 1
    aeskeygenassist xmm1, xmm1, 0x01
    aesenc xmm0, xmm1

    ; Round 2
    aeskeygenassist xmm1, xmm1, 0x01
    aesenc xmm0, xmm1

    ; ... Repeat for rounds 3 to 8 ...

    ; Final Round
    aeskeygenassist xmm1, xmm1, 0x01
    aesenclast xmm0, xmm1

    ; Store the result in ciphertext
    movdqu [rdx], xmm0

    ret

aes_decrypt:
    ; Load ciphertext into xmm0
    movdqu xmm0, [rdi]

    ; Store the result in plaintext
    movdqu [rdx], xmm0
    ret