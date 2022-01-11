/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iferr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:06:20 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:06:24 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_iferr(int x, int y, t_vars *vars)
{
	if (vars->map[y][x] != '1' && vars->map[y][x] != '0'
		&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E'
		&& vars->map[y][x] != 'P' && vars->map[y][x] != 'X'
		&& vars->map[y][x] != '\n')
	{
		printf("Error.\nCheck your map");
		exit(0);
	}
	if (vars->map[0][x] != '1' || vars->map[y][0] != '1'
		|| vars->map[y][vars->lenmap - 1] != '1'
		|| vars->map[vars->heightmap][x] != '1')
	{
		printf("%c\n", vars->map[y][x]);
		printf("Error.\nMap no closed, or not complete");
		exit(0);
	}
}
