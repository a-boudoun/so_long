/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:03 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/14 20:10:43 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	render_exit(t_program *program, int i, int j)
{
	if (program->map.count)
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.exit_no, i * HEIGHT, j * WIDTH);
	else
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.exit_yes, i * HEIGHT, j * WIDTH);
}

static void	render_program(t_program *program, int i, int j)
{
	if (program->map.map[i][j] == '1')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.wall, i * HEIGHT, j * WIDTH);
	if (program->map.map[i][j] == '0')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.floor, i * HEIGHT, j * WIDTH);
	// if (program->map.map[i][j] == 'P')
	// 	render_player(program, i, j);
	if (program->map.map[i][j] == 'C')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.collect, i * HEIGHT, j * WIDTH);
	if (program->map.map[i][j] == 'E')
		render_exit(program, i, j);
}

void	render_game(t_program *program)
{
	int	i;
	int	j;

	j = 0;
	while (j < program->map.column)
	{
		i = 0;
		while (i < program->map.row)
		{
			render_program(program, i, j);
			i++;
		}
		j++;
	}
}
