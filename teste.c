#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

int gd = DETECT, gm;

#include "includes.h"

#define TAM 10

int main()
{
  //int v[10] = {2,8,4,6,5,10,7,9,3,1};
  int *v = randomVector(v,99);
  //int v[10] = {3,1,2};
  printVector(v, 99);
  //bubbleSort(v, TAM); // trocar nome da função
  radixSort(v, 99, 1, 100);
  printVector(v, 99);


   return 0;
}
