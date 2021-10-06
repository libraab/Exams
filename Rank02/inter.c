/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:21:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 08:34:40 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	for(int i = 0; str[i] != 0; i++)
		write(1, &str[i], 1);
}

int ft_search_c_in_str(char c, char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

void	ft_inter(char *str1, char *str2)
{
	int j = 0;
	char f[1000];
	
	f[j] = 0;
	for (int i = 0; str1[i] != 0; i++)
	{
		if (ft_search_c_in_str(str1[i], str2) == 1)
		{
			if (ft_search_c_in_str(str1[i], f) == 0)
			{
				f[j++] = str1[i];
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
