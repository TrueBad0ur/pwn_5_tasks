#include <stdio.h>
#include <stdlib.h>

void hello() {
	printf("Hey, welcome, my friend!\nPwn pwn pwn it!\n\n");
}

void func() {
	char list[64];
	gets(list);
}

int main() {
  hello();
  char list[64];

  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);

  printf("buffer: ");
  func(list);

  return 0;
}
