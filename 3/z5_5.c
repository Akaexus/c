#include "stdio.h"
#include "stdlib.h"

int inputPositive(char string[]) {
  int number;
  do {
      printf("%s> ", string);
      scanf("%d", &number);
  } while (number <= 0);
  return number;
}

int main() {
  int n = inputPositive("N"), // w
      m = inputPositive("M"); // h

  double **array = malloc(sizeof(double*) * m);
  for (int i = 0; i < m; i++) {
    array[i] = malloc(sizeof(double*) * n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("array[%d][%d]> ", i, j);
      scanf("%lf", &array[i][j]);
    }
  }

  double x;
  printf("x> ");
  scanf("%lf", &x);

  int number_of_columns = 0;
  int column_sum = 0;
  for (int row = 0; row < n; row++) {
    column_sum = 0;
    for (int column = 0; column < m; column++) {
        column_sum += array[row][column];
    }
    if (column_sum > x) {
      number_of_columns += 1;
    }
  }

  printf("%d kolumn posiada sume elementow wieksza od %lf", number_of_columns, x);

  for (int i = 0; i < m; i++) {
    free(array[i]);
  }
  free(array);
}
