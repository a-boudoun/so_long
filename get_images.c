/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:11:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/15 15:21:43 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	player_images(t_program *program)
{
	int	img_height;
	int	img_width;

// 	program->img.player_down = mlx_png_file_to_image(program->mlx, "images/player_down.png", &img_width, &img_height);
// 	program->img.player_up = mlx_png_file_to_image(program->mlx, "images/player_up.png", &img_width, &img_height);
	program->img.player_right = mlx_xpm_file_to_image(program->mlx, "images/player_right.xpm", &img_width, &img_height);
	program->img.player_left = mlx_xpm_file_to_image(program->mlx, "images/player_left.xpm", &img_width, &img_height);
}

void	exit_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.exit_no = mlx_xpm_file_to_image(program->mlx, "images/exit_no.xpm", &img_width, &img_height);
	program->img.exit_yes = mlx_xpm_file_to_image(program->mlx, "images/exit_yes.xpm", &img_width, &img_height);
}

void	map_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.collect = mlx_xpm_file_to_image(program->mlx, "images/collect.xpm", &img_width, &img_height);
	program->img.wall = mlx_xpm_file_to_image(program->mlx, "images/wall.xpm", &img_width, &img_height);
	program->img.floor = mlx_xpm_file_to_image(program->mlx, "images/floor.xpm", &img_width, &img_height);	
}

void	get_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.collect = mlx_xpm_file_to_image(program->mlx, "images/collect.xpm", &img_width, &img_height);
	program->img.wall = mlx_xpm_file_to_image(program->mlx, "images/wall.xpm", &img_width, &img_height);
	program->img.floor = mlx_xpm_file_to_image(program->mlx, "images/floor.xpm", &img_width, &img_height);
	// map_images(program);
	// player_images(program);
	// exit_images(program);
}
