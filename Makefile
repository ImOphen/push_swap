CSRC = instructions_core.c parsing_utils_three.c parsing_utils_two.c parsing_utils.c
PUSH_SWAP_SRC = $(CSRC) main.c instructions_one.c instructions_two.c instructions_three.c
CHECKER_SRC = $(CSRC) checker.c get_next_line.c checker_instructions.c checker_instructions_two.c checker_instructions_three.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=%.o)
CHECKER_OBJ = $(CHECKER_SRC:%.c=%.o)
PUSH_SWAP = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP)

$(CHECKER) : $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(CHECKER)

%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(CHECKER) $(PUSH_SWAP)

re : fclean all
