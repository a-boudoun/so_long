/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:48:34 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/14 20:08:26 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;
	int			fd;

	if (argc < 2)
		exit_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_strcmp (".ber", &argv[1][ft_strlen(argv[1]) - 4]))
		exit_error (1);
	ft_initialize (&program);
	// program.mlx = mlx_init();
	// program.mlx_win = mlx_new_window(program.mlx, 1920, 1080, "so_long");
	parsing_map (argv[1], &program, fd);
	check_component (&program);
	//get_images(&program);
	generate_window(&program);
	//render_game(&program);
 	mlx_loop(program.mlx);
 }
