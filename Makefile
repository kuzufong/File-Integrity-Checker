CC = clang
OPENSSL_PREFIX = $(shell brew --prefix openssl@3)
CFLAGS = -Wall -Wextra -g -I$(OPENSSL_PREFIX)/include
LDFLAGS = -L$(OPENSSL_PREFIX)/lib -lssl -lcrypto

checker: checker.c
	$(CC) $(CFLAGS) -o checker checker.c $(LDFLAGS)

clean:
	rm -f checker