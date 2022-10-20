#include <stdio.h>
#include <stdlib.h>

void lovely_func() {
    char buffer[512];
    char *p = buffer;
    printf("\nyour buffer: %p\n", p);
    gets(buffer);
    printf("Entered: %s\n", buffer);
}

int main(int argc, char **argv) {
    printf("Nothing special, maybe string should be a bit bigger :)\nIf you trained yesterday, you'll get the idea \n:)");
    lovely_func();
}
