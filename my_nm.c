/*
** my_nm.c- for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 21:30:56 2008 caner candan
** Last update Sat Mar 29 22:09:34 2008 caner candan
*/

#include "nm-objdump.h"

int	main(int ac, char **av)
{
  void	*buf;
  int	fd;
  int	length;
  int	i;

  if (ac < 2)
    return (0);
  for (i = 1; i < ac; i++)
    {
      fd = file_open(av[1], &length, NAME_NM);
      buf = file_init(fd, length);
      file_elf(buf, av[1], NAME_NM);
      /*
	file_type(buf, av[1], name);
	dump_scn(buf);
	dump_prg(buf);
      */
      dump_sym(buf);
      file_free(buf, length);
      file_close(fd);
    }
  return (0);
}
