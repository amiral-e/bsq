##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC_DIR 	:= ./src/
SRC_NAMES	:= bsq.c
SRC_NAMES	+= c_errors.c
SRC_NAMES	+= s_values.c
SRC_NAMES	+= m_disp.c
SRC			:= $(addprefix $(SRC_DIR), $(SRC_NAMES))
#------other------#
OBJ			:= $(SRC:.c=.o)
INC			:= $(realpath ./include/)
#----tests_sources----#
#UT_SRC		:= tests/test_my_printf.c
### SOURCES ###


### COMPILE_USEFULL ###
#----general_usefull----#
CC			=	gcc
#----project_usefull----#
NAME		=	bsq
F_NAME		=	libmy.a
MAKEFLAGS 	+=	--no-print-directory
CFLAGS		:=	-Wall -Wextra
#CFLAGS		+=	-Werror
CFLAGS		+=	-iquote ./include/ -iquote ./lib/include/
#----unit_test_usefull----#
UT_NAME		=	testbin
UT_FLAGS	=	--coverage -lcriterion
LFLAGS		=	-L ./lib/ -lmy
### COMPILE_USEFULL ###


### COLORS ###
ccred		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\033[0m"
ccyellow	= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\033[0m"
ccend		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\033[0m"
### COLORS ###


### RULES_USEFULL ###
GCOVR		=	gcovr --exclude tests/
### RULES_USEFULL ###


all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -sC lib/
			$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
			@$(call ccend, "Project successfully compiled.")

tests_run:	$(UT_NAME)
$(UT_NAME):
			$(MAKE) -sC lib/
			$(CC) $(CFLAGS) $(UT_FLAGS) -o $(UT_NAME) $(SRC) $(UT_SRC) $(LFLAGS)
			@$(call ccend, "Unit tests successfully compiled.")
			./$(UT_NAME)

utest:		tests_run
			$(GCOVR)
			$(GCOVR) --branche
			$(RM) *.gc* $(UT_NAME)

clean:
			$(MAKE) -sC lib/ clean
			$(RM) -r $(OBJ) $(MAIN_OBJ) $(UT_OBJ) *.gc* *.o *vgcore.*
			@$(call ccyellow, "Project cleaned.")

fclean:		clean
			$(MAKE) -sC lib/ fclean
			$(RM) -r $(UT_NAME) $(F_NAME) $(NAME) a.out
			@$(call ccred, "Project fully cleaned.")

re:			fclean all

.PHONY:		all tests_run utest clean fclean re