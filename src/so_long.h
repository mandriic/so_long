/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:04:39 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:04:46 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct grafimage_idnf
{
	void	*grass;
	void	*enemy1;
	void	*enemy2;
	void	*exit;
	void	*coin;
	void	*coin2;
	void	*wall;
	void	*boy1;
	void	*boy2;
	void	*boy3;
	void	*boy4;
	void	*boy5;
	void	*boy6;
	void	*boy7;
	void	*boy8;
}t_grafimage;
typedef struct graf_idnf
{
	t_grafimage	img2pr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	void		*img_2_print;
}t_graf;
typedef struct var_idnf
{
	void	*mlx;
	void	*wind;
	t_graf	graf;
	char	**map;
	int		lenmap;
	int		heightmap;
	int		pickup;
	int		step;
	int		check;
}t_vars;
void	ft_parsing_x(int y, t_vars *vars);
void	ft_iferr(int x, int y, t_vars *vars);
void	ft_keycode_2(int q, t_vars *vars, int *x, int *y);
void	ft_keycode_0(int q, t_vars *vars, int *x, int *y);
void	ft_keycode_13(int q, t_vars *vars, int *x, int *y);
void	ft_keycode_1(int q, t_vars *vars, int *x, int *y);
void	ft_open_images(t_vars *vars);
void	ft_open_map(char *argv, t_vars *vars);
void	ft_parsing_xc(int x, int y, int flag, t_vars *vars);
void	ft_prints(int code, t_vars *vars);
#endif
