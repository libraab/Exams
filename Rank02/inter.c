/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:21:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/03 11:21:52 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s)
{
	for(int i = 0; s[i] != 0; i++)
		write(1, &s[i], 1);
}

int ft_isset(char c, char *s)
{
	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int j = 0;
	char f[1000];
	
	f[j] = 0;
	for (int i = 0; s1[i] != 0; i++)
	{
		if (ft_isset(s1[i], s2) == 1)
		{
			if (ft_isset(s1[i], f) == 0)
			{
				f[j++] = s1[i];
				f[j] = 0;
			}
		}
	}
	ft_putstr(f);
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

// Exemples:
// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
