int crypto_aead_encrypt(
    unsigned char *c, unsigned long long *clen,
    const unsigned char *m, unsigned long long mlen,
    const unsigned char *ad, unsigned long long adlen,
    const unsigned char *nsec,
    const unsigned char *npub,
    const unsigned char *k
) {
    // the code for the cipher implementation goes here,
    // generating a ciphertext c[0],c[1],...,c[*clen-1]
    // from a plaintext m[0],m[1],...,m[mlen-1]
    // and associated data ad[0],ad[1],...,ad[adlen-1]
    // and secret message number nsec[0],nsec[1],...
    // and public message number npub[0],npub[1],...
    // and secret key k[0],k[1],...
    return 0;
}
