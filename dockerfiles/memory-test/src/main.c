#include <stdlib.h>

int main()
{
  char *p;

  p = malloc(10*sizeof(char));
  p[0] = 'H';
  p[1] = 'u';
  p[2] = 'g';
 p[3] = 'o';
 p[4] = 0;
  return 0;
}
