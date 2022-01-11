/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_XC.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:04:10 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:04:21 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_xc(int x, int y, int flag, t_vars *vars)
{
	static int	z = 1;

	if (flag == 1)
	{
		if (z < 25)
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.coin, x * 51, y * 57);
		if (z > 25)
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.coin2, x * 51, y * 57);
		if (vars->heightmap > vars->check)
			vars->pickup++;
	}
	if (flag == 2)
	{
		if (z < 25)
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.enemy1, x * 51, y * 57);
		if (z > 25)
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.enemy2, x * 51, y * 57);
		z++;
	}
	if (z == 50)
		z = 1;
}
