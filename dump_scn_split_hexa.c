/*
** dump_scn_split_hexa.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 30 23:44:14 2008 caner candan
** Last update Sun Mar 30 23:44:44 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		dump_scn_split_hexa(void *s, unsigned char *str, int nb)
{
  Elf32_Shdr	*scn;
  unsigned int	i;

  scn = s;
  for (i = 0; i < 16; i++)
    {
      if ((nb + i) < scn->sh_size)
	printf(HEXA_CHAR, str[nb + i]);
      else
	printf("  ");
      if ((i % 4) == 3)
	printf(" ");
    }
}
