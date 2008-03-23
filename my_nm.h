/*
** nm.h for nm in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 22 11:29:44 2008 caner candan
** Last update Sun Mar 23 16:17:23 2008 caner candan
*/

#ifndef __NM_H__
# define __NM_H__

# define ERRMSG		"Error: %s\n"

/*
**
*/

int	file_open(char *file, int *length);
void	file_close(int fd);
void	*file_init(int fd, int length);
void	file_free(void *buf, int length);
void	file_type(void *buf);
void	*sct_get(void *buf, int type);

#endif /* !__NM_H__ */
