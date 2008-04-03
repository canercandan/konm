/*
** get_class.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 23:48:46 2008 caner candan
** Last update Sun Mar 30 00:26:23 2008 caner candan
*/

#include "nm-objdump.h"
#include "design.h"
#include <elf.h>

char	*get_class(int cl)
{
  if (cl == ELFCLASS32)
    return (CL_32);
  if (cl == ELFCLASS64)
    return (CL_64);
  return (CL_NONE);
}
