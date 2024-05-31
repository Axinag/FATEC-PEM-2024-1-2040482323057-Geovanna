//Praticando acesso a vetores

#include <stdio.h>

int main()
{
  float RL[4]={}, CGP[5]={}, LI[4]={}, AG[6]={}, JS[5]={};
  int x, soma, Nota_RL=0, Nota_CGP=0, Nota_LI=0, Nota_AG=0, Nota_JS=0;

  for(x=0; x<4; x++){
    printf("Informe a nota de RL:\n");
    scanf("%f", &RL[x]);
    Nota_RL += RL[x]; 
  }
  for(x=0; x<5; x++){
    printf("Informe a nota de CGP:\n");
    scanf("%f", &CGP[x]);
    Nota_CGP += CGP[x];
  }
  for(x=0; x<4; x++){
    printf("Informe a nota de LI:\n");
    scanf("%f", &LI[x]);
    Nota_LI += LI[x];
  }
  for(x=0; x<6; x++){
    printf("Informe a nota de AG:\n");
    scanf("%f", &AG[x]);
    Nota_AG += AG[x];
  }
  for(x=0; x<5; x++){
    printf("Informe a nota de JS:\n");
    scanf("%f", &JS[x]);
    Nota_JS += JS[x];
  }

  printf("Nota Raciocinio logico = %d\n", Nota_RL);
  printf("Nota Conceitos de gerenciamento de projetos = %d", Nota_CGP);
  printf("Nota Lingua inglesa = %d\n", Nota_LI);
  printf("Nota Conceitos de metodologia agil = %d\n", Nota_AG);
  printf("Nota Javascript = %d\n", Nota_JS);

  return 0;
}