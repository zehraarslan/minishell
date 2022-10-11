#include "minishell.h"

void	init_pipe()
{
	int	i;

	i = -1;
	while (++i < g_reach->number_of_pipe)
		pipe(g_reach->code[i].fd);
	
}

void	process(int i)
{
	g_reach->code[i].pid = fork();
	if (g_reach->code[i].pid == -1)
		printf("Error");
	if (g_reach->code[i].pid == 0)
	{
		
	}
}

void	redirection()
{
	int	i;
	int	status;

	status = 0;
	init_pipe();
	heredoc_check();

	i = 0;
	while (i <= g_reach->number_of_pipe)
	{
		process(i);
	}
	

}