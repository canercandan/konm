/*
** my_nm.c- for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 21:30:56 2008 caner candan
** Last update Sat Mar 29 22:21:56 2008 caner candan
*/

#include "nm-objdump.h"
#include <stdio.h>

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
      fd = file_open(av[i], &length, NAME_NM);
      buf = file_init(fd, length);
      if (file_elf(buf, av[i], NAME_NM))
	{
	  if (ac > 2)
	    printf(DUMP_NAME, av[i]);
	  dump_sym(buf);
	}
      file_free(buf, length);
      file_close(fd);
    }
  return (0);
}
