#include "stdio.h"
#include "stdlib.h"

int main() {
  unsigned int number;
  scanf("%d", &number);
  int digits = 0;
  while (number) {
    digits++;
    number >>= 1;
  }
  printf("%d", digits);
}
