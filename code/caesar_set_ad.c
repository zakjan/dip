static int caesar_set_ad(EVP_CIPHER_CTX *ctx, const unsigned char *in, size_t in_length) {
  EVP_CAESAR_CTX *cipher_ctx = (EVP_CAESAR_CTX *)ctx->cipher_data;

  if (cipher_ctx->ad) {
    free(cipher_ctx->ad);
  }

  cipher_ctx->ad = (unsigned char *)calloc(in_length, sizeof(unsigned char));
  cipher_ctx->ad_length = in_length;
  memcpy(cipher_ctx->ad, in, in_length);

  return 1;
}
