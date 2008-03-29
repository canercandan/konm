/*
** file_type.c for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:40:11 2008 caner candan
** Last update Sat Mar 29 22:07:15 2008 caner candan
*/

#include "nm-objdump.h"
#include <elf.h>
#include <stdio.h>

void		file_type(void *buf)
{
  Elf32_Ehdr	*elf;
  int		type;

  elf = buf;
  type = elf->e_type;
  if (type == ET_REL)
    printf("Relocatable\n");
  else if (type == ET_EXEC)
    printf("Executable\n");
  else if (type == ET_DYN)
    printf("Shared object\n");
  else if (type == ET_CORE)
    printf("Core file\n");
  else
    printf("An unknown type\n");
}
