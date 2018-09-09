typedef struct BALDE {
  int *pilha;
  int tam;
}Balde;

int qtdDigitos(int n) {
  int qtd = 0;
  if (n < 1) return 0;
  while (n /= 10)
    qtd++;
  return qtd+1;
}

int maiorNum(int *v, int n) {
  int maior = v[0];
  int i;
  for (i = 1; i < n; i++)
    if (v[i] > maior) maior = v[i];
  return maior;
}

int pegaDigito(int valor, int digito) {
  int i = 0, aux = 0;
  while (aux < digito) {
    valor /= 10;
    aux++;
  }
  return valor % 10;
}

void resetBalde(Balde *balde) {
  int i;
  for (i = 0; i < 10; i++) {
    balde[i].pilha = NULL;
    balde[i].tam = 0;
  }
}

void pushBalde(Balde *balde, int qualBalde, int valor) {
  balde[qualBalde].pilha = (int *)realloc(balde[qualBalde].pilha, sizeof(int)*(balde[qualBalde].tam+1));
  balde[qualBalde].tam += 1;
  balde[qualBalde].pilha[balde[qualBalde].tam-1] = valor;
}

int popBalde(Balde *balde, int qualBalde) {
  int size = balde[qualBalde].tam, valor;
  if (size == 0) {
    balde[qualBalde].pilha = NULL;
    return -1;
  }
  valor = balde[qualBalde].pilha[size-1];
  balde[qualBalde].tam -= 1;
  balde[qualBalde].pilha = (int *)realloc(balde[qualBalde].pilha, sizeof(int)*(size-1));
  return valor;
}

void printBalde(Balde *balde, int qualBalde) {
  int tamanho = balde[qualBalde].tam, i;
  if (tamanho > 0) {
    printf("balde %d:\n", qualBalde);
    for (i = 0; i < tamanho; i++) {
      printf("%d, ", balde[qualBalde].pilha[i]);
    }
    printf("\n\n");
  }
}
double radixSort(int *lista, int tamanho, int mostrarPassos, int sleep){
  int i, j, val, tamBalde, digitoProc, ciclos, casa=0, casaDecim;
  int maior = maiorNum(lista, tamanho);
  int digitos = qtdDigitos(maior);
  Balde balde[10];
  resetBalde(balde);

  clock_t begin = clock();
  double time_spent;
  if(mostrarPassos) initgraph(&gd,&gm,NULL);

  for(casaDecim = 0; casaDecim < digitos; casaDecim++) { // se repete 'qtd de digitos' vezes
    for (i = 0; i < tamanho; i++) { // derramando valores nos baldes
      pushBalde(balde, pegaDigito(lista[i], casaDecim), lista[i]);
    }
    j = 0;
    for (i = 0; i < 10; i++) { // pegando valores dos baldes
      tamBalde = j+balde[i].tam-1;
      do {
        val = popBalde(balde, i);
        if(val != -1) {
          lista[tamBalde] = val;
          tamBalde--;
          j++;
        }
      } while(val != -1);
      if (mostrarPassos) plotGraph(lista, tamanho, "Radix Sort", sleep);
    }
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
