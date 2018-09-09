int particionar(int *lista, int inicio, int fim){
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = *(lista + inicio);

  while( esq < dir ){
    while(lista[esq] <= pivo)
      esq++;                //percorre a posição da esquerda ate o pivo vendo se é menor ou igual
    while(lista[dir] > pivo)
      dir--;                // vai percorrendo da direita até o pivo vendo se é maio
    if(esq < dir){
      aux = lista[esq];
      lista[esq] = lista[dir];  // troca a posiação com o primeiro que for menor e o primeiro maior depois do pivô
      lista[dir] = aux;
    }
  }

  lista[inicio] = lista[dir];   //o inicio recebe o menor da direita depois dir < esq
  lista[dir] = pivo;  // e esse da direita recebe o pivo

  return dir; // o novo pivô

}

void quick_sort(int *lista, int inicio, int fim, int mostrarPassos, int sleep){
  int pivo;
  if(fim >inicio){
    if (mostrarPassos) plotGraph(lista, points, "Quick Sort", sleep);
    pivo = particionar(lista, inicio, fim);  // separa em dois galho
    quick_sort(lista, inicio, pivo-1, mostrarPassos, sleep); // antes do pivo
    quick_sort(lista,pivo+1, fim, mostrarPassos, sleep);  // depois do vetor
  }
}

double quickSort(int *lista, int inicio, int fim, int mostrarPassos, int sleep) {
  double time_spent;
  if(mostrarPassos) initgraph(&gd,&gm,NULL);

  clock_t begin = clock();
  quick_sort(lista, inicio, fim-1, mostrarPassos, sleep);
  clock_t end = clock();

  if(mostrarPassos) {
    delay(2000);
    closegraph();
    limparTela();
  }
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  return time_spent;
}
