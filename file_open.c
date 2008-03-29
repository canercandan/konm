/*
** file_open.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:25:37 2008 caner candan
** Last update Sat Mar 29 21:57:47 2008 caner candan
*/

#include "nm-objdump.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int		file_open(char *file, int *length, char *name)
{
  struct stat	s;
  int		fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    {
      fprintf(stderr, NOFILE, name, file);
      exit(-1);
    }
  fstat(fd, &s);
  *length = s.st_size;
  return (fd);
}
