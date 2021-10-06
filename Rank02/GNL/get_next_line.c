/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:19:59 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 08:37:32 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int	get_next_line(char **line)
{
	int i = 0;
	int r;
	char c;
	char *str;

	str = malloc(sizeof(char) * 10000);
	*line = s;
	while ((r = read(0, &c, 1) > 0) && c != '\n' && c != 0)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	return (r);
}
