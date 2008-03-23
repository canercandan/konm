/*
** file_free.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:28:33 2008 caner candan
** Last update Sun Mar 23 15:05:24 2008 caner candan
*/

#include "my_nm.h"
#include <unistd.h>
#include <sys/mman.h>

void	file_free(void *buf, int length)
{
  munmap(buf, length);
}
