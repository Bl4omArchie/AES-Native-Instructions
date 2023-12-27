# Implementing AES with Native Instructions (AES-NI)


AES is one of the most famous cipher block in the world. In real life software, you won't find AES code calling a SubBytes function, then a ShiftRows() function, and then a MixColumns() function because that would be inefficient. Instead, fast AES software uses special techniques called table-based implementations and native instructions.

Here we focused on native instructions (NI) which use dedicated assembly instructions within you processor to compute directly AES operations.




# Instructions

This is a listing of every instructions: 

| Instruction | 	Description |
|:--:         | :--:            |
| aesenc 	  | Perform one round of an AES encryption flow |
| aesenclast  |	Perform the last round of an AES encryption flow |
| aesdec 	  | Perform one round of an AES decryption flow |
| aesdeclast  |	Perform the last round of an AES decryption flow |
| aeskeygenassist | Assist in AES round key generation |
| aesimc 	      | Assist in AES decryption round key generation. Applies Inverse Mix Columns to round keys. |

Find all the supported architectures here: [link](https://en.wikipedia.org/wiki/AES_instruction_set#Supporting_x86_CPUs)

# Example program

In this sample, we implement the encrypting function. 

```assembly
section .text
global aes_encrypt, aes_decrypt

aes_encrypt:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pxor xmm0, xmm1

    aeskeygenassist xmm1, xmm1, 0x01
    aesenc xmm0, xmm1

    aeskeygenassist xmm1, xmm1, 0x01
    aesenc xmm0, xmm1

    aeskeygenassist xmm1, xmm1, 0x01
    aesenclast xmm0, xmm1

    movdqu [rdx], xmm0
    ret
```

# Sources:

- [Intel® Advanced Encryption Standard Instructions (AES-NI)](https://www.intel.com/content/www/us/en/developer/articles/technical/advanced-encryption-standard-instructions-aes-ni.html)

- [Wikipedia - AES instruction set](https://en.wikipedia.org/wiki/AES_instruction_set)

- [Assembly tutorial - AsmTutor](https://asmtutor.com/)