/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:50:48 by zarslan           #+#    #+#             */
/*   Updated: 2022/10/11 15:57:24 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_redirection(void)
{
	int	i;
	int	j;
	int	size;

	g_reach->parse_data->commands = (char **)malloc(sizeof(char *) * 3);
	g_reach->parse_data->redirections = (char **)malloc(sizeof(char *) * 3);
	g_reach->parse_data->flags = (char **)malloc(sizeof(char *) * 3);

	g_reach->parse_data->commands[0] = strdup("ls");
	g_reach->parse_data->redirections[0] = strdup("<< a > b");
	g_reach->parse_data->flags[0] = strdup("-l -a");

	g_reach->parse_data->commands[1] = strdup("cat a");
	g_reach->parse_data->redirections[1] = strdup(" ");
	g_reach->parse_data->flags[1] = strdup(" ");

	g_reach->parse_data->commands[2] = strdup("pwd");
	g_reach->parse_data->redirections[2] = strdup("> a << b");
	g_reach->parse_data->flags[2] = strdup(" ");


	i = 3;
	j = 0;
	g_reach->code = malloc(sizeof(t_code) * 3);
	while (j < i)
	{
		if (check_null_cmd(g_reach->parse_data->commands[j]) == 0)
			g_reach->code[j].commands = ft_split(g_reach->parse_data->commands[j], ' ');
		else 
		{
			g_reach->code[j].commands = malloc(sizeof(char));
			g_reach->code[j].commands[0] = "\0";
		}
		if (check_null_cmd(g_reach->parse_data->redirections[j]) == 0)
			g_reach->code[j].redirections = ft_split(g_reach->parse_data->redirections[j], ' ');
		else 
		{
			g_reach->code[j].redirections = malloc(sizeof(char));
			g_reach->code[j].redirections[0] = "\0";
		}

		if (check_null_cmd(g_reach->parse_data->flags[j]) == 0)
			g_reach->code[j].flags = ft_split(g_reach->parse_data->flags[j], ' ');
		else 
		{
			g_reach->code[j].flags = malloc(sizeof(char));
			g_reach->code[j].flags[0] = "\0";
		}
		j++;
	}


	printf("------------------\n");

	size = 0;
	while (size < i)
	{
	
		j = 0;
		printf("COMMANDS\n");
		while (g_reach->code[size].commands[j])
		{
			printf("%s\n", g_reach->code[size].commands[j]);
			j++;
		}
		j = 0;
		printf("REDIRECTIONS\n");
		while (g_reach->code[size].redirections[j])
		{
			printf("%s\n", g_reach->code[size].redirections[j]);
			j++;
		}
		j = 0;
		printf("FLAGS\n");
		while (g_reach->code[size].flags[j])
		{
			printf("%s\n", g_reach->code[size].flags[j]);
			j++;
		}
		printf("--------------\n");
		size++;
	}

	redirection();
}