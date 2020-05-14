#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fh;
  fh = fopen("Eden.txt", "r");
  int letters[26] = {0};
  int sum = 0;
  char buff;
  if (!fh) {
    printf("File error!");
    exit(1);
  }
  while (!feof(fh)) {
    fread(&buff, 1, 1, fh);
    buff = buff & 0x5f;
    if (buff >= 'A' && buff <= 'Z') {
      letters[buff - 'A'] += 1;
      sum += 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\t->\t%.2lf%%\n", 'a' + i, letters[i], ((double)letters[i]) / sum * 100);
  }
  int bar_size = 100;
  int limit = 0;
  for (int i = 0; i < 26; i++) {
    printf("%c | ", 'a' + i);
    limit = (letters[i] * bar_size / sum);
    for (int j = 0; j < bar_size; j++) {
      printf( j < limit ? "#" : " ");
    }

    printf("|\n");
  }
  fclose(fh);
}
