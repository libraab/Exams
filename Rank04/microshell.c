/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:10:23 by abouhlel          #+#    #+#             */
/*   Updated: 2022/01/18 15:24:00 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}

int ft_tablen(char **tab)
{
	int i = 0;
	while(tab[i])
		i++;
	return (i);
}

void freetab(char **tab)
{
	int i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void error(void)
{
	write(2, "error: fatal\n", 13);
	exit(1);
}

char *ft_strdup(char *s)
{
	int i = 0;
	char *s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if(!s2)
		error();
	while(s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int is_sep(char *s)
{
	if (!strcmp(s, "|") || !strcmp(s, ";"))
		return (1);
	return (0);
}

void cd(char **cmd)
{
	if(ft_tablen(cmd) != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if(chdir(cmd[1]) == 0)
		return ;
	write(2, "error: cannot change directory to ", 34);
	write(2, cmd[1], ft_strlen(cmd[1]));
	write(2, "\n", 1);
}

void tinyshell(char **av, char **env, int in)
{
	static int i = 1;
	int j = 0;
	int fds[2];
	int x;
	int next = STDIN_FILENO;
	char **cmd = malloc(sizeof(char *) * 100);
	if(!cmd)
		error();
	if(av[i] && sep(av[i]))
		i++;
	while(av[i] && !sep(av[i]))
	{
		cmd[j]= ft_strdup(av[i]);
		i++;
		j++;
	}
	cmd[j] = NULL;
	if(av[i] && !strcmp(av[i], "|"))
	{
		pipe(fds);
		x = fork();
		if(x < 0)
			error();
		if( x == 0)
		{
			dup2(in, STDIN_FILENO);
			dup2(fds[1], STDOUT_FILENO);
			if(!strcmp("cd", cmd[0]))
			{
				cd(cmd);
				exit(0);
			}
			if(execve(cmd[0], cmd, env) == -1)
			{
				write(2, "error: cannot execute ", 22);
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
		}
		close (fds[1]);
		next = fds[0];
	}
	else
	{
		x = fork();
		if(x < 0)
			error();
		if(x == 0)
		{
			dup2(in, STDIN_FILENO);
			if(!strcmp("cd", cmd[0]))
			{
				cd(cmd);
				exit(0);
			}
			if(execve(cmd[0], cmd, env) == -1)
			{
				write(2, "error: cannot execute ", 22);
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
		}
	}
	if(in != STDIN_FILENO)
		close (in);
	freetab(cmd);
	waitpid(0, NULL, 0);
	if (av[i])
		tinyshell(av, env, next);
}

int main(int ac, char **av, char **env)
{
	if (ac > 1)
		tinyshell(av, env, STDIN_FILENO);
	return 0;
}
