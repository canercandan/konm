/*
** get_machine.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 30 00:22:12 2008 caner candan
** Last update Sun Mar 30 00:26:13 2008 caner candan
*/

#include "nm-objdump.h"
#include "design.h"
#include <elf.h>

char	*get_machine(int ma)
{
  if (ma == EM_386)
    return (MA_386);
  if (ma == EM_486)
    return (MA_486);
  if (ma == EM_860)
    return (MA_860);
  if (ma == EM_960)
    return (MA_960);
  return (MA_NONE);
}
