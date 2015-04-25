static int caesar_decrypt(unsigned char *m, unsigned long long *mlen, unsigned char *nsec, const unsigned char *c, unsigned long long clen, const unsigned char *ad, unsigned long long adlen, const unsigned char *npub, const unsigned char *k) {
  int ret = crypto_aead_decrypt(m, mlen, nsec, c, clen, ad, adlen, npub, k); // @see CAESAR API

  return ret;
}
