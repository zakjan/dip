typedef struct {
  unsigned char *key;
  unsigned char *nsec;
  unsigned char *npub;
  unsigned char *ad;
  size_t ad_length;
  int is_tls;
} EVP_CAESAR_CTX;

static int caesar_init(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);
static int caesar_set_ad(EVP_CIPHER_CTX *ctx, const unsigned char *in, size_t in_length);
static int caesar_encrypt(unsigned char *c, unsigned long long *clen, const unsigned char *m, unsigned long long mlen, const unsigned char *ad, unsigned long long adlen, const unsigned char *nsec, const unsigned char *npub, const unsigned char *k);
static int caesar_decrypt(unsigned char *m, unsigned long long *mlen, unsigned char *nsec, const unsigned char *c, unsigned long long clen, const unsigned char *ad, unsigned long long adlen, const unsigned char *npub, const unsigned char *k);
static int caesar_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t in_length);
static int caesar_cleanup(EVP_CIPHER_CTX *ctx);
static int caesar_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr);

static const EVP_CIPHER caesar = {
  NID_caesar,
  1,
  CRYPTO_KEYBYTES,
  CRYPTO_NPUBBYTES,
  EVP_CIPH_CUSTOM_IV | EVP_CIPH_FLAG_CUSTOM_CIPHER | EVP_CIPH_FLAG_AEAD_CIPHER,
  caesar_init,
  caesar_cipher,
  caesar_cleanup,
  sizeof(EVP_CAESAR_CTX),
  NULL,
  NULL,
  caesar_ctrl,
  NULL
};

const EVP_CIPHER *EVP_caesar(void) {
  return &caesar;
}
