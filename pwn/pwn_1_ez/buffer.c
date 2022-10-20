#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void info_func() {
	printf("Hey, kids! You can give us 1 coin at a time!\nSorry, but you have just 15 seconds, Virtual Private Servers are very expensive nowadayas :(\n\n\n");
}

int main() {
	info_func();
	char *win = getenv("flag");
	unsigned short flag = 0xE000;
	char input='0';
	while (1) {
		printf("Enter how many coins you wanna give us, but no more than 9 and not less than 1 please :))))\nOur coin grabber is still in production!\n");
		do {
    			input = getchar();
  		}
  		while (!isdigit(input));

		input -= '0';
		flag += input;

		printf("GOT: %d\n", input);

		if (flag == 0) {
			puts(win);
			break;
		}
		//printf("FLAG: %x\n", flag);
	}
}
