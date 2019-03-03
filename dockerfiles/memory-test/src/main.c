#include <stdlib.h>

int main()
{
  int *a;
  int b;

  b = 42;
  a = malloc(sizeof(int)*10);


  free(a);
  return (0);
}
