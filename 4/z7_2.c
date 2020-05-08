#include <stdio.h>
#include <stdlib.h>

int main() {
  char nazwa1[255];
  printf("src> ");
  scanf("%s", nazwa1);
  char nazwa2[255];
  printf("dst> ");
  scanf("%s", nazwa2);

  FILE *fptr, *f2ptr;
  fptr = fopen(nazwa1, "r");
  f2ptr = fopen(nazwa2, "w");
  if (!fptr) {
    printf("Plik %s nie istnieje!", nazwa1);
  }
  if (!f2ptr) {
    printf("Plik %s nie istnieje!", nazwa2);
  }
  int number;
  if (fptr && f2ptr) {
    while(fscanf(fptr, "%d\n", &number) != EOF) {
      if (number > 137) {
        fprintf(f2ptr, "%d\n", number);
      }
    }
  }
  fclose(fptr);
}
