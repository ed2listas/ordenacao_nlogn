#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

int gd = DETECT, gm, points = 100;

#include "includes.h"

// para compilar e executar o codigo
// gcc main.c -o saida.out -lgraph && ./saida.out

int main(int argc, char const *argv[])
{
  int option, showSteps = 0, animDelay=100;
  int *vector = NULL;
  double tempo;

  /*int tm = 10;
  int *vec = NULL;
  vec = randomVector(vector, tm);
  //int vec[10] = {164, 73, 45, 48, 301, 141, 187, 124, 200, 302};
  printf("\n\nLista antes:\n");
  printVector(vec, tm);
  radixSort(vec, tm, 0, 100);
  printf("\n\nLista depois:\n");
  printVector(vec, tm);
  printf("\n\n\nFIM\n");
  getch();*/
  do {
    option = menu();
    vector = randomVector(vector, points);
    limparTela();
    printf("Vetor desordenado:\n\n");
    printVector(vector, points);

    switch (option) {
      case 1: //radix sort
        showSteps = mostrarPassos();
        tempo = radixSort(vector, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o radix Sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\n\nVetor ordenado\n");
        printVector(vector, points);
        getch();
        break;
      case 2: //quick sort
        showSteps = mostrarPassos();
        tempo = quickSort(vector, 0, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o quick Sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\n\nVetor ordenado\n");
        printVector(vector, points);
        getch();
        break;
      case 3: //merge sort
        showSteps = mostrarPassos();
        tempo = mergeSort(vector, 0, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o merge Sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\n\nVetor ordenado\n");
        printVector(vector, points);
        getch();
        break;
      case 4: //Comparar os tres
        compararTempos(points);
        break;
      case 5: //Configuracoes
        configurations(&points, &animDelay);
        break;
      case 0: // sair
        printf("\nSaindo...\n");
        break;
      default:
        printf("\nOpcao invalida!!\n");
        getch();
    }
  } while(option);

   return 0;
}
