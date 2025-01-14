#ifndef CODIFICACAO_H
#define CODIFICACAO_H

#include "hash.h"

// Codifica uma mensagem
void codificaMensagem(const char *mensagemOriginal, char *mensagemCodificada, HashTable *hash);

// Decodifica uma mensagem
void decodificaMensagem(const char *mensagemCodificada, char *mensagemDecodificada, HashTable *hash);

#endif
