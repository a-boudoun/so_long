/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:03 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/15 16:00:34 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	render_player(t_program *program, int i, int j)
// {
// 	program->player.x = i;
// 	program->player.y = j;
// 	if (!program->player.pos)
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->player.img_left,
// 			j * HEIGHT, i * WIDTH);
// 	else
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->player.img_right,
// 			j * HEIGHT, i * WIDTH);
// }

void	render_exit(t_program *program, int i, int j)
{
	if (program->map.collectible)
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.exit_no,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.exit_no,
			j * HEIGHT, i * WIDTH);
}

void	render_map(t_program *program, int i, int j)
{
	if (program->map.map[i][j] == '1')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.wall,
			j * HEIGHT, i * WIDTH);
	if (program->map.map[i][j] == '0')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.floor,
			j * HEIGHT, i * WIDTH);
	// if (program->map.map[i][j] == 'P')
	// 	put_player(program, i, j);
	if (program->map.map[i][j] == 'C')
		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.collect,
			j * HEIGHT, i * WIDTH);
	if (program->map.map[i][j] == 'E')
		render_exit(program, i, j);
}

void	render_game(t_program *program)
{
	int	i;
	int	j;

	mlx_clear_window(program->mlx, program->mlx_win);
	j = 0;
	while (j < program->map.column)
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
// static void	render_exit(t_program *program, int i, int j)
// {
// 	if (program->map.count)
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->i * HEIGHT, j * WIDTH);mg.exit_no, i
// 	else
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.exit_yes, i * HEIGHT, j * WIDTH);
// }

// static void	render_program(t_program *program, int i, int j)
// {
// 	if (program->map.map[i][j] == '1')
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.wall, i * HEIGHT, j * WIDTH);
// 	if (program->map.map[i][j] == '0')
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.floor, i * HEIGHT, j * WIDTH);
// 	// if (program->map.map[i][j] == 'P')
// 	// 	render_player(program, i, j);
// 	if (program->map.map[i][j] == 'C')
// 		mlx_put_image_to_window(program->mlx, program->mlx_win, program->img.collect, i * HEIGHT, j * WIDTH);
// 	//if (program->map.map[i][j] == 'E')
// 		//render_exit(program, i, j);
// }

// void	render_game(t_program *program)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < program->map.column)
// 	{
// 		i = 0;
// 		while (i < program->map.row)
// 		{
// 			render_program(program, i, j);
// 			i++;
// 		}
// 		j++;
// 	}
// }
