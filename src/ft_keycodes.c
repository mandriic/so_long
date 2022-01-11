/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:06:39 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:06:43 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keycode_2(int q, t_vars *vars, int *x, int *y)
{
	if (vars->map[*y][*x + 1] != '1')
	{
		vars->graf.x = vars->graf.x + 51;
		if (vars->map[*y][*x + 1] == 'X')
			ft_prints(0, vars);
		if (vars->map[*y][*x + 1] == 'E' && vars->pickup == 0)
			ft_prints(1, vars);
		if (vars->map[*y][*x + 1] == 'C')
		{
			vars->map[*y][*x + 1] = '0';
			vars->pickup--;
		}
		if (q == 0)
			vars->graf.img_2_print = vars->graf.img2pr.boy2;
		else if (q == 1)
			vars->graf.img_2_print = vars->graf.img2pr.boy3;
	}
}

void	ft_keycode_0(int q, t_vars *vars, int *x, int *y)
{
	if (vars->map[*y][*x - 1] != '1')
	{	
		if (vars->map[*y][*x - 1] == 'X')
			ft_prints(0, vars);
		if (vars->map[*y][*x - 1] == 'E' && vars->pickup == 0)
			ft_prints(1, vars);
		if (vars->map[*y][*x - 1] == 'C')
		{
			vars->map[*y][*x - 1] = '0';
			vars->pickup--;
		}		
		vars->graf.x = vars->graf.x - 51;
		if (q == 0)
			vars->graf.img_2_print = vars->graf.img2pr.boy5;
		else if (q == 1)
			vars->graf.img_2_print = vars->graf.img2pr.boy8;
	}
}

void	ft_keycode_13(int q, t_vars *vars, int *x, int *y)
{
	if (vars->map[*y - 1][*x] != '1')
	{
		if (vars->map[*y - 1][*x] == 'X')
			ft_prints(0, vars);
		if (vars->map[*y - 1][*x] == 'E' && vars->pickup == 0)
			ft_prints(1, vars);
		if (vars->map[*y - 1][*x] == 'C')
		{
			vars->map[*y - 1][*x] = '0';
			vars->pickup--;
		}	
		vars->graf.y = vars->graf.y - 57;
		if (q == 0)
			vars->graf.img_2_print = vars->graf.img2pr.boy1;
		else if (q == 1)
			vars->graf.img_2_print = vars->graf.img2pr.boy4;
	}
}

void	ft_keycode_1(int q, t_vars *vars, int *x, int *y)
{
	if (vars->map[*y + 1][*x] != '1')
	{	
		if (vars->map[*y + 1][*x] == 'X')
			ft_prints(0, vars);
		if (vars->map[*y + 1][*x] == 'E' && vars->pickup == 0)
			ft_prints(1, vars);
		if (vars->map[*y + 1][*x] == 'C')
		{
			vars->map[*y + 1][*x] = '0';
			vars->pickup--;
		}
		vars->graf.y = vars->graf.y + 57;
		if (q == 0)
			vars->graf.img_2_print = vars->graf.img2pr.boy5;
		else if (q == 1)
			vars->graf.img_2_print = vars->graf.img2pr.boy7;
	}
}
