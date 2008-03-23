/*
** nm.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 22 11:26:54 2008 caner candan
** Last update Sun Mar 23 18:13:45 2008 caner candan
*/

#include "my_nm.h"
#include <elf.h>
#include <stdio.h>

int		main(int ac, char **av)
{
  int		fd;
  int		length;
  void		*buf;
  Elf32_Ehdr	*elf;
  Elf32_Phdr	*prg;
  Elf32_Shdr	*sct;
  char		*strtab;
  char		*symtab;
  int		i;

  if (ac < 2)
    return (0);
  fd = file_open(av[1], &length);
  buf = file_init(fd, length);
  file_type(buf);
  elf = buf;
  printf("entry: %08x\n", elf->e_entry);
  sct = buf + elf->e_shoff + (elf->e_shentsize * elf->e_shstrndx);
  strtab = buf + sct->sh_offset;
  symtab = sct_get(buf, SHT_SYMTAB);
  printf("strtab: %s\n", strtab + 1);
  printf("prg addr: %08x, size: %d, num: %d\n",
	 elf->e_phoff, elf->e_phentsize, elf->e_phnum);
  if (elf->e_phoff)
    {
      i = 0;
      while (i < elf->e_phnum)
	{
	  prg = buf + elf->e_phoff + (elf->e_phentsize * i);
	  printf("type: %d, offset: %08x\n",
		 prg->p_type, prg->p_offset);
	  i++;
	}
    }
  printf("sct addr: %08x, size: %d, num: %d\n",
	 elf->e_shoff, elf->e_shentsize, elf->e_shnum);
  if (elf->e_shoff)
    {
      i = 0;
      while (i < elf->e_shnum)
	{
	  sct = buf + elf->e_shoff + (elf->e_shentsize * i);
	  if (sct->sh_type != SHT_NULL)
	    {
	      printf("name: %s, type: %d, offset: %08x\n",
		     strtab + sct->sh_name, sct->sh_type, sct->sh_offset);
	    }
	  i++;
	}
    }
  file_free(buf, length);
  file_close(fd);
  return (0);
}
