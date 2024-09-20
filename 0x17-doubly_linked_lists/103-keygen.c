#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

char generate_key_char(int index, const char *username) {
    unsigned long username_hash = hash(username);
    char key_char = ((username_hash ^ (index * 1337)) % 26) + 'A';
    return key_char;
}

void generate_key(const char *username, char *key) {
    int key_length = strlen(username) + 4;
    for (int i = 0; i < key_length; i++) {
        key[i] = generate_key_char(i, username);
    }
    key[key_length] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    char username[MAX_USERNAME_LENGTH];
    strncpy(username, argv[1], MAX_USERNAME_LENGTH - 1);
    username[MAX_USERNAME_LENGTH - 1] = '\0';

    char key[MAX_USERNAME_LENGTH + 5];
    generate_key(username, key);

    printf("%s\n", key);

    return 0;
}
