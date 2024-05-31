//Identificação de palíndromos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool ehPalindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (fim > inicio) {
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return false;
        }
        inicio++;
        fim--;
    }

    return true;
}

bool ehPreposicaoOuArtigo(char palavra[]) {
    const char *preposicoes[] = {"a", "ante", "apos", "ate", "com", "contra", "de", "desde", "em", "entre", "para", "perante", "por", "sem", "sob", "sobre", "trás"};
    const char *artigos[] = {"o", "a", "os", "as", "um", "uma", "uns", "umas"};
    int i;

for (i = 0; i < sizeof(preposicoes) / sizeof(preposicoes[0]); i++) {
        if (strcasecmp(palavra, preposicoes[i]) == 0) {
            return true;
        }
    }

    for (i = 0; i < sizeof(artigos) / sizeof(artigos[0]); i++) {
        if (strcasecmp(palavra, artigos[i]) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    char frase[1000];
    char palavra[100];
    int i, j = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

printf("Palavras palíndromos na frase: ");
    for (i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            
            palavra[j++] = frase[i];
        } else {
          printf("\nacho que espaço:%d\n", i);
          palavra[j] = '\0';
            if (!ehPreposicaoOuArtigo(palavra) && ehPalindromo(palavra)) {
                printf("%s ", palavra);
            }
            j = 0;
        }
    }

    palavra[j] = '\0';
    if (!ehPreposicaoOuArtigo(palavra) && ehPalindromo(palavra)) {
        printf("%s\n", palavra);
    }

    return 0;
}