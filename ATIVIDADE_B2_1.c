//Implementar Modularização - Calculadora

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERAND_LENGTH 10

float soma(float a, float b){
    return a+b;
}
float subtracao(float a, float b){
    return a-b;
}
float multiplicacao(float a, float b){
    return a*b;
}
float divisao(float a, float b){
    if(b!=0)
        return a/b
    else{
        printf("Erro: Divisão por zero.");
        return 0;
    }
}

int main(){
    char operacao;
    float operandos[2];
    float resultado;

    printf("Calculadora\n");
    printf("Operações disponíveis: Soma(+), Subtração(-), Multiplicação(*), Divisão(/) \n");
    printf("Digite 'S' a qualquer momento para sair.\n");

    while(1){
        printf(Digite o simbolo da operação desejada:\n);
        scanf("%c", &operacao);
        if(operacao == 'S' || operacao == 's'){
            printf("Você saiu da calculadora.\n");
            break;
        }
        printf("Digite dois números:\n");
        scanf("%f %f", &operandos[0], &operandos[1]);

        switch(operacao){
            case '+':
                resultado = soma(operandos[0],operandos[1]);
                break;
            case '-':
                resultado = subtracao(operandos[0],operandos[1]);
                break;
            case '*':
                resultado = multiplicacao(operandos[0],operandos[1]);
                break;
            case '/':
                resultado = divisao(operandos[0],operandos[1]);
                break;
            default:
                printf("Operação inválida! Tente novamente.\n");
                continue;
        }
        printf("Resultado: %.2f\n\n", resultado);
    }

    return 0;
}