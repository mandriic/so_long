/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:05:12 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:05:15 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_prints(int code, t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->heightmap != i)
		free(vars->map[++i]);
	free(vars->map);
	if (code == 0)
	{
		printf("%s\n", "You lose");
		exit(0);
	}
	if (code == 1)
	{
		printf("%s\n", "You win");
		exit(0);
	}
}
