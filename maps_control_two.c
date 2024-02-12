/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:28:23 by saksoy            #+#    #+#             */
/*   Updated: 2023/06/22 20:27:51 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

void	endln_control(char line)
{
	if (line == '\n')
	{
		write(2, "Empty Line In Map", 18);
		exit(1);
	}
}

void	coin_control(t_win *pnc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt = pnc->map->coin_cnt + 1;
		}
		j = 0;
	}
	if (pnc->map->coin_cnt <= 0)
	{
		write(2, "Not Found Coin in Map", 22);
		close_frame(pnc);
	}
}

void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(2, "Wrong File Path", 16);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	char_control(t_win *pnc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] != '0'
				&& pnc->map->mappin[i][j] != '1'
				&& pnc->map->mappin[i][j] != 'P'
				&& pnc->map->mappin[i][j] != 'C'
				&& pnc->map->mappin[i][j] != 'E')
			{
				write(2, "Undefined Char", 15);
				close_frame(pnc);
			}
		}
		j = 0;
	}
}

void	move_control(char **tab, int begin, int begin2)
{
	if (begin < 0 || begin2 < 0)
		return ;
	if (tab[begin][begin2] == '1' || tab[begin][begin2] == 'F')
		return ;
	tab[begin][begin2] = 'F';
	move_control(tab, begin - 1, begin2);
	move_control(tab, begin + 1, begin2);
	move_control(tab, begin, begin2 - 1);
	move_control(tab, begin, begin2 + 1);
}
