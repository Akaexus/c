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
  int w = inputPositive("w"),
      h = inputPositive("h");

  double **array = malloc(sizeof(double*) * h);
  for (int i = 0; i < h; i++) {
    array[i] = malloc(sizeof(double*) * w);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("array[%d][%d]> ", i, j);
      scanf("%lf", &array[i][j]);
    }
  }

  int cs = inputPositive("column_start"),
      ce = inputPositive("column_end");
  for (int row = 0; row < h; row++) {
    for (int column = cs; column <= ce; column++) {
      printf("%lf ", array[row][column]);
    }
    printf("\n");
  }


  for (int i = 0; i < h; i++) {
    free(array[i]);
  }
  free(array);
}
