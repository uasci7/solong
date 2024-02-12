/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:30:34 by saksoy            #+#    #+#             */
/*   Updated: 2023/07/11 17:39:54 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

void	get_img(t_win *pnc, int x, int y)
{
	pnc->height = pnc->map->h * 64;
	pnc->width = pnc->map->w * 64;
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height, "Slime Game");
	pnc->chr = ft_calloc(1, sizeof(t_char));
	pnc->chr->l_x = 0;
	pnc->chr->l_y = 0;
	pnc->chr->point = 0;
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/front_char.xpm", &x, &y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/back_char.xpm", &x, &y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/right_char.xpm", &x, &y);
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/left_char.xpm", &x, &y);
	pnc->chr->chr_cur = pnc->chr->chr_front;
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/bg.xpm", &x, &y);
	pnc->block_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/block.xpm", &x, &y);
	pnc->c_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/coin.xpm", &x, &y);
	pnc->end_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/endgate.xpm", &x, &y);
}

char	**map_duplicator(t_win *pnc)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (pnc->map->h + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (pnc->map->mappin[i])
	{
		copy[i] = ft_strdup(pnc->map->mappin[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	open_windows(t_win *pnc, char *path)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	pnc->map = read_map(path);
	get_img(pnc, x, y);
	player_control(pnc);
	map_size_control(pnc);
	wall_control(pnc);
	end_control(pnc);
	char_control(pnc);
	coin_control(pnc);
	pnc->try = map_duplicator(pnc);
	move_control(pnc->try, pnc->begin, pnc->begin2);
	retrycontrol(pnc, pnc->try);
	while (pnc->try[i])
	{
		free(pnc->try[i]);
		i++;
	}
}

int	close_frame(void *param)
{
	t_win	*pnc;
	int		i;

	pnc = param;
	i = 0;
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->c_bg);
	mlx_destroy_image(pnc->mlx, pnc->end_bg);
	mlx_destroy_image(pnc->mlx, pnc->block_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	free(pnc->chr);
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	mlx_destroy_window(pnc->mlx, pnc->win);
	exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_win	pnc;

	if (argc == 2)
	{
		xpm_control();
		xpm_control_two();
		path_checker(argv[1]);
		file_control(argv[1]);
		open_windows(&pnc, argv[1]);
		render_map(&pnc);
		mlx_hook(pnc.win, 2, (1L << 0), walk, &pnc);
		mlx_hook(pnc.win, 17, 0, close_frame, &pnc);
		mlx_loop(pnc.mlx);
	}
	else
	{
		write(2, "missing argument", 17);
	}
	return (0);
}
