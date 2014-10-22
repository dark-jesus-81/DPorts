--- src/scrypt.h.orig	2014-08-24 15:09:34 UTC
+++ src/scrypt.h
@@ -29,19 +29,4 @@
 PBKDF2_SHA256(const uint8_t *passwd, size_t passwdlen, const uint8_t *salt,
     size_t saltlen, uint64_t c, uint8_t *buf, size_t dkLen);
 
-static inline uint32_t le32dec(const void *pp)
-{
-        const uint8_t *p = (uint8_t const *)pp;
-        return ((uint32_t)(p[0]) + ((uint32_t)(p[1]) << 8) +
-            ((uint32_t)(p[2]) << 16) + ((uint32_t)(p[3]) << 24));
-}
-
-static inline void le32enc(void *pp, uint32_t x)
-{
-        uint8_t *p = (uint8_t *)pp;
-        p[0] = x & 0xff;
-        p[1] = (x >> 8) & 0xff;
-        p[2] = (x >> 16) & 0xff;
-        p[3] = (x >> 24) & 0xff;
-}
 #endif
