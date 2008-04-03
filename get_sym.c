/*
** get_sym.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:15:08 2008 caner candan
** Last update Mon Mar 31 00:34:02 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

void		get_sym(void *buf, void **sym, char **strtab)
{
  Elf32_Shdr	*scn;

  *sym = scn_get(buf, SHT_SYMTAB, 0);
  if (!(scn = scn_get(buf, SHT_STRTAB, 2)))
    {
      printf(NOSYMBOL, "nm", "FILE");
      exit(-1);
    }
  *strtab = buf + scn->sh_offset;
}
