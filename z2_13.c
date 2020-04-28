#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void
clear (void)
{
  while ( getchar() != '\n' );
}

int main() {
  char string[255];
  scanf("%s", string);
  int size = strlen(string);
  if (string[0] == 'B') {
    int sum = 0;
    for (int i = size - 1; i >= 1; i--) {
      int digit = string[i] - '0';
      if (digit) {
        sum += pow(2, size - 1 - i);
      }
    }
    printf("%d", sum);
  } else if (string[0] == 'D') {
    string[0] = '0';
    int number = atoi(string);
    char output[255];
    for (int pos = 0; number; pos++) {
      output[pos] = number % 2 ? '1' : '0';
      number /= 2;
    }
    for (int i = strlen(output); i >= 0; i--) {
      printf("%c", output[i]);
    }
  }
}
