static int caesar_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t in_length) {
  int ret = 0;
  unsigned long long out_length = 0;
  EVP_CAESAR_CTX *cipher_ctx = (EVP_CAESAR_CTX *)ctx->cipher_data;

  if (in_length > 0) {
    if (out == NULL) {
      caesar_set_ad(ctx, in, in_length);
    } else {
      // correct length for AEAD tag
      if (cipher_ctx->is_tls && ctx->encrypt) {
        in_length -= CRYPTO_ABYTES;
      }

      // message
      if (ctx->encrypt) {
        ret = caesar_encrypt(out, &out_length, in, in_length, cipher_ctx->ad, cipher_ctx->ad_length, cipher_ctx->nsec, cipher_ctx->npub, cipher_ctx->key);
      } else {
        ret = caesar_decrypt(out, &out_length, cipher_ctx->nsec, in, in_length, cipher_ctx->ad, cipher_ctx->ad_length, cipher_ctx->npub, cipher_ctx->key);
      }
    }
  }


  return ret == 0 ? (int)out_length : ret;
}
