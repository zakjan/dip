## Cipher Suites

ssl/tls1.h - TLS1_TXT_RSA_WITH_AES_128_GCM_SHA256, TLS1_CK_RSA_WITH_AES_128_GCM_SHA256 (suite names and codes)
ssl/s3_lib.c - ssl3_ciphers (suite definitions)
ssl/ssl_locl.h - SSL_AES128GCM, SSL_AEAD, ... (suite paramters)
ssl/ssl.h - SSL_CIPHER, ssl_cipher_st (suite definition)
ssl/ssl3_lib.c - ssl3_get_cipher_by_char
ssl/ssl_locl.h - IMPLEMENT_tls_meth_func

ssl/t1_srvr.c, ssl/t1_clnt.c
apps/s_server.c, apps/s_client.c

ssl/ssl_lib.c - SSL_CTX_new
ssl/ssl_ciph.c - SSL_ENC_AES128GCM_IDX
crypto/objects/obj_mac.h - SN_aes_128_gcm
crypto/evp/names.c - EVP_get_cipherbyname
crypto/objects/o_names.c - OBJ_NAME_get
crypto/evp/c_allc.c - OpenSSL_add_all_ciphers
crypto/evp/e_aes.c - aes_gcm_cipher, aes_gcm_tls_cipher, BLOCK_CIPHER_custom (EVP_aes_256_gcm !)
