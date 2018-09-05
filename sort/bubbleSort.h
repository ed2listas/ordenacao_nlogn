
double bubbleSort(int *lista, int tamanho, int mostrarPassos, int sleep){
  int i, j, aux;
  clock_t begin = clock();
  double time_spent;

  if(mostrarPassos) initgraph(&gd,&gm,NULL);

  for(i = 1; i < tamanho; i++){
    for(j = 0; j < tamanho-1; j++){
      if(lista[j] > lista[j+1]){
        aux = lista[j];
        lista[j] = lista[j+1];
        lista[j+1] = aux;
      }

    }
    if (mostrarPassos) plotGraph(lista, tamanho, "Bubble Sort", sleep);
  }
  clock_t end = clock();

  if(mostrarPassos) {
    delay(2000);
    closegraph();
    limparTela();
  }
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  return time_spent;
}
