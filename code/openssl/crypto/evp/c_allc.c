void OpenSSL_add_all_ciphers(void) {
  ...
  EVP_add_cipher(EVP_caesar());
}
