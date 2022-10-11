NAME = minishell
LIB	= ./lib/.minishell
SRC = main.c utils.c main_redirection.c redirection.c \
	heredoc_check.c

all: $(NAME)

$(NAME) : $(SRC)
	@make -sC ./libft
	@gcc $(SRC) -Wall -Wextra -Werror ./libft/libft.a  -lreadline  -o $(NAME) -g


clean:
	@make fclean -sC ./libft
	@rm -rf minishell

fclean : clean
	@echo "Cleaned!"

run: $(NAME)
	./$(NAME)
