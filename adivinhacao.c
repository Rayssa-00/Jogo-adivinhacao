#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  setlocale(LC_ALL, "");

  // imprime cabecalho do jogo
  printf("******************************************\n");
  printf("* Bem-vindo ao nosso jogo de adivinha��o *\n");
  printf("[] ,----.___ \n");
  printf(" __||_/___ '.\n");
  printf("/ O|| /| )   \n");
  printf("/ "" / / =._/\n");
  printf("/________/ / \n");
  printf("|________|/  \n");
  printf("******************************************\n\n");

  

  int segundos = time(0);
  srand(segundos);

  int numeroaleatorio = rand();

  int numerosecreto = numeroaleatorio % 100;

  int chute;
  int tentativas;
  double pontos = 1000;
  int acertou = 0;

  int nivel;
  printf("Selecione o nivel de dificuldade:\n");
  printf("(1)F�cil (2)M�dio (3)Dif�cil \n\n");
  printf("Escolha: ");
  scanf("%d", &nivel);

  switch(nivel){
    case 1:
      tentativas = 20;
      break;

    case 2:
      tentativas = 15;
      break;

    default:
      tentativas = 5;
      break;
  }

  for(int i = 0; i <= tentativas; i++)
  {

    printf("Tentativa %d de %d\n", i + 1, tentativas);
    printf("Qual � o seu chute?\n");

    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

    if (chute < 0)
    {
      printf("Voc� n�o pode chutar n�meros negativos!\n");
      i--;
      continue;
    }

    acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;

    if (acertou)
    {
      break;
    }

    else if (maior)
    {
      printf("Seu chute foi maior que o n�mero secreto\n");
    }
    else
    {
      printf("Seu chute foi menor que o n�mero secreto\n");
    }

    double pontosperdidos = abs(chute - numerosecreto) / 2.0;
    pontos = pontos - pontosperdidos;
  }

  printf("Fim de jogo!\n");

  if (acertou)
  {
    printf("Parab�ns! Voc� acertou!\n");
    printf("N�meros de tentativas:%d\n", tentativas);
    printf("Total de pontos: %.2f\n", pontos);
  }
  else
  {
    printf("       \\|/ ____ \\|/    \n");   
    printf("        @~/ ,. \\~@      \n");   
    printf("       /_( \\__/ )_\\    \n");   
    printf("          \\__U_/        \n");
    printf("Voc� perdeu!! Tente novamente");
  }
}