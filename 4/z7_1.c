#include <stdio.h>
#include <stdlib.h>

struct Employee {
  char surname[255];
  double salary;
};

void
clear (void)
{
  while ( getchar() != '\n' );
}

int main() {
  int index = 0;
  struct Employee employees[50];
  char choice;
  do {
    printf("choice> ");
    scanf("%c", &choice);
    switch(choice) {
      case 'N':
        printf("nazwisko> ");
        struct Employee employee;
        scanf("%s", employee.surname);
        printf("pensja> ");
        scanf("%lf", &employee.salary);
        employees[index] = employee;
        index++;
        break;
      case 'W':
        for (int i = 0; i < index; i++) {
          printf("[%d] %s\t%.2lf\n", i, employees[i].surname, employees[i].salary);
        }
        break;
      case 'Z':
        printf("path> ");
        FILE *ptr;
        char path[255];

        scanf("%s", path);
        ptr = fopen(path, "w");
        if (ptr) {
          for (int i = 0; i < index; i++) {
            fprintf(ptr, "%s,%.2lf\n", employees[i].surname, employees[i].salary);
          }
        } else {
          printf("plik nie istnieje!\n");
        }
        fclose(ptr);
        break;
      case 'R':
        printf("path> ");
        FILE *rptr;
        char rpath[255];

        scanf("%s", rpath);
        rptr = fopen(rpath, "r");
        if (rptr) {
          index = 0;
          double salary;
          while (fscanf(rptr, "%s %lf\n", employees[index].surname, &employees[index].salary) != EOF) {
            // employees[index].surname = surname;
            // employees[index].salary = salary;
            index++;
          }
        } else {
          printf("plik nie istnieje!\n");
        }
        fclose(rptr);
        break;
    }
    clear();
  } while(choice != 'K');

}
