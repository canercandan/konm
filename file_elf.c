/*
** file_elf.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 29 22:01:22 2008 caner candan
** Last update Sun Mar 30 00:53:55 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>
#include <string.h>

int		file_elf(void *buf, char *file, char *name)
{
  Elf32_Ehdr	*elf;

  elf = buf;
  if (!IS_ELF(*elf))
    {
      printf(ERRFILE, name, file);
      return (0);
    }
  if (!strcmp(name, NAME_OD))
    printf(HEADER_FILE, file,
	   get_class(elf->e_ident[EI_CLASS]),
	   get_machine(elf->e_machine),
	   get_os(elf->e_ident[EI_OSABI]));
  return (1);
}
