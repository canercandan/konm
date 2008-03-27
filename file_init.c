/*
** file_init.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:27:50 2008 caner candan
** Last update Sun Mar 23 18:39:29 2008 caner candan
*/

#include "my_nm.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

void	*file_init(int fd, int length)
{
  void	*buf;

  if (!(buf = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0)))
    {
      fprintf(stderr, ERRMSG, "mmap");
      exit(-1);
    }
  return (buf);
}
