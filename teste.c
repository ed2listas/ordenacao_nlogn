#include <stdio.h>
//#include <graphics.h>
//#include <X11/Xlib.h>

//#include "plotGraph.h"
#include "pausar.h"
#include "troca.h"
//#include "limparTela.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "printVector.h"

#define TAM 10

int main()
{
  int v[10] = {2,8,4,6,5,10,7,9,3,1};
  //int v[10] = {3,1,2};
  printVector(v, TAM);
  bubbleSort(v, TAM); // trocar nome da função
  printVector(v, TAM);


   return 0;
}
