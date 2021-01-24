##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC_DIR 	:= ./my_printf/
SRC_NAMES	:= my_printf.c
SRC_NAMES	+= pf_base.c
SRC_NAMES	+= pf_def.c
SRC_NAMES	+= pf_smp.c
SRC			:= $(addprefix $(SRC_DIR), $(SRC_NAMES))
#------other------#
OBJ			:= $(SRC:.c=.o)
INC			:= $(realpath ./include/)
### SOURCES ###


### COMPILE_USEFULL ###
#----general_usefull----#
CC			=	gcc
#----project_usefull----#
NAME		=	my_printf.a
F_NAME		=	libmy.a
MAKEFLAGS 	+=	--no-print-directory
CFLAGS		:=	-Wall -Wextra
#CFLAGS		+=	-Werror
CFLAGS		+=	-iquote ./include/
### COMPILE_USEFULL ###


### COLORS ###
ccred		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\033[0m"
ccyellow	= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\033[0m"
ccend		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\033[0m"
### COLORS ###


all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -sC my/
			ar -x my/libmy.a
			ar -rc $(F_NAME) *.o $(OBJ)
			$(RM) -rf *.o

clean:
			$(MAKE) -sC my/ clean
			$(RM) -rf $(OBJ) $(MAIN_OBJ) $(UT_OBJ) $(NAME) *.gc* *.o *vgcore.*

fclean:		clean
			$(MAKE) -sC my/ fclean
			$(RM) -rf $(UT_NAME) $(F_NAME) a.out

re:			fclean all

.PHONY:		all tests_run utest clean fclean re