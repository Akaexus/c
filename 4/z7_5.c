#include <stdio.h>
#include <stdlib.h>

double value(char c) {
  switch(c) {
    case 'c': return 0.01;
    case 't': return 0.02;
    case 'f': return 0.05;
    case 'd': return 0.10;
    case 'q': return 0.20;
    case 'h': return 0.50;
    case 'K': return 1;
    case 'D': return 2;
    case 'F': return 5;
  }
}

int main() {
  char nazwa1[255];
  printf("monety> ");
  scanf("%s", nazwa1);

  FILE *fptr;
  fptr = fopen(nazwa1, "r");
  char ch;
  double all;
  int c = 0;
  int t = 0;
  int f = 0;
  int d = 0;
  int q = 0;
  int h = 0;
  int K = 0;
  int D = 0;
  int F = 0;
  while(fscanf(fptr, "%c", &ch) != EOF) {
    all += value(ch);
    switch(ch) {
      case 'c': c++; break;
      case 't': t++; break;
      case 'f': f++; break;
      case 'd': d++; break;
      case 'q': q++; break;
      case 'h': h++; break;
      case 'K': K++; break;
      case 'D': D++; break;
      case 'F': F++; break;
    }
  }
  printf("%.2lfzl\n\n", all);

  printf("0.01zl\tx%d\n", c);
  printf("0.02zl\tx%d\n", t);
  printf("0.05zl\tx%d\n", f);
  printf("0.10zl\tx%d\n", d);
  printf("0.20zl\tx%d\n", q);
  printf("0.50zl\tx%d\n", h);
  printf("1zl\tx%d\n", K);
  printf("2zl\tx%d\n", D);
  printf("5zl\tx%d\n", F);

  fclose(fptr);
}
