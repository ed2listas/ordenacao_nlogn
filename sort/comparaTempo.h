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
    int *vector_mer = 0;
    int *vector_qui = 0;
    int *vector_ra = 0;
    double *tempo = 0;
    tempo = (double *)malloc(3*sizeof(double));;
    double tempo_mer , tempo_qui, tempo_ra;

    vector_mer = randomVector(vector_mer, size);
    vector_qui = (int *)malloc(size*sizeof(int));
    comyVector(vector_qui, vector_mer, size);
    vector_ra = (int *)malloc(size*sizeof(int));
    comyVector(vector_ra, vector_mer, size);

    tempo_mer = mergeSort(vector_mer,0, size, 0, 0);
    tempo_qui = quickSort(vector_qui,0, size, 0, 0);
    tempo_ra =  radixSort(vector_ra, size, 0 ,0);

    tempo[0] = tempo_mer;
    tempo[1] = tempo_qui;
    tempo[2] = tempo_ra;

    ordena(tempo,3);
    printf("Total de pontos: %d\n\n", size);
    for(int i = 0; i < 3; i++){
        if(tempo_mer == tempo[i]){
            printf("%dº lugar Merge Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
        else if(tempo_ra == tempo[i]){
            printf("%dº lugar Radix Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
        else if(tempo_qui == tempo[i]){
            printf("%dº lugar Quick Sort com: %lf segundos\n",i + 1, tempo[i]);
        }
    }
    getch();
}
