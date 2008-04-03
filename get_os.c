/*
** get_os.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 23:52:09 2008 caner candan
** Last update Sun Mar 30 00:26:51 2008 caner candan
*/

#include "nm-objdump.h"
#include "design.h"
#include <elf.h>

char	*get_os(int os)
{
  if (os == ELFOSABI_HPUX)
    return (OS_HPUX);
  if (os == ELFOSABI_LINUX)
    return (OS_LINUX);
  if (os == ELFOSABI_FREEBSD)
    return (OS_FREEBSD);
  if (os == ELFOSABI_NETBSD)
    return (OS_NETBSD);
  if (os == ELFOSABI_SOLARIS)
    return (OS_SOLARIS);
  if (os == ELFOSABI_STANDALONE)
    return (OS_STANDALONE);
  return (OS_NONE);
}
