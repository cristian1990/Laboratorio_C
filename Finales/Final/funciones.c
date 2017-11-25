#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void get_string(char msg[], char var[])
{
    printf(msg);
    fflush(stdin);
    gets(var);
}

char get_char(char msg[])
{
  char caracter;
  printf(msg);
  caracter = getche();
  return caracter;
}

void clear_screen(void)
{
  system("pause");
  system("cls");
}

int length_string(char string[])
{
	int length = 0;
	while (string[length] != '\0')
  {
    length++;
  }
	return length;
}

