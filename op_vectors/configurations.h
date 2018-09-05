int menuConfig(int points, int animDelay) {
  int opcao;
  limparTela();
  printf("Digite a opcao do que quer alterar:\n\n");
  printf("1: Numero de pontos  (%d)\n", points);
  printf("2: Delay da animacao (%d)\n", animDelay);
  printf("3: Resetar\n");
  printf("0: Voltar\n\n");
  scanf("%d", &opcao);
  return opcao;
}

void configurations(int *points, int *animDelay) {
  int opcao;
  do {
    opcao = menuConfig(*points, *animDelay);
    switch (opcao) {
      case 1:
        printf("\nDigite a nova quantidade de pontos: ");
        scanf("%d", points);
        break;
      case 2:
        printf("\nDigite o delay da animacao: ");
        scanf("%d", animDelay);
        break;
      case 3:
        *points = 99;
        *animDelay = 100;
        break;
      case 0:
        printf("\nVoltando...\n");
        break;
      default:
        printf("\nOpcao invalida!!\n");
        getch();
    }
  } while(opcao);

}
