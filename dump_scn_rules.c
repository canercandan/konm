/*
** dump_scn_rules.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 30 17:19:05 2008 caner candan
** Last update Sun Mar 30 23:50:56 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>

int		dump_scn_rules(void *buf, void *s, int nb)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*scn;
  Elf32_Shdr	*scntab;
  int		type;

  elf = buf;
  scn = s;
  type = scn->sh_type;
  if (type == SHT_NULL || type == SHT_NOBITS
      || nb == elf->e_shstrndx
      || !scn->sh_size)
    return (1);
  if ((scntab = scn_get(buf, SHT_SYMTAB, 0)))
    if (scntab->sh_name == scn->sh_name)
      return (1);
  if ((scntab = scn_get(buf, SHT_STRTAB, 1)))
    if (scntab->sh_name == scn->sh_name)
      return (1);
  if ((scntab = scn_get(buf, SHT_STRTAB, 2)))
    if (scntab->sh_name == scn->sh_name)
      return (1);
  return (0);
}
