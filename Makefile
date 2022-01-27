NAME = gnl.out

SRC = main.c get_next_line.c

# Add /-g/ flag for lldb debugging.
FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

all: $(NAME)

$(NAME):
		@echo "Creating and linking the libft.a library file"
		@make -s -C libft
		@echo "\nCompiling the executable 'gnl.out'"
		@gcc $(FLAGS) -o $(NAME) $(SRC) -I libft $(LIB)
		@echo "Finished.\n"

clean:
		@echo "Deleting library object files"
		@make -s -C libft clean
		@echo "Done."

fclean: clean
		@echo "\nExecuting rule: fclean"
		@make -s -C libft fclean
		@echo "\nRemoving $(NAME) output file"
		@rm -r $(NAME)
		@echo "Finished.\n"

run:
		@./$(NAME)

re: fclean all

.PHONY: all clean fclean re
