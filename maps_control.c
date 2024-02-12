/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:18:49 by saksoy            #+#    #+#             */
/*   Updated: 2023/06/22 20:45:13 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

void	player_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
			{
				pnc->map->p_cnt += 1;
				pnc->begin = i;
				pnc->begin2 = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (pnc->map->p_cnt != 1)
	{
		write(2, "Player Count Error", 19);
		close_frame(pnc);
	}
}

void	wall_control(t_win *pnc)
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' ||
			pnc->map->mappin[pnc->map->h - 1][i] != '1')
		{
			write(2, "Wall Error", 11);
			close_frame(pnc);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			write(2, "Wall Error", 11);
			close_frame(pnc);
		}
	}
}

void	map_size_control(t_win *pnc)
{
	int		i;
	size_t	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (ft_strlen(pnc->map->mappin[i]) != len)
		{
			write(2, "Line Size Error", 16);
			close_frame(pnc);
		}
		i++;
	}
}

void	end_control(t_win *pnc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'E')
			{
				pnc->map->end_cnt = pnc->map->end_cnt + 1;
			}
		}
		j = 0;
	}
	if (pnc->map->end_cnt != 1)
	{
		write (2, "End Door Count Error", 21);
		close_frame(pnc);
	}
}

void	cbcc(char	*str,	t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			map->cb = map->cb + 1;
		i++;
	}
}
