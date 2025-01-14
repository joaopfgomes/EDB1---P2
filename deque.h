#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

// Define o tamanho máximo do deque
#define MAX_DEQUE_LENGTH 1000
#define MAX_MSG_LENGTH 1000000

typedef struct {
    unsigned char messages[MAX_DEQUE_LENGTH][MAX_MSG_LENGTH];
    int front, rear, size;
} Deque;

// Inicializa o deque
void inicializaDeque(Deque *deque);

// Insere uma mensagem no início
bool insereInicio(Deque *deque, const char *mensagem);

// Insere uma mensagem no fim
bool insereFim(Deque *deque, const char *mensagem);

// Remove uma mensagem do início
bool removeInicio(Deque *deque, char *mensagemRemovida);

// Remove uma mensagem do fim
bool removeFim(Deque *deque, char *mensagemRemovida);

#endif
