static int caesar_encrypt(unsigned char *c, unsigned long long *clen, const unsigned char *m, unsigned long long mlen, const unsigned char *ad, unsigned long long adlen, const unsigned char *nsec, const unsigned char *npub, const unsigned char *k) {
  int ret = crypto_aead_encrypt(c, clen, m, mlen, ad, adlen, nsec, npub, k); // CAESAR API

  return ret;
}
