#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int superhack() {
  char *v1;
  unsigned int v2;

  scanf("%u", &v1);
  scanf("%d", &v2);
  v2 = v2&0xff;
  *v1 = v2;
  if ( !v2 ) {
  puts("Caesar non supra grammaticos");
  } else {
    if ( (v2 == 1) || (v2 == 2) )
    {
      puts("Plenus venter non studet libenter");
    }
    else if ( v2 > 3 )
    {
      if ( v2 > 5 )
        puts("Festina lente");
      else
        puts("De gustibus non est disputandum");
    }
    else if (v2 == 7)
    {
      puts("Timeo Danaos et dona ferentes");
    } else {
      puts("Risus abundat in ore stultorum");
    }
  }

  return 0;
}

int settup(void *addr) {
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}

int main() {
  settup(superhack);
  superhack();
  //char inp_byte_c;
  //int inp_byte_i;

  //scanf("%u", &addr);

  //scanf("%d", &inp_byte);

  //fgets(inp_byte_c, sizeof(inp_byte_c), stdin);
  //inp_byte_i = (int)strtol(inp_byte_c, NULL, 10);

  //inp_byte_i = (char)inp_byte_i & 0xFF;

  //*(int *)addr_i = inp_byte_i;
}
