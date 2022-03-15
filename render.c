/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:03 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/15 18:33:48 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	render_player(t_program *program, int i, int j)
{
	program->player.x = j;
	program->player.y = i;
	if (!program->player.position)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_left, i * HEIGHT, j * WIDTH);
	else
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_right, i * HEIGHT, j * WIDTH);
}

void	render_exit(t_program *program, int i, int j)
{
	if (program->map.collectible)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.exit_no, i * HEIGHT, j * WIDTH);
	else
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.exit_yes, i * HEIGHT, j * WIDTH);
}

void	render_map(t_program *program, int i, int j)
{
	if (program->map.map[j][i] == '1')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.wall, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == '0')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.floor, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == 'P')
		render_player(program, i, j);
	if (program->map.map[j][i] == 'C')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.collect, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == 'E')
		render_exit(program, i, j);
}

void	render_game(t_program *program)
{
	int	i;
	int	j;

	mlx_clear_window(program->mlx, program->mlx_win);
	j = 0;
	while (j < program->map.column - 2)
	{
		i = 0;
		while (i < program->map.row)
		{
			render_map(program, i, j);
			i++;
		}
		j++;
	}
}
