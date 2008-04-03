/*
** dump_scn.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:26:49 2008 caner candan
** Last update Sun Mar 30 22:07:34 2008 caner candan
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
      if (dump_scn_rules(buf, scn, i))
	continue;
      printf(CONTENTS_SCN, strtab + scn->sh_name);
      dump_scn_split(buf, scn);
    }
  return (1);
}
