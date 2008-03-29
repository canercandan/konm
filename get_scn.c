/*
** get_scn.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:15:57 2008 caner candan
** Last update Sat Mar 29 21:21:27 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>

void		get_scn(void *buf, void **scn, char **strtab)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*s;

  elf = buf;
  s = buf + elf->e_shoff + (elf->e_shentsize * elf->e_shstrndx);
  *scn = s;
  *strtab = buf + s->sh_offset;
}
