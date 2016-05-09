#include <stdio.h>

int main() {
  char name[80];
  char reddit[80];
  int age;
  printf("Please state your name: ");
  //scanf("%s", name);
  scanf("%s", name);
  printf("Please state your reddit name: ");
  scanf("%s", reddit);
  printf("What is your age? ");
  scanf("%i", &age);
  printf("\nYour name is %s, your reddit name is %s and you are %i years old.", name, reddit, age);
  return 0;
}