#include "hash.h"

void inicializaHash(HashTable *hash) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash->table[i].occupied = false;
    }
}

void insereHash(HashTable *hash, char key) {
    int index = key % TABLE_SIZE;

    while (hash->table[index].occupied && hash->table[index].key != key) {
        index = (index + 1) % TABLE_SIZE; // Trata colisões com sondagem linear
    }

    if (!hash->table[index].occupied) {
        hash->table[index].key = key;
        hash->table[index].frequency = 1;
        hash->table[index].occupied = true;
    } else {
        hash->table[index].frequency++;
    }
}

int buscaHash(HashTable *hash, char key) {
    int index = key % TABLE_SIZE;

    while (hash->table[index].occupied) {
        if (hash->table[index].key == key) {
            return hash->table[index].frequency;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return 0; // Caracter não encontrado
}

void limpaHash(HashTable *hash) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash->table[i].occupied = false;
    }
}
