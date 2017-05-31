#ifndef BASE64_H
#define BASE64_H
#include <stddef.h>
#include <stdint.h>


int nn_base64_decode (const char *in, size_t in_len,
    uint8_t *out, size_t out_len);
int nn_base64_encode (const uint8_t *in, size_t in_len,
    char *out, size_t out_len);

#endif // BASE64_H
