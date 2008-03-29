/*
** fill_symtab.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri Mar 28 21:16:42 2008 caner candan
** Last update Sat Mar 29 21:26:01 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdlib.h>

void		**fill_symtab(void *buf, void *scn)
{
  Elf32_Ehdr	*elf;
  Elf32_Sym	**tab;
  Elf32_Shdr	*sym;
  Elf32_Sym	*symtab;
  int		size;
  int		i;

  elf = buf;
  sym = scn;
  symtab = buf + sym->sh_offset;
  size = sym->sh_size / sym->sh_entsize;
  tab = malloc(sizeof(**tab) * (size - elf->e_shnum) + 1);
  for (i = elf->e_shnum; i < size; i++)
    tab[i - elf->e_shnum] = symtab + i;
  tab[i - elf->e_shnum] = 0;
  return ((void *) tab);
}
