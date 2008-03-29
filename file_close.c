/*
** file_close.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:27:07 2008 caner candan
** Last update Sat Mar 29 21:11:41 2008 caner candan
*/

#include "nm-objdump.h"
#include <unistd.h>

void	file_close(int fd)
{
  close(fd);
}
