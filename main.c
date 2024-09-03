void input(int v[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
}

void swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void sort(int v[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--){
      if (v[j] < v[j - 1]) {
        swap(v, j, j - 1);
      }
      else {
        break;
      }
    }
  }
}

void print(int v[], int n) {
  printf("Esse eh o seu vetor inteiro:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
}

int binarySearch(int v[], int n, int x) {
  int l = 0;
  int r = n - 1;
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (x < v[m]) {
      r = m - 1;
    }
    else if (x > v[m]) {
      l = m + 1;
    }
    else {
      return m;
    }
  }
  return -1;
}

void remove(int v[], int *n, int x) {
  int pos = binarySearch(v, *n, x);
  if (pos != -1) {
    v[pos] = v[*n - 1];
    (*n)--;
  }
}

void insert(int v[], int *n, int add) {
  if (*n < 50) {
    v[*n] = add;
    (*n)++;
  }
  else {
    printf("O vetor esta cheio");
  }
}

int main () {
  int wish = 0;
  int n;
  printf("Digite o tamnho do vetor(entre 3 e 50 elementos): ");
  scanf("%d", &n);

  int v[n];
  printf("Agora preencha o vetor:\n");
  input(v, n);
  sort(v, n);

  while (wish != 5) {
    printf("\n----------MENU----------\n"
       "1.Imprimir todo o vetor\n"
       "2.Consultar posicao\n"
       "3.Remover um elemento\n"
       "4.Inserir um valor\n"
       "5.Parar\n");
    scanf("%d", &wish);
    if (wish == 1) {
      print(v, n);
    }
    else if (wish == 2) {
      int x;
      printf("Digite o numero que deseja a posicao: ");
      scanf("%d", &x);
      int p = binarySearch(v, n, x);
      printf("O numero esta na posicao %d", p);
    }
    else if (wish == 3) {
      int x;
      printf("Digite o numero para ser removido: ");
      scanf("%d", &x);
      remove(v, &n, x);
      sort(v, n);
      print(v, n);
    }
    else if (wish == 4) {
      int add;
      printf("Digite o numero a ser inserido: ");
      scanf("%d", &add);
      insert(v, &n, add);
      sort(v, n);
      print(v, n);
    }
    else {
      printf("\nACABOU");
    }
  }

  return 0;
}