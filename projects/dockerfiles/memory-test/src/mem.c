#include <stdio.h>
#include <stdlib.h>
    
static int i_stat = 4; /* Stocké dans le segment data */
int  i_glob;           /* Stocké dans le segment bss  */
int *pi_pg;            /* Stocké dans le segment bss  */
    
/* main est stocké dans le segment text de la zone de programme */
int main(int nargs, char **args) { 
  /* paramètres nargs et args stockés dans la frame numéro 1 de la pile */
  int *pi_loc;       /* dans la frame 1 de la pile */
  void *sbrk0;       /* nécessaire pour stocker l'adresse de base 
			avant le premier malloc    */

  sbrk0 = (void *) sbrk(0);

  if (!(pi_loc = (int *) malloc(sizeof(int) * 16)))   
    /* réservation de 16 x sizeof(int) sur le tas */
    return 1; 
  if (!(pi_pg  = (int *) malloc(sizeof(int) *  8))) { 
    /* réservation de 8 x sizeof(int) sur le tas */
    free(pi_loc); 
    return 2;
  }
  printf("adresse de i_stat = 0x%08x (zone programme, segment data)\n", &i_stat); 
  printf("adresse de i_glob = 0x%08x (zone programme, segment bss)\n",  &i_glob); 
  printf("adresse de pi_pg  = 0x%08x (zone programme, segment bss)\n",  &pi_pg); 
  printf("adresse de main   = 0x%08x (zone programme, segment text)\n", main); 
  printf("adresse de nargs  = 0x%08x (pile frame 1)\n", &nargs);
  printf("adresse de args   = 0x%08x (pile frame 1)\n", &args);
  printf("adresse de pi_loc = 0x%08x (pile frame 1)\n", &pi_loc);
  printf("sbrk(0) (heap)    = 0x%08x (tas)\n", sbrk0);
  printf("pi_loc            = 0x%08x (tas)\n", pi_loc);
  printf("pi_pg             = 0x%08x (tas)\n", pi_pg);
  free(pi_pg);
  free(pi_loc); 
  return 0;
}
