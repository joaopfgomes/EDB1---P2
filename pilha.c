#include "pilha.h"
#include <string.h>

void inicializaPilha(Pilha *pilha) {
    pilha->top = -1;
}

bool push(Pilha *pilha, const char *mensagem) {
    if (pilha->top == MAX_MSG_LENGTH - 1) {
        return false; // Pilha cheia
    }
    pilha->top++;
    strcpy(pilha->messages[pilha->top], mensagem);
    return true;
}

bool pop(Pilha *pilha, char *mensagemRemovida) {
    if (pilha->top == -1) {
        return false; // Pilha vazia
    }
    strcpy(mensagemRemovida, pilha->messages[pilha->top]);
    pilha->top--;
    return true;
}

bool consultaTopo(Pilha *pilha, char *mensagemTopo) {
    if (pilha->top == -1) {
        return false; // Pilha vazia
    }
    strcpy(mensagemTopo, pilha->messages[pilha->top]);
    return true;
}
