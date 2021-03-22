NAME = ps_instructions.a

##### COLORS #####
BLUE = \033[1;36m
RED = \033[1;33m
END = \033[0m

##### FLAG #####
CC = clang
FLAGS = -Wall -Wextra -Werror

DEPS = instructions_ps.h

## SRC & OBJ PATH ##
LIBFTPATH = ../libft
SRCPATH = .
OBJDIR = obj

##### INCLUDE #####
INC_LIBFT = $(LIBFTPATH)

##### LIB #####
LIBFT = $(LIBFTPATH)/libft.a

##### SRCS #####
SRC = $(addprefix $(SRCPATH)/, ft_create_two_stacks.c ft_push.c \
	  ft_stack_utils.c convert_argv_to_int_array.c fill_stack_with_int_array.c \
	  ft_pop.c ps_swap.c ps_push.c)

##### OBJS #####
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)



all : mk_objdir mk_libft $(NAME)

mk_objdir :
	@if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi

mk_libft :
	@if [ ! -f $(LIBFT) ]; then make -C $(LIBFTPATH); fi

$(NAME) : message $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(BLUE)$@ is built !$(END)"

message :
	@echo "\n$(BLUE)Building $(NAME) objects$(END)"

$(OBJDIR)/%.o : $(SRCPATH)/%.c $(DEPS)
	$(CC) $(FLAGS) -I $(INC_LIBFT) -c $< -o $@



.PHONY : clean
clean :
	@rm -rf $(OBJ)
	@echo "$(RED)$(NAME) objects removed.$(END)"
	@make clean -C $(LIBFTPATH)

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed.$(END)"
	@make fclean -C $(LIBFTPATH)

re : fclean all
