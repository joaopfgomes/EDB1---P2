#include "codificacao.h"
#include <string.h>

#define CHAR_SET "abcdefghijklmnopqrstuvwxyz0123456789, .?:"
#define CHAR_SET_SIZE 40

// Função auxiliar para encontrar o índice de um caracter no conjunto permitido
int getIndex(char c) {
    const char *pos = strchr(CHAR_SET, c);
    return pos ? (int)(pos - CHAR_SET) : -1;
}

// Codifica uma mensagem
void codificaMensagem(const char *mensagemOriginal, char *mensagemCodificada, HashTable *hash) {
    int len = strlen(mensagemOriginal);

    for (int i = 0; i < len; i++) {
        char c = mensagemOriginal[i];
        int originalIndex = getIndex(c);

        if (originalIndex == -1) { // Caracter inválido
            mensagemCodificada[i] = c;
            continue;
        }

        int frequencia = buscaHash(hash, c);
        int novoIndex = (originalIndex + frequencia + (i + 1)) % CHAR_SET_SIZE;
        mensagemCodificada[i] = CHAR_SET[novoIndex];
    }

    mensagemCodificada[len] = '\0';
}

// Decodifica uma mensagem
void decodificaMensagem(const char *mensagemCodificada, char *mensagemDecodificada, HashTable *hash) {
    int len = strlen(mensagemCodificada);

    for (int i = 0; i < len; i++) {
        char c = mensagemCodificada[i];
        int novoIndex = getIndex(c);

        if (novoIndex == -1) { // Caracter inválido
            mensagemDecodificada[i] = c;
            continue;
        }

        int frequencia = buscaHash(hash, CHAR_SET[getIndex(mensagemDecodificada[i])]);
        int originalIndex = (novoIndex - frequencia - (i + 1) + CHAR_SET_SIZE) % CHAR_SET_SIZE;
        mensagemDecodificada[i] = CHAR_SET[originalIndex];
    }

    mensagemDecodificada[len] = '\0';
}
