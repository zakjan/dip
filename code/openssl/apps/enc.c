int MAIN(int argc, char **argv) {
  ...
  /*
  if (cipher && EVP_CIPHER_flags(cipher) & EVP_CIPH_FLAG_AEAD_CIPHER) {
    BIO_printf(bio_err, "AEAD ciphers not supported by the enc utility\n");
    goto end;
  }
  */
  ...
}
