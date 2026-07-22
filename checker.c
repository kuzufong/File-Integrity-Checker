#include <openssl/evp.h>
#include <stdio.h>

int main(void) {
    printf("EVP_sha256 pointer: %p\n", (void *)EVP_sha256());
    return 0;
}