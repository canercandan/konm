/*
** my_objdump.c for my_objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 11:13:24 2008 caner candan
** Last update Sun Mar 30 03:20:18 2008 caner candan
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
      if (!(fd = file_open(file, &length, NAME_OD)))
	continue;
      buf = file_init(fd, length);
      if (file_elf(buf, file, NAME_OD))
	{
	  if (ac > 2)
	    printf(DUMP_NAME, file);
	  dump_scn(buf);
	}
      file_free(buf, length);
      file_close(fd);
    }
  return (0);
}
