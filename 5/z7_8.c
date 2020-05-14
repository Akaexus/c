#include <stdio.h>
#include <stdlib.h>

struct Pomiar {
  int numer_serii;
  double pomiar[4];
  int sposob_przetwarzania;
};

struct Wynik {
    int numer_serii;
    double wyliczona_wartosc;
    int sposob_przetwarzania;
};

double max(double * array, int n) {
  double max = array[0];
  for(int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

double min(double * array, int n) {
  double min = array[0];
  for(int i = 1; i < n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

double avg(double * array, int n) {
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += array[i];
  }
  return sum/n;
}

int main() {
  FILE *fp;
  fp = fopen("Pomiary.txt", "r");
  if (!fp) {
    printf("File error!");
    exit(1);
  }
  int n;
  fscanf(fp, "%d", &n);
  struct Pomiar *pomiary = malloc(sizeof(struct Pomiar) * n);
  struct Wynik *wyniki = malloc(sizeof(struct Wynik) * n);

  double (*fn[])(double*, int) = {avg, max, min};

  for(int i = 0; i < n; i++) {
    fscanf(fp, "%d %lf %lf %lf %lf %d",
      &pomiary[i].numer_serii,
      pomiary[i].pomiar,
      pomiary[i].pomiar + 1,
      pomiary[i].pomiar + 2,
      pomiary[i].pomiar + 3,
      &pomiary[i].sposob_przetwarzania
    );
  }
  fclose(fp);

  for(int i = 0; i < n; i++) {
    wyniki[i].numer_serii = pomiary[i].numer_serii;
    wyniki[i].wyliczona_wartosc = fn[pomiary[i].sposob_przetwarzania](pomiary[i].pomiar, 4);
    wyniki[i].sposob_przetwarzania = pomiary[i].sposob_przetwarzania;
  }
  free(pomiary);
  fp = fopen("Wyniki.txt", "w");
  if (!fp) {
    printf("File error!");
    exit(1);
  }
  fprintf(fp, "%d\n", n);
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d %lf %d\n", wyniki[i].numer_serii, wyniki[i].wyliczona_wartosc, wyniki[i].sposob_przetwarzania);
  }
  fclose(fp);
  free(wyniki);
}
