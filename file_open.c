/*
** file_open.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:25:37 2008 caner candan
** Last update Sun Mar 23 15:04:59 2008 caner candan
*/

#include "my_nm.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int		file_open(char *file, int *length)
{
  struct stat	s;
  int		fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    {
      fprintf(stderr, ERRMSG, "open");
      exit(-1);
    }
  fstat(fd, &s);
  *length = s.st_size;
  return (fd);
}
