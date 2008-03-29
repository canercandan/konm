/*
** file_free.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:28:33 2008 caner candan
** Last update Sat Mar 29 21:12:10 2008 caner candan
*/

#include "nm-objdump.h"
#include <unistd.h>
#include <sys/mman.h>

void	file_free(void *buf, int length)
{
  munmap(buf, length);
}
