/*
** sct_get.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 15:29:32 2008 caner candan
** Last update Sun Mar 23 16:25:22 2008 caner candan
*/

#include "my_nm.h"
#include <elf.h>
#include <stdio.h>

void		*sct_get(void *buf, int type)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*sct;
  int		i;

  elf = buf;
  i = 0;
  while (i < elf->e_shnum)
    {
      sct = buf + elf->e_shoff + (elf->e_shentsize * i);
      if (sct->sh_type == type)
	{
	  printf("type found: %d\n", i);
	  return (sct);
	}
      i++;
    }
  return (0);
}
