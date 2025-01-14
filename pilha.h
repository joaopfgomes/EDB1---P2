#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Define o tamanho máximo das mensagens
#define MAX_MSG_LENGTH 1000000

typedef struct {
    char messages[MAX_MSG_LENGTH][MAX_MSG_LENGTH];
    int top;
} Pilha;

// Inicializa a pilha
void inicializaPilha(Pilha *pilha);

// Insere uma mensagem na pilha
bool push(Pilha *pilha, const char *mensagem);

// Remove a mensagem do topo
bool pop(Pilha *pilha, char *mensagemRemovida);

// Consulta o topo da pilha
bool consultaTopo(Pilha *pilha, char *mensagemTopo);

#endif
