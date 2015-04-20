int encrypt(
    unsigned char *plaintext, int plaintext_length,
    unsigned char *aad, int aad_length,
    unsigned char *key,
    unsigned char *iv,
    unsigned char *ciphertext,
    unsigned char *tag
) {
    EVP_CIPHER *cipher;
    EVP_CIPHER_CTX *ctx;
    int length;
    int ciphertext_length;

    // get the cipher handle
    cipher = EVP_aes_128_gcm();

    // initialize the cipher context
    ctx = EVP_CIPHER_CTX_new();

    // initialize the encryption operation
    // the key and IV length should be appropriate for the chosen cipher
    EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv);

    // provide the AAD data to be authenticated
    // this can be called zero or more times as required
    EVP_EncryptUpdate(ctx, NULL, &length, aad, aad_length);

    // provide the plaintext to be encrypted and authenticated, and receive the ciphertext
    // this can be called multiple times as required
    EVP_EncryptUpdate(ctx, ciphertext, &length, plaintext, plaintext_length);
    ciphertext_length = length;

    // finalize the encryption operation
    // further ciphertext bytes may be received
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &length);
    ciphertext_length += length;

    // receive the MAC tag
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag);

    // cleanup the cipher context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_length;
}
