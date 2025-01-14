#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "deque.h"
#include "hash.h"
#include "codificacao.h"

void menu() {
    printf("Menu:\n");
    printf("1. Inserir mensagem na pilha\n");
    printf("2. Codificar mensagem\n");
    printf("3. Decodificar mensagem\n");
    printf("4. Sair\n");
}

int main() {
    Pilha pilha;
    Deque deque;
    HashTable hash;
    unsigned char *mensagem = (unsigned char*) malloc(MAX_MSG_LENGTH * sizeof(unsigned char));  // Aloca memória para a mensagem
    unsigned char *mensagemCodificada = (unsigned char*) malloc(MAX_MSG_LENGTH * sizeof(unsigned char));  // Aloca memória para a mensagem codificada
    unsigned char *mensagemDecodificada = (unsigned char*) malloc(MAX_MSG_LENGTH * sizeof(unsigned char));  // Aloca memória para a mensagem decodificada
    int opcao;

    inicializaPilha(&pilha);
    inicializaDeque(&deque);
    inicializaHash(&hash);

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 1:
                printf("Digite a mensagem a ser inserida: ");
                fgets(mensagem, sizeof(mensagem), stdin);
                mensagem[strcspn(mensagem, "\n")] = '\0'; // Remove o '\n'
                if (push(&pilha, mensagem)) {
                    printf("Mensagem inserida com sucesso!\n");
                } else {
                    printf("Erro: Pilha cheia!\n");
                }
                break;
            case 2:
                if (consultaTopo(&pilha, mensagem)) {
                    limpaHash(&hash);
                    for (int i = 0; mensagem[i] != '\0'; i++) {
                        insereHash(&hash, mensagem[i]);
                    }
                    codificaMensagem(mensagem, mensagemCodificada, &hash);
                    if (insereFim(&deque, mensagemCodificada)) {
                        printf("Mensagem codificada: %s\n", mensagemCodificada);
                        pop(&pilha, mensagem);
                    } else {
                        printf("Erro: Deque cheio!\n");
                    }
                } else {
                    printf("Erro: Pilha vazia!\n");
                }
                break;
            case 3:
                if (removeInicio(&deque, mensagemCodificada)) {
                    limpaHash(&hash);
                    for (int i = 0; mensagemCodificada[i] != '\0'; i++) {
                        insereHash(&hash, mensagemCodificada[i]);
                    }
                    decodificaMensagem(mensagemCodificada, mensagemDecodificada, &hash);
                    printf("Mensagem decodificada: %s\n", mensagemDecodificada);
                } else {
                    printf("Erro: Deque vazio!\n");
                }
                break;
            case 4:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    free(mensagem);
    free(mensagemCodificada);
    free(mensagemDecodificada);

    return 0;
}
