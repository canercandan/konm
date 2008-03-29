/*
** dump_sym.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 27 17:38:10 2008 caner candan
** Last update Sat Mar 29 21:20:59 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

int		dump_sym(void *buf)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*sym;
  Elf32_Sym	**tab;
  char		*strtab;
  int		i;

  elf = buf;
  get_sym(buf, (void *) &sym, &strtab);
  tab = (void *) fill_symtab(elf, sym);
  tab = (void *) sort_symtab((void *) tab, strtab);
  for (i = 0; tab[i]; i++)
    {
      if (ELF32_ST_TYPE(tab[i]->st_info) != STT_FILE)
	{
	  if (tab[i]->st_value)
	    printf("%08x ", tab[i]->st_value);
	  else
	    printf("\t ");
	  get_info_sym(tab[i]);
	  printf("%s\n", strtab + tab[i]->st_name);
	}
    }
  free(tab);
  return (1);
}
