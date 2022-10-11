#include "minishell.h"


int	main(int ac, char **av, char **env)
{
	g_reach = malloc(sizeof(t_reach));
	g_reach->data = malloc(sizeof(t_data));
	g_reach->parse_data = malloc(sizeof(parse_data));
	//ft_copy_env(env);

  	g_reach->number_of_pipe = 2;
	g_reach->data->env_in = env;
 
    //add_history(g_reach->data->temp);
    //ft_parser(ac, av);//Tarık
   	main_redirection();//Zehra
	(void)ac;
	(void)av;
  
  //system("leaks minishell");
  return (0);
}
