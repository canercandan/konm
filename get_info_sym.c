/*
** get_info_sym.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 13:47:06 2008 caner candan
** Last update Sat Mar 29 21:22:12 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		get_info_sym(void *tab)
{
  Elf32_Sym	*sym;
  int		info;
  int		bind;
  int		type;
  int		index;
  char		c;

  sym = tab;
  info = sym->st_info;
  bind = ELF32_ST_BIND(info);
  type = ELF32_ST_TYPE(info);
  index = sym->st_shndx;
  if (index == SHN_ABS)
    c = 'A';
  else if (type == 0)
    c = 'w';
  else if (index == SHN_UNDEF)
    c = 'U';
  else if (index == 0x2 || index == 0xe)
    c = 'R';
  else if (index == 0x13 || index == 0x14)
    c = 'B';
  else if (index >= 0x7 && index <= 0xb)
    c = 'T';
  else if (index == 0xc || index == 0xd
	   || index == 0x10 || index == 0x11
	   || index == 0x12 || index == 0xf)
    c = 'D';
  else
    c = '?';
  printf("%c ", (bind == 0 && c != '?' ? c + 0x20 : c));
}
