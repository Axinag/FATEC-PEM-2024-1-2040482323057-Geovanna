// Struct Bubble Sort

#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    double nota;
} Aluno;

void incluirAluno(Aluno alunos[], int *numAlunos) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Esse é o número máximo de alunos!.\n");
        return;
    }
    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n]", alunos[*numAlunos].nome); 
    printf("Digite a nota do aluno: \n");
    scanf("%lf", &alunos[*numAlunos].nota);
    (*numAlunos)++;
}

void listarAlunos(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = 0; j < numAlunos - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

    printf("\nLista de Alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Nota: %.2lf\n", alunos[i].nota);
        printf("Situação: %s\n\n", alunos[i].nota >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

void exibirMenu() {
    printf("BEM-VINDO AO GERENCIADOR DO PROFESSOR: \n Menu:\n");
    printf("1. Incluir alunos\n");
    printf("2. Listar alunos\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");

    return 0;
}