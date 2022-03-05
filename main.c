/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:48:34 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/05 17:54:53 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;
	int			fd;
	int			i;

	i = 0;
	if (argc < 2)
		exit_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_strcmp (".ber", &argv[1][ft_strlen(argv[1]) - 4]))
		exit_error (1);
	ft_initialize (&program);
	parsing_map (argv[1], &program, fd);
	while (program.map.map[i])
	{
		printf("%s", program.map.map[i]);
		i++;
	}
// components_check(argv[1], &program);
}
