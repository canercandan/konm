/*
** file_close.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:27:07 2008 caner candan
** Last update Sun Mar 23 15:05:33 2008 caner candan
*/

#include "my_nm.h"
#include <unistd.h>

void	file_close(int fd)
{
  close(fd);
}
