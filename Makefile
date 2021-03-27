NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap

##### COLORS #####
BLUE = \033[1;35m
GREY = \033[3;31m
GREEN = \033[1;37m
RED = \033[1;31m
END = \033[0m

CHECKERPATH = ./d_checker
CHECKER = $(CHECKERPATH)/checker

PUSH_SWAP_PATH = ./d_push_swap
PUSH_SWAP = $(PUSH_SWAP_PATH)/push_swap


### RULES ###
.PHONY : $(NAME_CHECKER) $(NAME_PUSH_SWAP)

all : $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER):
	@make -C $(CHECKERPATH)
	@cp $(CHECKER) .

$(NAME_PUSH_SWAP):
	@make -C $(PUSH_SWAP_PATH)
	@cp $(PUSH_SWAP) .


### CLEAN ###
.PHONY : clean fclean re

clean :
	@make clean -C $(CHECKERPATH)
	@make clean -C $(PUSH_SWAP_PATH)

fclean : clean
	@make fclean -C $(CHECKERPATH)
	@rm -f $(NAME_CHECKER)
	@make fclean -C $(PUSH_SWAP_PATH)
	@rm -f $(NAME_PUSH_SWAP)

re : fclean all
