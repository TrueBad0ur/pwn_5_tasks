#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void func1() {
	printf("Done!\n");
	char *win = getenv("f1");
	puts(win);
}

void func26() {
        printf("Done!\n");
        char *win = getenv("f26");
        puts(win);
}

void func27() {
        printf("Done!\n");
        char *win = getenv("f27");
        puts(win);
}

void func24() {
        printf("Done!\n");
        char *win = getenv("f24");
        puts(win);
}

void func25() {
        printf("Done!\n");
        char *win = getenv("f25");
        puts(win);
}

void func28() {
        printf("Done!\n");
        char *win = getenv("f28");
        puts(win);
}

void func23() {
        printf("Done!\n");
        char *win = getenv("f23");
        puts(win);
}

void func2() {
        printf("Done!\n");
        char *win = getenv("f2");
        puts(win);
}

void func22() {
        printf("Done!\n");
        char *win = getenv("f22");
        puts(win);
}

void func3() {
        printf("Done!\n");
        char *win = getenv("f3");
        puts(win);
}

void func21() {
        printf("Done!\n");
        char *win = getenv("f21");
        puts(win);
}

void func29() {
        printf("Done!\n");
        char *win = getenv("f29");
        puts(win);
}

void func20() {
        printf("Done!\n");
        char *win = getenv("f20");
        puts(win);
}

void func4() {
        printf("Done!\n");
        char *win = getenv("f4");
        puts(win);
}

void func15() {
        printf("Done!\n");
        char *win = getenv("f15");
        puts(win);
}

void func17() {
        printf("Done!\n");
        char *win = getenv("f17");
        puts(win);
}

void func16() {
        printf("Done!\n");
        char *win = getenv("f16");
        puts(win);
}

void func18() {
        printf("Done!\n");
        char *win = getenv("f18");
        puts(win);
}

void func19() {
        printf("Done!\n");
        char *win = getenv("f19");
        puts(win);
}

void func5() {
        printf("Done!\n");
        char *win = getenv("f5");
        puts(win);
}

void func14() {
        printf("Done!\n");
        char *win = getenv("f14");
        puts(win);
}

void func6() {
        printf("Done!\n");
        char *win = getenv("f6");
        puts(win);
}

void func13() {
        printf("Done!\n");
        char *win = getenv("f13");
        puts(win);
}

void func30() {
        printf("Done!\n");
        char *win = getenv("f30");
        puts(win);
}

void func12() {
        printf("Done!\n");
        char *win = getenv("f12");
        puts(win);
}

void func7() {
        printf("Done!\n");
        char *win = getenv("f7");
        puts(win);
}

void func31() {
        printf("Done!\n");
        char *win = getenv("f31");
        puts(win);
}

void func8() {
        printf("Done!\n");
        char *win = getenv("f8");
        puts(win);
}

void func33() {
        printf("Done!\n");
        char *win = getenv("f33");
        puts(win);
}

void func32() {
        printf("Done!\n");
        char *win = getenv("f32");
        puts(win);
}

void func9() {
        printf("Done!\n");
        char *win = getenv("f9");
        puts(win);
}

void func11() {
        printf("Done!\n");
        char *win = getenv("f11");
        puts(win);
}

void func10() {
        printf("Done!\n");
        char *win = getenv("f10");
        puts(win);
}

int main() {
        printf("Your main function is here: %p\nThat's all what I can say :(\n", main);
	//printf("func1: %p", func1);

        unsigned long long int func_addr;
        while (1) {
		printf("\nEnter func addr: ");
        	scanf("%llu", &func_addr);
        	//printf("\nYou func addr: %d\n", func_addr);

        	void(*funct)(void) = (void(*)(void))func_addr;

        	funct();
        }
	return 0;
}
