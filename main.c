#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *create_node(int value);
void show(const Node *stack);
int push(Node **stack, int value);
int pop(Node **stack, int *value);
int peek(const Node *stack, int *value);
int is_empty(const Node *stack);
void clear(Node **stack);


int main() {
    Node *stack = NULL;
    int value;
    int result;

    printf("Verificando pilha vazia\n");
    printf("Pilha vazia? %s\n", is_empty(stack) ? "Sim" : "Nao");
    show(stack);

    printf("\nPeek em pilha vazia\n");
    result = peek(stack, &value);
    if (result)
        printf("Topo: %d\n", value);
    else
        printf("Erro: pilha vazia!\n");

    printf("\nPop em pilha vazia\n");

    result = pop(&stack, &value);
    if (result)
        printf("Elemento removido: %d\n", value);
    else
        printf("Erro: pilha vazia!\n");

    printf("\nInserindo elementos\n");

    int values[] = {10, 20, 30, 40, 50};
    int n = 5;

    for (int i = 0; i < n; i++) {
        if (push(&stack, values[i]))
            printf("Inserido: %d\n", values[i]);
        else
            printf("Erro ao inserir: %d\n", values[i]);
    }

    printf("\nEstado da pilha:\n");
    show(stack);

    printf("\nVerificando estado da pilha\n");

    printf("Pilha vazia? %s\n", is_empty(stack) ? "Sim" : "Nao");

    printf("\nFazendo Peek\n");
    result = peek(stack, &value);

    if (result)
        printf("Topo: %d\n", value);
    else
        printf("Erro ao consultar topo!\n");

    printf("Pilha apos Peek:\n");
    show(stack);

    printf("\nFazendo Pop\n");

    for (int i = 0; i < 3; i++) {
        result = pop(&stack, &value);

        if (result)
            printf("Removido: %d\n", value);
        else
            printf("Erro ao remover!\n");
    }

    printf("\nEstado da pilha:\n");
    show(stack);

    printf("\nInserindo novos elementos\n");

    push(&stack, 100);
    push(&stack, 200);

    show(stack);

    printf("\nLimpando pilha (Clear)\n");

    clear(&stack);

    printf("Estado apos Clear:\n");
    show(stack);

    printf("Pilha vazia? %s\n", is_empty(stack) ? "Sim" : "Nao");

    printf("\nClear em pilha vazia\n");

    clear(&stack);

    return 0;
}


Node *create_node(int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return NULL;

    node->value = value;
    node->next = NULL;
    
    return node;
}

void show(const Node *stack) {
    const Node *aux = stack;

    while (aux != NULL) {
        printf("%d -> ", aux->value);
        aux = aux->next;
    }
    puts("NULL");
}

int push(Node **stack, int value) {
    Node* node = create_node(value);
    if (node == NULL) return 0;

    node->next = *stack;
    *stack = node;

    return 1;
}

int pop(Node **stack, int *value) {
    Node *node = *stack;
    if (node == NULL) return 0;

    *stack = node->next;
    *value = node->value;

    free(node);

    return 1;
}

int peek(const Node *stack, int *value) {
    if (stack == NULL) return 0;

    *value = stack->value;

    return 1;
}

int is_empty(const Node *stack) {
    return stack == NULL;
}

void clear(Node **stack) {
    Node *aux = *stack;
    
    while (aux != NULL) {
        Node *next = aux->next;
        free(aux);
        aux = next;
    }

    *stack = NULL;
}
