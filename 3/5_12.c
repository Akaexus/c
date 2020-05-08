#include <stdio.h>
#include <stdlib.h>

struct Item {
  char name[50];
  int quantity;
  double price;
};

void
clear (void)
{
  while ( getchar() != '\n' );
}

int main() {
  struct Item items[50];
  int index = 0;
  char choice;
  do {
    printf("choice> ");
    scanf("%c", &choice);
    if (choice == 'N' || choice == 'n') {
      struct Item item;
      printf("nazwa> ");
      scanf("%s", item.name);
      printf("ilosc> ");
      scanf("%d", &item.quantity);
      printf("cena> ");
      scanf("%lf", &item.price);
      items[index] = item;
      index++;
    } else if (choice == 'W' || choice == 'w') {
      for (int i = 0; i < index; i++) {
        printf("[%d] %s\t%d\t%f\n", i, items[i].name, items[i].quantity, items[i].price);
      }
    } else if (choice == 'R' || choice == 'r') {
      double all = 0;
      for (int i = 0; i < index; i++) {
        all += items[i].quantity * items[i].price;
      }
      printf("%f\n", all);
    }
    clear();
  } while(choice != 'Q' && choice != 'q');
}
