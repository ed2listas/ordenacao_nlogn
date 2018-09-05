#ifndef PLOTGRAPH
#define PLOTGRAPH

//#define DIST_TO_RIGHT_SIDE 20

#define ROP 2 // radius of point (raio do ponto)
#define LEFT 30
#define TOP 40
#define RIGHT 620
#define BOTTOM 400

// valor maximo dos pontos é 360

void plotGraph(int *vector, int n, char *title, int minisec) {
  int x, dbp = RIGHT/n;
  char str[5];
  cleardevice(); // apaga tela do grafico
  outtextxy(LEFT + 250, TOP-20, title);
  rectangle(LEFT, TOP, RIGHT, BOTTOM);
  for (x = 0; x <= BOTTOM-TOP; x+=20) {
    sprintf(str, "%d", x);
    outtextxy(0, BOTTOM-x, str);
  }
  for (x = 0; x < n; x++) {
    circle(x*dbp+LEFT, BOTTOM-vector[x], ROP);
  }
  delay(minisec);
}

#endif
