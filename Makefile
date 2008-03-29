##
## Makefile for my_nm in /home/candan_c/rendu/project/nm-objdump
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Sun Mar 23 12:57:34 2008 caner candan
## Last update Sat Mar 29 22:05:50 2008 caner candan
##

NM		=	my_nm
OD		=	my_objdump

SRC		=	file_open.c	\
			file_close.c	\
			file_init.c	\
			file_free.c	\
			file_type.c	\
			file_elf.c	\
			scn_get.c	\
			get_scn.c	\
			get_sym.c	\
			get_rel.c	\
			get_info_sym.c	\
			dump_scn.c	\
			dump_sym.c	\
			dump_prg.c	\
			sort_symtab.c	\
			fill_symtab.c

NM_SRC		=	my_nm.c		\
			$(SRC)

NM_OBJ		=	$(NM_SRC:.c=.o)

OD_SRC		=	my_objdump.c	\
			$(SRC)

OD_OBJ		=	$(OD_SRC:.c=.o)

INCLUDES	=	-I.
CFLAGS		=	$(INCLUDES) -g -Wall -W

CC		=	gcc
RM		=	rm -rf
MK		=	make

$(NM)		:	$(NM_OBJ)
			@$(CC) -o $@ $(NM_OBJ)

$(OD)		:	$(OD_OBJ)
			@$(CC) -o $@ $(OD_OBJ)

all		:
			@$(MK) $(NM)
			@$(MK) $(OD)

clean		:
			$(RM) *~
			$(RM) *.o

fclean		:	clean
			$(RM) $(NM)
			$(RM) $(OD)

re		:	fclean all

.PHONY		:	all clean fclean re
