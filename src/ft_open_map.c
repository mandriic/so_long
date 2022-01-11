/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:05:46 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:05:48 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_map(char *argv, t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", "Error. Check root to map *.ber");
		exit(0);
	}
		vars->map = malloc (sizeof(char *) * 1000);
	i = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		vars->map[++i] = line;
	}
	free(line);
	vars->heightmap = i;
	vars->map[++i] = 0;
	close(fd);
}
