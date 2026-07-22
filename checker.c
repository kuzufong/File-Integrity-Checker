#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

// Reads the file at `path`, computes its SHA-256 digest,
// and writes 32 raw bytes into `digest_out`.
// Returns 1 on success, 0 on failure.
int hash_file(const char *path, unsigned char *digest_out) {
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        perror("fopen");
        return 0;
    }

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // read in chunk of BUFFER_SIZE and stop when there is 0 byte.
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) != 0) {
        EVP_DigestUpdate(ctx, buffer, bytes_read);
    }

    unsigned int digest_len;
    EVP_DigestFinal_ex(ctx, digest_out, &digest_len);

    EVP_MD_CTX_free(ctx);
    fclose(fp);
    return 1;
}

void print_hex(const unsigned char *digest, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        printf("%02x", digest[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    unsigned char digest[EVP_MAX_MD_SIZE];
    if (!hash_file(argv[1], digest)) {
        return 1;
    }

    print_hex(digest, 32);
    printf("  %s\n", argv[1]);
    return 0;
}