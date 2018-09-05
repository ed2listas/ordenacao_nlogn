int menu() {
  int opcao;
  limparTela();
  printf("=======================\n");
  printf("= Digite uma opcao    =\n");
  printf("=======================\n");
  printf("= 1) bubble sort      =\n");
  printf("= 2) insertion sort   =\n");
  printf("= 3) selection sort   =\n");
  printf("= 4) Comparar os tres =\n");
  printf("= 5) Configuracoes    =\n");
  printf("= 0) Sair             =\n");
  printf("=======================\n");
  scanf("%d", &opcao);
  return opcao;
}
