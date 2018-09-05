
int *randomVector(int *v, int size) {
  int i;
  free(v);
  v = (int *)malloc(size*sizeof(int));
  srand( (unsigned)time(NULL) );
  for ( i = 0; i < size; i++) {
    v[i] = rand() % 360;
  }
  return v;
}
