#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <unistd.h>

int main() {
  unsigned char p = (unsigned char)(long long)999; 
  int i;

  i = 0;
  while (i < sizeof((long long)999))
    {
      printf("%p \t %x\n", &p+i, *(&p+i));
      i++;
    }
  return 0;
}
