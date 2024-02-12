/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:18:41 by saksoy            #+#    #+#             */
/*   Updated: 2023/06/22 23:53:04 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

void	xpm_control(void)
{
	int	fd_back;
	int	fd_bg;
	int	fd_block;
	int	fd_coin;

	fd_back = open("./img/back_char.xpm", O_RDWR);
	fd_bg = open("./img/bg.xpm", O_RDWR);
	fd_block = open("./img/block.xpm", O_RDWR);
	fd_coin = open("./img/coin.xpm", O_RDWR);
	if (fd_back <= 0 || fd_bg <= 0 || fd_block <= 0 || fd_coin <= 0)
	{
		write(2, "Missing XPM File\n", 18);
		close(fd_back);
		close(fd_bg);
		close(fd_block);
		close(fd_coin);
		exit(1);
	}
	close(fd_back);
	close(fd_bg);
	close(fd_block);
	close(fd_coin);
}

void	xpm_control_two(void)
{
	int	fd_endgate;
	int	fd_front;
	int	fd_left;
	int	fd_right;

	fd_endgate = open("./img/endgate.xpm", O_RDWR);
	fd_front = open("./img/front_char.xpm", O_RDWR);
	fd_left = open("./img/left_char.xpm", O_RDWR);
	fd_right = open("./img/right_char.xpm", O_RDWR);
	if (fd_endgate <= 0 || fd_front <= 0 || fd_left <= 0 || fd_right <= 0)
	{
		write(2, "Missing XPM File\n", 18);
		close(fd_endgate);
		close(fd_front);
		close(fd_left);
		close(fd_right);
		exit(1);
	}
	close(fd_endgate);
	close(fd_front);
	close(fd_left);
	close(fd_right);
}

void	path_checker(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(2, "Wrong File Extension", 21);
		exit(1);
	}
}

void	retrycontrol(t_win *pnc, char **control)
{
	int		i;
	int		j;
	int		ccount;
	int		k;

	i = -1;
	k = -1;
	j = -1;
	ccount = 0;
	while (control[++i])
	{
		while (control[i][++j])
		{
			if (control[i][j] == 'C' || control[i][j] == 'E')
				ccount++;
		}
		j = 0;
	}
	if (ccount > 0)
	{
		write(2, "Invalid Path", 12);
		while (pnc->try[++k])
			free(pnc->try[k]);
		close_frame(pnc);
	}
}

void	nullconl(char	*str)
{
	if (str == (void *) '\0')
	{
		ft_putstr_fd("MAP NULL\n", 2);
		exit(1);
	}
}
