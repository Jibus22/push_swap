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

all : mk_checker mk_push_swap


mk_checker:
	@if [ ! -f $(CHECKER) ]; then make -C $(CHECKERPATH); fi
	@cp $(CHECKER) .

mk_push_swap:
	@if [ ! -f $(PUSH_SWAP) ]; then make -C $(PUSH_SWAP_PATH); fi
	@cp $(PUSH_SWAP) .


### CLEAN ###
.PHONY : clean fclean re

clean :
	@make clean -C $(CHECKERPATH)
	@make clean -C $(PUSH_SWAP_PATH)

fclean : clean
	@make fclean -C $(CHECKERPATH)
	@rm -f checker
	@make fclean -C $(PUSH_SWAP_PATH)
	@rm -f push_swap

re : fclean all
