void troca (int *lista, int val1, int val2) {
    int aux = lista[val1];
    lista[val1] = lista[val2];
    lista[val2] = aux;
}
