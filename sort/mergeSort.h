#include <math.h>
void mergeFinal(int *lista,int inicio,int meio,int fim, int mostrarPassos, int sleep){
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim - inicio + 1; // definindo tamanho do atual
  p1 = inicio; // ponto1 incial
  p2 = meio + 1;  // ponto 2 final
  temp = (int *) malloc(tamanho*sizeof(int)); // combina num terceiro vetor

  if(temp != NULL){
    for( i = 0; i < tamanho; i++){
      if(!fim1 && !fim2){
        if(lista[p1] < lista[p2]){
          temp[i] = lista[p1];
          p1++;    //verifica quem eh o menor dos dois e coloca na temp
        }
        else{
          temp[i] = lista[p2];
          p2++;
        }
        if(p1 > meio) fim1 =1; // se o vetor acabou seta como verdadeiro
        if(p2 > fim) fim2 = 1;
      }
      else{
        if(!fim1)
          temp[i] = lista[p1++]; // copia o que sobra
        else
          temp[i] = lista[p2++];
      }
      //if (mostrarPassos) plotGraph(lista, points, "Merge Sort", sleep);
    }

    for(j = 0, k = inicio; j < tamanho; j++, k++) //copia os dados do tempo e passa para o lista
      lista[k] = temp[j];
    if (mostrarPassos) plotGraph(lista, points, "Merge Sort", sleep);
  }
  free(temp);
}

void merge_sort(int *lista, int inicio, int fim, int mostrarPassos, int sleep){
  int meio;
  if(inicio < fim){
    meio = floor((inicio + fim)/2);
    //printf("meios: %d: %d\n",meio, lista[meio]);
    if (mostrarPassos) plotGraph(lista, points, "Merge Sort", sleep);
    merge_sort(lista, inicio, meio, mostrarPassos, sleep);
    merge_sort(lista,meio+1, fim, mostrarPassos, sleep);
    mergeFinal(lista, inicio, meio, fim, mostrarPassos, sleep);
  }
  //print_vetor(lista);
}

double mergeSort(int *lista, int inicio, int fim, int mostrarPassos, int sleep) {
  double time_spent;
  if(mostrarPassos) initgraph(&gd,&gm,NULL);

  clock_t begin = clock();
  merge_sort(lista, 0, fim-1, mostrarPassos, sleep);
  clock_t end = clock();

  if(mostrarPassos) {
    delay(2000);
    closegraph();
    limparTela();
  }
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  return time_spent;
}
