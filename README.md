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


# Compilation

How to compile a program using AES-NI:
```bash
gcc aes-ni.c -o ./aes -maes
```


# Sources:

- Interesting White paper with code samples in C and assembly. Benchmark at the end. [Intel® Advanced Encryption Standard (AES) New Instructions Set by Shay Gueron](https://www.intel.com/content/dam/develop/external/us/en/documents/aes-wp-2012-09-22-v01-165683.pdf)

- [Intel® Advanced Encryption Standard Instructions (AES-NI)](https://www.intel.com/content/www/us/en/developer/articles/technical/advanced-encryption-standard-instructions-aes-ni.html)

- [Wikipedia - AES instruction set](https://en.wikipedia.org/wiki/AES_instruction_set)

- Tutorial for assembly -> [Assembly tutorial - AsmTutor](https://asmtutor.com/)