static int caesar_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc) {
  EVP_CAESAR_CTX *cipher_ctx = (EVP_CAESAR_CTX *)ctx->cipher_data;

  cipher_ctx->key = (unsigned char *)calloc(CRYPTO_KEYBYTES, sizeof(unsigned char));
  cipher_ctx->nsec = (unsigned char *)calloc(CRYPTO_NSECBYTES, sizeof(unsigned char));
  cipher_ctx->npub = (unsigned char *)calloc(CRYPTO_NPUBBYTES, sizeof(unsigned char));
  cipher_ctx->ad = (unsigned char *)calloc(1, sizeof(unsigned char));
  cipher_ctx->ad_length = 0;
  cipher_ctx->is_tls = 0;

  memcpy(cipher_ctx->key, key, CRYPTO_KEYBYTES);
  memcpy(cipher_ctx->npub, iv, CRYPTO_NPUBBYTES);

  return 1;
}
