/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:18:30 by saksoy            #+#    #+#             */
/*   Updated: 2023/06/22 20:45:06 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

char	*read_file(char	*path,	t_map	*map)
{
	char	*line;
	char	*ret;
	int		fd;
	int		flag;

	fd = open(path, O_RDONLY);
	ret = NULL;
	flag = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (flag == 1)
		{
			nullconl(line);
			flag++;
		}
		if (!line)
			break ;
		endln_control(line[0]);
		cbcc(line, map);
		strappend(&ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

t_map	*read_map(char *path)
{
	t_map	*ret;
	char	*map;

	ret = ft_calloc(1, sizeof(t_map));
	map = read_file(path, ret);
	ret->mappin = ft_split(map, '\n');
	ret->h = 0;
	while (ret->mappin[ret->h])
		ret->h++;
	ret->w = ft_strlen(ret->mappin[0]);
	free(map);
	return (ret);
}

void	put_element(char c, t_win *pnc, int x, int y)
{
	mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->img_bg, x, y);
	if (c == 'P')
	{
		pnc->chr->l_x = x;
		pnc->chr->l_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->chr->chr_cur, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->block_bg, x, y);
	if (c == 'C')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->c_bg, x, y);
	if (c == 'E')
	{
		pnc->map->gate_x = x;
		pnc->map->gate_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->end_bg, x, y);
	}
}

void	put_score(t_win *pnc)
{
	char	*score;

	score = ft_itoa(pnc->chr->point);
	mlx_string_put(pnc->mlx, pnc->win, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	render_map(t_win *pnc)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		x = 0;
		while (pnc->map->mappin[i][j])
		{
			put_element(pnc->map->mappin[i][j++], pnc, x, y);
			put_score(pnc);
			x += 64;
		}
		i++;
		y = y + 64;
	}
}
