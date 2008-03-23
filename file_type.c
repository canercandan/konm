/*
** file_type.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Mar 23 13:40:11 2008 caner candan
** Last update Sun Mar 23 15:05:51 2008 caner candan
*/

#include "my_nm.h"
#include <elf.h>
#include <stdio.h>

void		file_type(void *buf)
{
  Elf32_Ehdr	*elf;
  elf = buf;

  if (elf->e_type == ET_REL)
    printf("A relocatable file\n");
  else if (elf->e_type == ET_EXEC)
    printf("An executable file\n");
  else if (elf->e_type == ET_CORE)
    printf("A core file\n");
  else
    printf("An unknown type\n");
}
