/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:21:56 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 08:36:30 by abouhlel         ###   ########.fr       */
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

void	ft_union(char *str1, char *str2)
{
	char f[1000];
	int j = 0;
	
	f[j] = 0;
	for (int i = 0; str1[i] != 0; i++)
	{
		if (ft_search_c_in_str(s1[i], f) == 0)
		{
			f[j++] = s1[i];
			f[j] = 0;
		}
	}
	for (int i = 0; str2[i] != 0; i++)
	{
		if (ft_search_c_in_str(str2[i], f) == 0)
		{
			f[j++] = s2[i];
			f[j] = 0;
		}
	}
	ft_putstr(f);
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>
