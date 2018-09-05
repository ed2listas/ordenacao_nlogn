void ordena(double *lista, int tamanho) {
  int i, j;
  double aux;

  for (i = 0; i < tamanho; i++) {
    for (j = i+1; j < tamanho; j++) {
      if (lista[j] < lista[i]) {
        aux = lista[i];
        lista[i] = lista[j];
        lista[j] = aux;
      }
    }
  }
}

void comyVector(int *v1, int *v2, int size) {
  int i;
  for (i = 0; i < size; i++)
    v1[i] = v2[i];
}

void compararTempos(int size){
    int *vector_in = 0;
    int *vector_se = 0;
    int *vector_bu = 0;
    double *tempo = 0;
    tempo = (double *)malloc(3*sizeof(double));;
    double tempo_in , tempo_se, tempo_bu;

    vector_in = randomVector(vector_in, size);
    vector_se = (int *)malloc(size*sizeof(int));
    comyVector(vector_se, vector_in, size);
    vector_bu = (int *)malloc(size*sizeof(int));
    comyVector(vector_bu, vector_in, size);

    tempo_in = insertionSort(vector_in, size, 0, 0);
    tempo_se = selectionSort(vector_se, size, 0, 0);
    tempo_bu =  bubbleSort(vector_bu, size, 0 ,0);

    tempo[0] = tempo_in;
    tempo[1] = tempo_se;
    tempo[2] = tempo_bu;

    ordena(tempo,3);
    printf("Total de pontos: %d\n\n", size);
    for(int i = 0; i < 3; i++){
        if(tempo_in == tempo[i]){
            printf("%dº lugar Insertion Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
        else if(tempo_bu == tempo[i]){
            printf("%dº lugar Bubble Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
        else if(tempo_se == tempo[i]){
            printf("%dº lugar Selection Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
    }
    getch();
}
