#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	main()
{
  int	fd;
  void	*addr;
  int	len;

  if ((fd = open("/dev/zero", O_RDWR)) == -1)
    aff_err("/dev/zero");
  if ((addr = mmap(NULL, 42, PROT_READ|PROT_WRITE, 
                   MAP_FILE|MAP_PRIVATE, fd, 0))
      == (void *)-1)
    aff_err("mmap");
  my_putnbr(addr);
  my_putchar('\n');
  len = 0;
  munmap(addr, len);
  close(fd);
}
