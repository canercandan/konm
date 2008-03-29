/*
** dump_scn.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:26:49 2008 caner candan
** Last update Sat Mar 29 21:54:23 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

int		dump_scn(void *buf)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*scn;
  char		*strtab;
  int		i;

  elf = buf;
  get_scn(buf, (void *) &scn, &strtab);
  if (!elf->e_shoff)
    return (0);
  for (i = 0; i < elf->e_shnum; i++)
    {
      scn = buf + elf->e_shoff + (elf->e_shentsize * i);
      if (scn->sh_type != SHT_NULL)
	printf("idx name: %d, name: %s, type: %d, offset: %08x, link: %d\n",
	       scn->sh_name, strtab + scn->sh_name, scn->sh_type,
	       scn->sh_offset, scn->sh_link);
    }
  return (1);
}
