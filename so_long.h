# ifndef SO_LONG_H 
# define SO_LONG_H

# include<mlx.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"



typedef struct s_img
{
	void		*player_right;
	void		*player_left;
	void		*collect;
	void		*exit_yes;
	void 		*exit_no;
	void 		*die;
	void		*wall;
	void 		*floor;
} t_img;

typedef struct s_player{
	int x;
	int y;
	int count;
}	t_player;

typedef struct s_map{
	char **map;
	int column;
	int row;
	int clollectibles;

} t_map;

typedef struct s_program{
	t_map map;
	t_img img;
	t_player player;

} 				t_program;

void exit_error(int error);
void parsing_map(char *filename, t_program *program);

#endif