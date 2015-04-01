struct evp_cipher_st {
  int nid;
  int block_size;
  int key_len;
  int iv_len;
  unsigned long flags;
  int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);
  int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t inl);
  int (*cleanup)(EVP_CIPHER_CTX *);
  int ctx_size;
  int (*set_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *);
  int (*get_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *);
  int (*ctrl)(EVP_CIPHER_CTX *, int type, int arg, void *ptr);
  void *app_data;
} EVP_CIPHER;
