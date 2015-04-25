static int caesar_cleanup(EVP_CIPHER_CTX *ctx) {
  EVP_CAESAR_CTX *cipher_ctx = (EVP_CAESAR_CTX *)ctx->cipher_data;

  free(cipher_ctx->key);
  free(cipher_ctx->nsec);
  free(cipher_ctx->npub);
  free(cipher_ctx->ad);

  return 1;
}
