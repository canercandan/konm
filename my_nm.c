/*
** my_nm.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 21:30:56 2008 caner candan
** Last update Sat Mar 29 22:49:16 2008 caner candan
*/

#include "nm-objdump.h"
#include <stdio.h>

int	main(int ac, char **av)
{
  void	*buf;
  char	*file;
  int	fd;
  int	length;
  int	i;

  file = (ac < 2 ? FILE_DEFAULT : 0);
  for (i = 1; i < ac || (ac < 2 && i == 1); i++)
    {
      if (ac >= 2)
	file = av[i];
      fd = file_open(file, &length, NAME_NM);
      buf = file_init(fd, length);
      if (file_elf(buf, file, NAME_NM))
	{
	  if (ac > 2)
	    printf(DUMP_NAME, file);
	  dump_sym(buf);
	}
      file_free(buf, length);
      file_close(fd);
    }
  return (0);
}
