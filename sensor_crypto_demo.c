#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random 256-bit key
void generateRandomKey(unsigned char *key, size_t key_len) {
    for (size_t i = 0; i < key_len; ++i) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message
void encryptMessage(const unsigned char *message, size_t message_len,
                    const unsigned char *key, unsigned char *ciphertext) {
    for (size_t i = 0; i < message_len; ++i) {
        ciphertext[i] = message[i] ^ key[i % 32];
    }
}

// Function to decrypt a message
void decryptMessage(const unsigned char *ciphertext, size_t ciphertext_len,
                    const unsigned char *key, unsigned char *decrypted_message) {
    for (size_t i = 0; i < ciphertext_len; ++i) {
        decrypted_message[i] = ciphertext[i] ^ key[i % 32];
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed random

    unsigned char key[32]; // 256-bit key
    generateRandomKey(key, sizeof(key));

    const char *original_message = "Sensor123: Temperature=25.5";
    size_t message_len = strlen(original_message);

    unsigned char ciphertext[256];        // Adjust size as needed
    unsigned char decrypted_message[256]; // Adjust size as needed

    encryptMessage((const unsigned char *)original_message, message_len, key, ciphertext);
    decryptMessage(ciphertext, message_len, key, decrypted_message);

    printf("\n===== Secure Sensor Data Encryption Demo =====\n\n");
    printf("Original Message: %s\n\n", original_message);

    printf("Generated 256-bit Key: ");
    for (size_t i = 0; i < sizeof(key); ++i)
        printf("%02X ", key[i]);
    printf("\n\n");

    printf("Encrypted Message (Hex): ");
    for (size_t i = 0; i < message_len; i++)
        printf("%02X ", ciphertext[i]);
    printf("\n\n");

    printf("Decrypted Message: %s\n", decrypted_message);
    printf("\n===============================================\n");

    return 0;
}
