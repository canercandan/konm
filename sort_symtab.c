/*
** sort_symtab.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri Mar 28 21:15:41 2008 caner candan
** Last update Sat Mar 29 21:22:36 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <string.h>

void		**sort_symtab(void **sym, char *strtab)
{
  Elf32_Sym	**tab;
  Elf32_Sym	*tmp;
  int		i;

  tab = (void *) sym;
  for (i = 0; tab[i]; i++)
    {
      if (tab[i] && tab[i + 1])
	{
	  if (strcmp(strtab + tab[i]->st_name,
		     strtab + tab[i + 1]->st_name) > 0)
	    {
	      tmp = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = tmp;
	      i = -1;
	    }
	}
    }
  return ((void *) tab);
}
