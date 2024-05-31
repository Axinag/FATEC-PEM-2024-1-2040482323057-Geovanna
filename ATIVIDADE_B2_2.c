// Implementação e apresentação da Calculadora HP12c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    double items[STACK_SIZE];
    int top;
} Stack;

Stack initStack() {
    Stack stack;
    stack.top = -1; 
    return stack;
}

int vazia(Stack stack) {
    return stack.top == -1;
}

int cheia(Stack stack) {
    return stack.top == STACK_SIZE - 1;
}

Stack push(Stack stack, double valor) {
    if (cheia(stack)) {
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
    stack.top++;
    stack.items[stack.top] = valor;
    return stack;
}

double pop(Stack *stack) {
    if (vazia(*stack)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    double valor = stack->items[stack->top];
    stack->top--;
    return valor;
}

int main() {
    Stack stack = initStack();
    char expressao[100];

    printf("Bem vindo ao simulador Calculadora HP12C\n");
    printf("Entre com a operação RPN\n");
    printf("Operadores válidos: + - * /\n");
    printf("Digite s para sair.\n");

    while (1) {
        printf("Pilha: ");
        for (int i = 0; i <= stack.top; i++) {
            printf("%.2f ", stack.items[i]);
        }
        printf("\n");

        printf("Digite um valor ou operador: ");
        if (scanf("%s", expressao) != 1) {
            printf("Erro de entrada.\n");
            exit(1);
        }

        if (expressao[0] == 's') {
            break;
        } 

        char *endptr;
        double value = strtod(expressao, &endptr);
        if (*endptr == '\0') {
            stack = push(stack, value);
        } else {
            char op = expressao[0];
            if (op != '+' && op != '-' && op != '*' && op != '/') {
                printf("Operador inválido.\n");
                continue;
            }
            
            if (vazia(stack)) {
                printf("Erro: Pilha vazia!\n");
                continue;
            }
            double b = pop(&stack);

            if (vazia(stack)) {
                printf("Erro: Pilha vazia!\n");
                continue;
            }
            double a = pop(&stack);

            double resultado;
            switch (op) {
                case '+':
                    resultado = a + b;
                    break;
                case '-':
                    resultado = a - b;
                    break;
                case '*':
                    resultado = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf("Erro: Divisão por zero.\n");
                        continue;
                    }
                    resultado = a / b;
                    break;
                default:
                printf("Operador inválido.\n");
                    continue; 
                    break;
            }
            stack = push(stack, resultado);
        }
    }

    if (vazia(stack)) {
        printf("Resultado: Pilha vazia.).\n");
    } else {
        printf("Resultado final: %.2f\n", pop(&stack));
    }

    return 0;
}