/*
** get_rel.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri Mar 28 21:49:46 2008 caner candan
** Last update Sat Mar 29 21:21:54 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>

void		get_rel(void *buf, void **rel)
{
  Elf32_Shdr	*scn;

  scn = scn_get(buf, SHT_REL, 0);
  *rel = buf + scn->sh_offset;
}
