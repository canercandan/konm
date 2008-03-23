/*
** nm.c for nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 22 11:26:54 2008 caner candan
** Last update Sun Mar 23 00:40:27 2008 caner candan
*/

#include "nm.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <unistd.h>
#include <stdio.h>

int	open_file(char *f)
{
  int	fd;

  if ((fd = open(f, O_RDONLY)) < 0)
    {
      fprintf(stderr, ERRMSG, "open");
      exit(1);
    }
  return (fd);
}

void	close_file(int fd)
{
  close(fd);
}

int		main(int ac, char **av)
{
  int		fd;
  void		*buf;
  struct stat	s;
  Elf32_Ehdr	*elf;
  Elf32_Phdr	*p;
  int		i;

  if (ac < 2)
    return (0);
  fd = open_file(av[1]);
  fstat(fd, &s);
  buf = mmap(NULL, s.st_size, PROT_READ, MAP_FILE, fd, 0);
  elf = buf;
  i = 0;
  while ((elf + i)->e_shoff)
    {
      printf("shoff: %08x, phoff: %08x, nb: %d, phnum: %d, phentsize: %d\n",
	     (elf + i)->e_shoff,
	     (elf + i)->e_phoff,
	     (elf + i)->e_shnum,
	     (elf + i)->e_phnum,
	     (elf + i)->e_phentsize);
      i++;
    }
  munmap(elf, s.st_size);
  close_file(fd);
  return (0);
}
