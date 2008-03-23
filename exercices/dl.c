/*
** dl.c for dl in /home/candan_c/rendu/project/nm-objdump/exercices
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Mar 20 19:37:04 2008 caner candan
** Last update Thu Mar 20 19:45:33 2008 caner candan
*/

#include <stdio.h>
#include <dlfcn.h>

int	main(int ac, char **av)
{
  void	*handle;
  void	(*f1)();
  void	(*f2)();
  char	*error;

  if (ac < 2)
    return (0);
  if (!(handle = dlopen(av[1], RTLD_LAZY)))
    {
      fputs(dlerror(), stderr);
      fprintf(stderr, "Error: %s\n", dlerror());
      exit(1);
    }
  f1 = dlsym(handle, "coco");
  f2 = dlsym(handle, "about");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "Error: %s\n", error);
      exit(1);
    }
  f2();
  f1();
  return (0);
}
