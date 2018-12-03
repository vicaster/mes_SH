/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sample_mker.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/02 13:39:04 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 17:49:15 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

char	*getpos(char *piece, int bytes)
{
	int		start;

	start = 0;
	if (bytes == 83)
		start = (rand() % 4);
	else if (bytes == 125)
		start = (rand() % 6);
	else if (bytes == 169)
		start = (rand() % 8);
	start *= 21;
	return (ft_strsub(piece, start, 20));
}

void	getpiece(int rgn)
{
	int		fd[19];
	int		bytes;
	char	*piece;

	if (!(piece = (char *)malloc(sizeof(char) * 169)))
		return ;
	fd[0] = open("/Users/widrye/Cursus/tetriminos/L_leg_0", O_RDONLY);
	fd[1] = open("/Users/widrye/Cursus/tetriminos/L_leg_1", O_RDONLY);
	fd[2] = open("/Users/widrye/Cursus/tetriminos/L_leg_2", O_RDONLY);
	fd[3] = open("/Users/widrye/Cursus/tetriminos/L_leg_3", O_RDONLY);
	fd[4] = open("/Users/widrye/Cursus/tetriminos/L_stairs_0", O_RDONLY);
	fd[5] = open("/Users/widrye/Cursus/tetriminos/L_stairs_1", O_RDONLY);
	fd[6] = open("/Users/widrye/Cursus/tetriminos/R_leg_0", O_RDONLY);
	fd[7] = open("/Users/widrye/Cursus/tetriminos/R_leg_1", O_RDONLY);
	fd[8] = open("/Users/widrye/Cursus/tetriminos/R_leg_2", O_RDONLY);
	fd[9] = open("/Users/widrye/Cursus/tetriminos/R_leg_3", O_RDONLY);
	fd[10] = open("/Users/widrye/Cursus/tetriminos/barre_0", O_RDONLY);
	fd[11] = open("/Users/widrye/Cursus/tetriminos/barre_1", O_RDONLY);
	fd[12] = open("/Users/widrye/Cursus/tetriminos/podium_0", O_RDONLY);
	fd[13] = open("/Users/widrye/Cursus/tetriminos/podium_1", O_RDONLY);
	fd[14] = open("/Users/widrye/Cursus/tetriminos/podium_2", O_RDONLY);
	fd[15] = open("/Users/widrye/Cursus/tetriminos/podium_3", O_RDONLY);
	fd[16] = open("/Users/widrye/Cursus/tetriminos/carre", O_RDONLY);
	fd[17] = open("/Users/widrye/Cursus/tetriminos/R_stairs_0", O_RDONLY);
	fd[18] = open("/Users/widrye/Cursus/tetriminos/R_stairs_1", O_RDONLY);

	bytes = read(fd[rgn], piece, 169);
	piece[bytes] = '\0';
	ft_putstr(getpos(piece, bytes));
	rgn = 0;
	while (rgn < 19)
		close(fd[rgn++]);
}

int		main(int ac, char **av)
{
	int		npiece;
	int		rgn;

	srand(time(NULL));
	if (ac != 2)
	{
		ft_putendl("usage: make sample [n pieces]");
		return (0);
	}
	npiece = ft_atoi(av[1]);
	if (npiece < 1 || npiece > 26)
	{
		ft_putendl("number of pieces must be between 1 and 26 !");
		return (0);
	}
	while (npiece--)
	{
		rgn = rand() % 19;
		getpiece(rgn);
		if (npiece)
			ft_putchar('\n');
	}
	return (0);
}
