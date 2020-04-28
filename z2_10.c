#include "stdio.h"
#include "stdlib.h"

void
clear (void)
{
  while ( getchar() != '\n' );
}

int main() {
  char choice;
  while (1) {
    fflush(stdin);
    printf("wybor> ");
    scanf("%c", &choice);
    clear();
    if (choice == 'Q' || choice == 'q') {
      break;
    }
    unsigned long long section;

    if (choice == 'N' || choice == 'n') {
        printf("sekcja> ");
        fflush(stdin);
        scanf("%lld", &section);
        clear();
    } else if (choice == 'L' || choice == 'l') {
      int position = 0;
      int index = 0;
      unsigned long long section2 = section;
      while (section2) {
        if (section2 % 2 == 1) {
          position = index;
        }
        section2 >>= 1;
        index += 1;
      }
      printf("%d", position);
    } else if (choice == 'R' || choice == 'r') {
      unsigned long long section2 = section;
      int index = 0;
      while (section2) {
        if (section2 % 2 == 0) {
          printf("%d", index);
          break;
        }
        section2 >>= 1;
        index += 1;
      }
    }
  }
}
