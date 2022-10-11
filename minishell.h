#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"
#include <string.h>

typedef struct s_data
{
	char		*temp;
	char		**arg;//bütün argümanları burada almam lazım!
	char		**env_in;//bütün envleri burada almam lazım!
	char		**export;
	char		*cwd;
}			t_data;

typedef struct s_parse_data
{
    char    **commands;
	char	**flags;
    char    **redirections;

} parse_data;

typedef struct s_code
{
    char    **commands;
	char	**flags;
    char    **redirections;
	int		fd[2];
	pid_t	pid;
	char	*heredoc_str;
} t_code;

typedef	struct s_reach
{
	int			number_of_pipe;
	t_data		*data;
	parse_data	*parse_data;
	t_code		*code;
}				t_reach;


t_reach	*g_reach;

// main_redirection.c
void	main_redirection(void);

// redirection.c
void	redirection();

// check_heredoc.c
int	heredoc_check();

// utils.c
int		check_null_cmd(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcmp2(const char *s1, const char *s2);

#endif
