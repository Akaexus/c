#include <stdio.h>
#include <stdlib.h>

struct Zodiak {
  char nazwa[16];
  int dzien;
  int miesiac;
};

int main() {
  struct Zodiak array[12] = {
    {"Wodnik",     20, 1},
    {"Ryby",       19, 2},
    {"Baran",      21, 3},
    {"Byk",        20, 4},
    {"Bliznieta",  23, 5},
    {"Rak",        22, 6},
    {"Lew",        23, 7},
    {"Panna",      24, 8},
    {"Waga",       23, 9},
    {"Skorpion",   23, 10},
    {"Strzelec",   22, 11},
    {"Koziorozec", 22, 12}
  };
  int miesiac, dzien;
  printf("miesiac> ");
  scanf("%d", &miesiac);
  printf("dzien> ");
  scanf("%d", &dzien);
  if (array[miesiac - 1].dzien <= dzien) {
    printf("%s", array[miesiac - 1].nazwa);
  } else {
    if (miesiac == 1) {
      printf("%s", array[11].nazwa);
    } else {
      printf("%s", array[miesiac-2].nazwa);
    }
  }
}
