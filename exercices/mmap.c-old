#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

int     main(int argc, char **argv)
{
  int           fd;
  struct stat   s;
  void          *addr;
  int           i;

  if (argc != 2)
    {
      my_putstr("usage: mmap file\n");
      exit(1);
    }
  if ((fd = open(argv[1], O_RDWR)) == -1)
    aff_err(argv[1]);
  if (fstat(fd, &s) == -1)
    aff_err("stat");
  addr = mmap(NULL, s.st_size, PROT_READ|PROT_WRITE, MAP_FILE, fd, 0);
  if (addr == (void *)-1)
    aff_err("mmap");
  my_putnbr(addr);
  my_putchar('\n');
  munmap(addr, s.st_size);
  close(fd);
}
