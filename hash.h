#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

#define TABLE_SIZE 256

typedef struct {
    char key;       // Caracter
    int frequency;  // Frequência do caracter
    bool occupied;  // Marca se a posição está ocupada
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
} HashTable;

// Inicializa a tabela hash
void inicializaHash(HashTable *hash);

// Insere ou atualiza a frequência de um caracter na tabela
void insereHash(HashTable *hash, char key);

// Busca a frequência de um caracter na tabela
int buscaHash(HashTable *hash, char key);

// Limpa a tabela hash
void limpaHash(HashTable *hash);

#endif
