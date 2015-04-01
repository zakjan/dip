int decrypt(
    unsigned char *ciphertext, int ciphertext_length,
    unsigned char *aad, int aad_length,
    unsigned char *tag,
    unsigned char *key,
    unsigned char *iv,
    unsigned char *plaintext
) {
    EVP_CIPHER *cipher;
    EVP_CIPHER_CTX *ctx;
    int length;
    int plaintext_length;
    int ret;

    // get the cipher handle
    cipher = EVP_aes_128_gcm();

    // initialize the cipher context
    ctx = EVP_CIPHER_CTX_new();

    // initialize the decryption operation
    // the key and IV length should be appropriate for the chosen cipher
    EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv);

    // provide the expected MAC tag value
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, tag);

    // provide the AAD data to be verified
    // this can be called zero or more times as required
    EVP_DecryptUpdate(ctx, NULL, &length, aad, aad_length);

    // provide the ciphertext to be decrypted and verified, and receive the plaintext
    // this can be called multiple times as required
    EVP_DecryptUpdate(ctx, plaintext, &length, ciphertext, ciphertext_length);
    plaintext_length = length;

    // finalize the decryption operation
    // further plaintext bytes may be received
    ret = EVP_DecryptFinal_ex(ctx, plaintext + plaintext_length, &length);
    plaintext_length += length;

    // cleanup the cipher context
    EVP_CIPHER_CTX_free(ctx);

    if (ret > 0) {
        // decryption successful
        return plaintext_length;
    } else {
        // decryption failed
        return -1;
    }
}
