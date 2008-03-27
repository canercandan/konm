/*
** nm.c for my_nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 22 11:26:54 2008 caner candan
** Last update Wed Mar 26 18:56:08 2008 caner candan
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
  Elf32_Shdr	*scttab;
  Elf32_Sym	*sym;
  char		*strtab;
  char		*strtab2;
  int		i;

  if (ac < 2)
    return (0);
  fd = file_open(av[1], &length);
  buf = file_init(fd, length);
  file_type(buf);
  elf = buf;
  printf("entry: %08x, str idx: %d\n", elf->e_entry, elf->e_shstrndx);
  sct = buf + elf->e_shoff + (elf->e_shentsize * elf->e_shstrndx);
  strtab = buf + sct->sh_offset;
  sym = sct_get(buf, SHT_SYMTAB);
  scttab = sct_get(buf, SHT_STRTAB);
  printf("name: %d, type: %d\n", scttab->sh_name, scttab->sh_type);
  //strtab2 = buf + scttab->sh_offset;
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
	  //printf("string: %s\n", buf + prg->p_offset);
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
	      printf("idx name: %d, name: %s, type: %d, offset: %08x, link: %d\n",
		     sct->sh_name, strtab + sct->sh_name, sct->sh_type,
		     sct->sh_offset, sct->sh_link);
	    }
	  i++;
	}
    }
  file_free(buf, length);
  file_close(fd);
  return (0);
}
