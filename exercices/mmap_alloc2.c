#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	main()
{
  void	*addr;
  int	len;

  addr = mmap(NULL, 42, PROT_READ|PROT_WRITE,
              MAP_ANON|MAP_PRIVATE, -1, 0);
  if (addr == (void *)-1)
    aff_err("mmap");
  my_putnbr(addr);
  my_putchar('\n');
  len = 0;
  munmap(addr, len);
}
