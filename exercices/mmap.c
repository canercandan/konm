/*
** mmap.c for mmap in /home/candan_c/rendu/project/nm-objdump/exercices
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 20 20:22:47 2008 caner candan
** Last update Fri Mar 21 20:16:14 2008 caner candan
*/

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <elf.h>
#include <unistd.h>

int			maper(int fd, struct stat *s)
{
  static Elf32_Ehdr	*elf;

  elf = mmap(NULL, s->st_size, PROT_READ, MAP_FILE, fd, (elf ? elf->e_phoff : 0));
  if (!elf->e_phoff)
    {
      munmap(elf, s->st_size);
      return (-1);
    }
  printf("addr: %08x, nb: %d, version %d\n",
	 elf->e_shoff, elf->e_shnum, elf->e_version);
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;
  void		*buf;
  struct stat	s;
  Elf32_Ehdr	*elf;

  if ((fd = open(av[1], O_RDONLY)) < 0)
    {
      fprintf(stderr, "Error: open\n");
      exit(1);
    }
  fstat(fd, &s);
  while (42)
    {
      if (maper(fd, &s) < 0)
	break;
    }
  close(fd);
  return (0);
}
