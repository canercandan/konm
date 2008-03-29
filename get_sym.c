/*
** get_sym.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:15:08 2008 caner candan
** Last update Sat Mar 29 21:21:39 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>

void		get_sym(void *buf, void **sym, char **strtab)
{
  Elf32_Shdr	*scn;

  *sym = scn_get(buf, SHT_SYMTAB, 0);
  scn = scn_get(buf, SHT_STRTAB, 2);
  *strtab = buf + scn->sh_offset;
}
