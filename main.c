#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

int gd = DETECT, gm;

#include "includes.h"

// para compilar e executar o codigo
// gcc main.c -o saida.out -lgraph && ./saida.out

int main(int argc, char const *argv[])
{
  int option, points = 99, showSteps = 0, animDelay=100;
  int *vector = NULL;
  double tempo;

  do {
    option = menu();
    vector = randomVector(vector, points);
    limparTela();
    printf("Vetor desordenado:\n\n");
    printVector(vector, points);

    switch (option) {
      case 1: //bubble sort
        showSteps = mostrarPassos();
        tempo = bubbleSort(vector, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o bubble sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\n\nVetor ordenado\n");
        printVector(vector, points);
        getch();
        break;
      case 2: //insertion sort
        showSteps = mostrarPassos();
        tempo = insertionSort(vector, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o insertion Sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\nVetor ordenado:\n\n");
        printVector(vector, points);
        getch();
        break;
      case 3: //selection sort
        showSteps = mostrarPassos();
        tempo = selectionSort(vector, points, showSteps, animDelay);
        limparTela();
        printf("tempo que o que o selection Sort demorou para ordenar %d valores: %lf\n segundos", points, tempo);
        printf("\nVetor ordenado:\n\n");
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
