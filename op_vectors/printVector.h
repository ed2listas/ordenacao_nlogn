void printVector(int *lista, int tamLista) {
  int i;
  printf("[");
  for ( i = 0; i < tamLista; i++) {
    printf("%d, ", lista[i]);
  }
  printf("]\n\n\n");
}
