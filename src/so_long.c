/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:04:52 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:04:55 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_p(int x, int y, t_vars *vars)
{
	if (vars->graf.x == -1)
	{
		vars->graf.x = x * 51;
		vars->graf.y = y * 57;
	}
}

int	key_hook_fn(int keycode, t_vars *vars)
{
	static int	q = 0;
	int			x;
	int			y;

	x = vars->graf.x / 51;
	y = vars->graf.y / 57;
	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		vars->step++;
	printf("Steps :%d\n", vars->step);
	if (keycode == 2)
		ft_keycode_2(q, vars, &x, &y);
	if (keycode == 0)
		ft_keycode_0(q, vars, &x, &y);
	if (keycode == 13)
		ft_keycode_13(q, vars, &x, &y);
	if (keycode == 1)
		ft_keycode_1(q, vars, &x, &y);
	if (++q == 2)
		q = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->wind);
		exit(0);
	}
	return (0);
}

void	ft_parsing_x(int y, t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->map[y][x] != '\n')
	{
		mlx_put_image_to_window(vars->mlx, vars->wind,
			vars->graf.img2pr.grass, x * 51, y * 57);
		if (vars->map[y][x] == '1')
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.wall, x * 51, y * 57);
		if (vars->map[y][x] == 'P')
			ft_init_p(x, y, vars);
		if (vars->map[y][x] == 'C')
			ft_parsing_xc(x, y, 1, vars);
		if (vars->map[y][x] == 'X')
			ft_parsing_xc(x, y, 2, vars);
		if (vars->map[y][x] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->wind,
				vars->graf.img2pr.exit, x * 51, y * 57);
		ft_iferr(x, y, vars);
		mlx_put_image_to_window(vars->mlx, vars->wind,
			vars->graf.img_2_print, vars->graf.x, vars->graf.y);
		x++;
	}
}

int	loop_hook(t_vars *vars)
{
	char	*print;
	int		y;

	y = -1;
	mlx_clear_window(vars->mlx, vars->wind);
	while (vars->map[++y] != 0)
	{
		ft_parsing_x(y, vars);
		if (ft_strlen(vars->map[0]) != ft_strlen(vars->map[y]))
		{
			printf("Error.\nCheck your map1");
			exit(0);
		}
		if (vars->heightmap > vars->check)
		vars->check++;
	}
	print = ft_itoa(vars->step);
	mlx_string_put(vars->mlx, vars->wind, 10, 10, 0x00FFFFFF, "STEPS: ");
	mlx_string_put(vars->mlx, vars->wind, 60, 10, 0x00FFFFFF, print);
	free(print);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
		ft_open_map(argv[1], &vars);
	else
	{
		printf("App need one map *.ber");
		exit(0);
	}
	vars.lenmap = ft_strlen (vars.map[0]) - 1;
	vars.pickup = 0;
	vars.step = 0;
	vars.mlx = mlx_init();
	vars.wind = mlx_new_window(vars.mlx, vars.lenmap * 51,
			(vars.heightmap + 1) * 57, "so_long");
	ft_open_images(&vars);
	vars.graf.y = 0;
	vars.graf.x = -1;
	vars.check = 0;
	vars.graf.img_2_print = vars.graf.img2pr.boy1;
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_hook(vars.wind, 2, 0, key_hook_fn, &vars);
	mlx_loop(vars.mlx);
}
