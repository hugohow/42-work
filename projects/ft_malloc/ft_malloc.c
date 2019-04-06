#include "ft_malloc.h"

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int div_roundup(int a, int b) {
  return (a+b-1)/b;
}


void ft_free(void * ptr) {
  void* region = ptr-sizeof(size_t);
  if (munmap(region, *(size_t*)region) != 0) {
    perror("Could not munmap");
  }
}


void *ft_malloc(size_t size)
{
	int pagesize = getpagesize();

	size_t required = size + sizeof(size_t);
	int num_pages;
	
	num_pages = div_roundup(required, pagesize);
	void * new_region = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, 0, 0);
	if (new_region == MAP_FAILED) return NULL;
	*(size_t*)new_region = required; // We use this to free() the right number of bytes
	return new_region+sizeof(size_t);
}