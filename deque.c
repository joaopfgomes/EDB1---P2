#include "deque.h"
#include <string.h>

void inicializaDeque(Deque *deque) {
    deque->front = 0;
    deque->rear = -1;
    deque->size = 0;
}

bool insereInicio(Deque *deque, const char *mensagem) {
    if (deque->size == MAX_DEQUE_LENGTH) {
        return false; // Deque cheio
    }
    deque->front = (deque->front - 1 + MAX_DEQUE_LENGTH) % MAX_DEQUE_LENGTH;
    strcpy(deque->messages[deque->front], mensagem);
    deque->size++;
    return true;
}

bool insereFim(Deque *deque, const char *mensagem) {
    if (deque->size == MAX_DEQUE_LENGTH) {
        return false; // Deque cheio
    }
    deque->rear = (deque->rear + 1) % MAX_DEQUE_LENGTH;
    strcpy(deque->messages[deque->rear], mensagem);
    deque->size++;
    return true;
}

bool removeInicio(Deque *deque, char *mensagemRemovida) {
    if (deque->size == 0) {
        return false; // Deque vazio
    }
    strcpy(mensagemRemovida, deque->messages[deque->front]);
    deque->front = (deque->front + 1) % MAX_DEQUE_LENGTH;
    deque->size--;
    return true;
}

bool removeFim(Deque *deque, char *mensagemRemovida) {
    if (deque->size == 0) {
        return false; // Deque vazio
    }
    strcpy(mensagemRemovida, deque->messages[deque->rear]);
    deque->rear = (deque->rear - 1 + MAX_DEQUE_LENGTH) % MAX_DEQUE_LENGTH;
    deque->size--;
    return true;
}
