#include "minishell.h"

int	heredoc(char *neddle, int stdin_fd)
{
	char	*haystack;
	int		heredoc_fd[2];

	pipe(heredoc_fd);
	while (1)
	{
		haystack = readline(">");
		if (ft_strcmp2(haystack, neddle) == 0)
		{
			close(heredoc_fd[0]);
			close(heredoc_fd[1]);
			dup2(heredoc_fd[0], stdin_fd);
			return 0;
		}
		ft_putendl_fd(haystack, heredoc_fd[1]);
		free(haystack);
	}
	exit(0);
}

int	heredoc_check()
{
	int		i;
	int		j;

	i = 0;
	while (i <= g_reach->number_of_pipe)
	{
		j = 0;
		while (g_reach->code[i].redirections[j])
		{
			if (ft_strcmp(g_reach->code[i].redirections[j], "<<") == 0)
			{
				heredoc(g_reach->code[i].redirections[++j], g_reach->code[i].fd[0]);
			}
			j++;
		}
		i++;
	}
	return (0);
}