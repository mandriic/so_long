/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:05:58 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:06:00 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_img_norm_die(t_vars *vars, char *str)
{
	int		w;
	int		h;
	void	*temp;

	temp = mlx_xpm_file_to_image(vars->mlx, str, &w, &h);
	return (temp);
}

void	ft_open_images(t_vars *vars)
{
		vars->graf.img2pr.wall = ft_img_norm_die(vars, "./xpm/wall.xpm");
		vars->graf.img2pr.boy1 = ft_img_norm_die(vars, "./xpm/000.xpm");
		vars->graf.img2pr.boy2 = ft_img_norm_die(vars, "./xpm/001.xpm");
		vars->graf.img2pr.boy3 = ft_img_norm_die(vars, "./xpm/002.xpm");
		vars->graf.img2pr.boy4 = ft_img_norm_die(vars, "./xpm/003.xpm");
		vars->graf.img2pr.boy5 = ft_img_norm_die(vars, "./xpm/004.xpm");
		vars->graf.img2pr.boy6 = ft_img_norm_die(vars, "./xpm/005.xpm");
		vars->graf.img2pr.boy7 = ft_img_norm_die(vars, "./xpm/006.xpm");
		vars->graf.img2pr.boy8 = ft_img_norm_die(vars, "./xpm/007.xpm");
		vars->graf.img2pr.coin = ft_img_norm_die(vars, "./xpm/coin.xpm");
		vars->graf.img2pr.coin2 = ft_img_norm_die(vars, "./xpm/coin2.xpm");
		vars->graf.img2pr.exit = ft_img_norm_die(vars, "./xpm/exit.xpm");
		vars->graf.img2pr.enemy1 = ft_img_norm_die(vars, "./xpm/enemy1.xpm");
		vars->graf.img2pr.enemy2 = ft_img_norm_die(vars, "./xpm/enemy2.xpm");
		vars->graf.img2pr.grass = ft_img_norm_die(vars, "./xpm/grass.xpm");
}
