#include "stdio.h"
#include "stdlib.h"

void
clear (void)
{
  while ( getchar() != '\n' );
}

int main() {
  unsigned int alfa;
  scanf("%d", &alfa);
  while (alfa) {
    if (alfa == 0b1011) {
      printf("Tak!");
      return 0;
    }
    alfa >>= 1;
  }
  printf("Nie!");
}
