/*
** file_elf.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 22:01:22 2008 caner candan
** Last update Sat Mar 29 22:07:05 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

void		file_elf(void *buf, char *file, char *name)
{
  Elf32_Ehdr	*elf;

  elf = buf;
  if (!IS_ELF(*elf))
    {
      printf(ERRFILE, name, file);
      exit(0);
    }
}
