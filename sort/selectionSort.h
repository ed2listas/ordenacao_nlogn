
double selectionSort(int *lista, int tamanho, int mostrarPassos, int sleep) {
  int i, j;
  clock_t begin = clock();
  double time_spent;

  if(mostrarPassos) initgraph(&gd,&gm,NULL);

  for (i = 0; i < tamanho; i++) {
    for (j = i+1; j < tamanho; j++) {
      if (lista[j] < lista[i]) {
        troca(lista, i, j);
      }

    }
    if (mostrarPassos) plotGraph(lista, tamanho, "Selection Sort", sleep);
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
