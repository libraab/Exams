#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char	**TAB;

typedef struct s_draw
{
	char	t;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}			t_draw;

int		err_msg(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write(1, "Error: Operation file corrupted\n", 32);
	else if (err == 1)
		write(1, "Error: argument\n", 16);
	else
	{
		for (int i = 0; i < H; i++)
		{
			write (1, TAB[i], W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int		main(int ac, char **av)
{
	t_draw	draw;
	FILE	*fd;
	int		res;

	fd = 0;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(H * sizeof(char *));
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(W * sizeof(char));
					memset(TAB[i], BG, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %f %c",
						&draw.t, &draw.x, &draw.y, &draw.w, &draw.h, &draw.c);
					if (res == -1)
						return (err_msg(fd, 0));
					else if (res != 6 || (draw.t != 'r' && draw.t != 'R') || draw.h <= 0 || draw.w <= 0)
						break ;
					for (int line = 0; line < H; line++)
						for (int col = 0; col < W; col++)
						{
							if (draw.x <= col
							&& draw.y <= line
							&& col <= draw.x + draw.w
							&& line <= draw.y + draw.h)
							{
								if (draw.t == 'r'
									&&(line - draw.y < 1
									|| (draw.y + draw.h - line) < 1
									|| col - draw.x < 1
									|| draw.x + draw.w - col < 1))
									TAB[line][col] = draw.c;
								else if (draw.t == 'R')
									TAB[line][col] = draw.c;
							}
						}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}
