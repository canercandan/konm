/*
** dump_scn_split.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 30 17:19:48 2008 caner candan
** Last update Sun Mar 30 23:45:09 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		dump_scn_split(void *buf, void *s)
{
  Elf32_Shdr	*scn;
  unsigned char	*str;
  unsigned int	i;

  scn = s;
  str = buf + scn->sh_offset;
  for (i = 0; i < scn->sh_size; i += 16)
    {
      printf(ADDR_STR, scn->sh_addr + i);
      dump_scn_split_hexa(scn, str, i);
      printf(" ");
      dump_scn_split_string(scn, str, i);
      printf("\n");
    }
}
