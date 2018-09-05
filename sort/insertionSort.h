
double insertionSort(int *lista, int tamanho, int mostrarPassos, int sleep) {
    int aux = lista[1];
    int pos_aux = 1;
    int i = 0;
    clock_t begin = clock();
    double time_spent;

    if(mostrarPassos) initgraph(&gd,&gm,NULL);

    while(1) {
        i = pos_aux;
        while(aux < lista[i - 1] && i != 0) {
            troca(lista, i, i-1);
            i -= 1;
        }
        if (mostrarPassos) plotGraph(lista, tamanho, "Inserction Sort", sleep);
        if(pos_aux != tamanho - 1) {
            pos_aux += 1;
            aux = lista[pos_aux];
        }
        else {
            break;
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
