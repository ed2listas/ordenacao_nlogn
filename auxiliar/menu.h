int menu() {
  int opcao;
  limparTela();
  printf("=======================\n");
  printf("= Digite uma opcao    =\n");
  printf("=======================\n");
  printf("= 1) radix sort lsd   =\n");
  printf("= 2) quick sort       =\n");
  printf("= 3) merge sort       =\n");
  printf("= 4) Comparar os tres =\n");
  printf("= 5) Configuracoes    =\n");
  printf("= 0) Sair             =\n");
  printf("=======================\n");
  scanf("%d", &opcao);
  return opcao;
}
