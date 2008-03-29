/*
** scn_get.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 15:29:32 2008 caner candan
** Last update Sat Mar 29 21:16:11 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		*scn_get(void *buf, unsigned int type, int pos)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*sct;
  int		i;
  int		fnd;

  elf = buf;
  fnd = 0;
  for (i = 0; i < elf->e_shnum; i++)
    {
      sct = buf + elf->e_shoff + (elf->e_shentsize * i);
      if (sct->sh_type == type)
	{
	  if (fnd == pos)
	    return (sct);
	  fnd++;
	}
    }
  return (0);
}
