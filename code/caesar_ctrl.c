static int caesar_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr) {
  EVP_CAESAR_CTX *cipher_ctx = (EVP_CAESAR_CTX *)ctx->cipher_data;

  switch (type) {
    case EVP_CTRL_AEAD_TLS1_AAD: ; // empty statement
      int in_length = arg;
      unsigned char *in = (unsigned char *)ptr;

      cipher_ctx->is_tls = 1;

      if (!ctx->encrypt) {
        // correct length for AEAD tag
        // @see e_aes.c
        unsigned int len = in[in_length - 2] << 8 | in[in_length - 1];
        len -= CRYPTO_ABYTES;

        in[in_length - 2] = len >> 8;
        in[in_length - 1] = len & 0xff;
      }

      caesar_set_ad(ctx, in, in_length);
      return CRYPTO_ABYTES; // AEAD tag length
    default:
      return -1;
  }
}
