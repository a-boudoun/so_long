/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:50:21 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/05 19:01:29 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*player_right;
	void	*player_left;
	void	*collect;
	void	*exit_yes;
	void	*exit_no;
	void	*die;
	void	*wall;
	void	*floor;
}		t_img;

typedef struct s_player{
	int	x;
	int	y;
	int position;
} t_player;

typedef struct s_map{
	char	**map;
	int		column;
	int		row;
	int		collectible;
	int		exit;
} t_map;

typedef struct s_program{
	t_map		map;
	t_img		img;
	t_player	player;

}		t_program;

void	exit_error(int error);
int		ft_strcmp(char *s1, char *s2);
void	ft_initialize(t_program *program);
void	parsing_map(char *filename, t_program *program, int fd);
void	build_map(t_program *program, char *line);
void	check_component(t_program *program);

#endif