/*
** dump_scn_split_string.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 30 23:45:05 2008 caner candan
** Last update Mon Mar 31 00:11:09 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		dump_scn_split_string(void *s, unsigned char *str, int nb)
{
  Elf32_Shdr	*scn;
  unsigned int	i;

  scn = s;
  for (i = 0; i < 16; i++)
    {
      if ((nb + i) < scn->sh_size)
	{
	  if (str[nb + i] >= 32 && str[nb + i] < 127)
	    printf("%c", str[nb + i]);
	  else
	    printf(".");
	}
      else
	printf(" ");
    }
}
