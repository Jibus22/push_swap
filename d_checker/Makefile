NAME = checker


##### COLORS #####
BLUE = \033[1;35m
GREY = \033[3;31m
GREEN = \033[1;37m
RED = \033[1;31m
END = \033[0m



##### SRC & OBJ PATH #####
LIBFTPATH = ../libft
PS_INSTRUCTIONS_PATH = ../instructions
SRCPATH = .
OBJPATH = $(SRCPATH)/obj

##### INCLUDE #####
INC_CHECKER = .
INC_INSTRUCTIONS = $(PS_INSTRUCTIONS_PATH)
INC_LIBFT = $(LIBFTPATH)

##### INCLUDES DEPENDENCIES  ---  any modif in any .h will alert makefile to compile again
INC_DEP = $(INC_CHECKER)/*.h

##### LIB #####
LIBFT = $(LIBFTPATH)/libft.a
PS_INSTRUCTIONS = $(PS_INSTRUCTIONS_PATH)/ps_instructions.a

##### FLAG #####
CC = clang
FLAGS = -Wall -Wextra -Werror #-g# -fsanitize=address

##### OSTYPE #####
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# mac
	FLAGS += -D DARWIN
else
	#Linus and others...
	FLAGS += -D LINUX
endif

##### SRCS #####
SRCS = $(addprefix $(SRCPATH)/, checker.c execute_instructions.c \
	   verify_instructions.c check_stacks.c)

OBJ = $(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)


### RULES ###

all : mk_objdir mk_instructions $(NAME)


mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

mk_instructions :
	@echo "\n$(END)$(BLUE)# Checking ps_instructions lib #$(END)$(GREY)"
	@make -C $(PS_INSTRUCTIONS_PATH)


$(NAME) : message $(OBJ) $(INC_DEP)
	@echo "\n$(END)$(BLUE)# Making $(NAME) #$(END)$(GREY)"
	$(CC) -o $@ $(OBJ) $(LIBFT) $(PS_INSTRUCTIONS)
	@echo "\n$(END)$(GREEN)# $(NAME) is built #$(END)"

message :
	@echo "\n$(END)$(BLUE)# Making $(NAME) objects #$(END)$(GREY)"


$(OBJPATH)/%.o : $(SRCPATH)/%.c $(INC_DEP)
	$(CC) $(FLAGS) -I $(INC_LIBFT) -I $(INC_CHECKER) \
	-I $(INC_INSTRUCTIONS) -c $< -o $@


### CLEAN ###
.PHONY : clean fclean re

clean :
	@echo "$(END)$(RED)# removing $(NAME) objects #$(END)$(GREY)"
	rm -rf $(OBJ)
	@make clean -C $(PS_INSTRUCTIONS_PATH)

fclean : clean
	@echo "$(END)$(RED)\n# removing $(NAME) #$(END)$(GREY)"
	@rm -f $(NAME)
	@make fclean -C $(PS_INSTRUCTIONS_PATH)

re : fclean all
