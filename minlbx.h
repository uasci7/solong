/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlbx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:55:45 by saksoy            #+#    #+#             */
/*   Updated: 2023/06/22 20:42:08 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINLBX_H
# define MINLBX_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"

typedef struct s_char
{
	int		l_x;
	int		l_y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_cur;
}	t_char;

typedef struct s_map
{
	char	**mappin;
	int		w;
	int		h;
	int		cb;
	int		gate_x;
	int		gate_y;
	int		p_cnt;
	int		end_cnt;
	int		coin_cnt;
}	t_map;

typedef struct s_win
{
	t_map	*map;
	t_char	*chr;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*block_bg;
	void	*c_bg;
	void	*end_bg;
	int		height;
	int		width;
	int		begin;
	int		begin2;
	char	**try;
}	t_win;

void	cbcc(char	*str,	t_map *map);
int		walk(int keycode, void *param);
void	retrycontrol(t_win *pnc, char **control);
void	putchr(t_win *pnc, int keycode);
char	*read_file(char	*path,	t_map	*map);
void	nullconl(char	*str);
t_map	*read_map(char *path);
void	move_control(char **tab, int begin, int begin2);
void	put_element(char c, t_win *pnc, int x, int y);
void	render_map(t_win *pnc);
int		close_frame(void *param);
void	player_control(t_win *pnc);
void	get_img(t_win *pnc, int x, int y);
void	wall_control(t_win *pnc);
void	map_size_control(t_win	*pnc);
void	end_control(t_win *pnc);
void	endln_control(char line);
void	coin_control(t_win *pnc);
void	file_control(char *path);
void	char_control(t_win *pnc);
void	xpm_control(void);
void	xpm_control_two(void);
void	path_checker(char *path);
#endif
