/*
** dump_prg.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:40:28 2008 caner candan
** Last update Sat Mar 29 21:21:14 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

int		dump_prg(void *buf)
{
  Elf32_Ehdr	*elf;
  Elf32_Phdr	*prg;
  int		i;

  elf = buf;
  if (!elf->e_phoff)
    return (0);
  for (i = 0; i < elf->e_phnum; i++)
    {
      prg = buf + elf->e_phoff + (elf->e_phentsize * i);
      printf("type: %d, offset: %08x\n",
	     prg->p_type, prg->p_offset);
    }
  return (1);
}
