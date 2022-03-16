#include"so_long.h"

void	move_right(t_program *program, int *count)
{
	int	prow;
	int	pcol;

	prow = program->player.x;
	pcol = program->player.y;
	if (program->map.map[prow][pcol + 1] == 'E')
	{
		if (program->map.collectible == 0)
			exit_error(2);
		return ;
	}
	program->player.position = 1;
	*count = 1;
	program->map.map[prow][pcol] = '0';
	pcol += 1;
	if (program->map.map[prow][pcol] == 'C')
	{
		program->map.map[prow][pcol] = '0';
		program->map.collectible -= 1;
	}
	program->map.map[prow][pcol] = 'P';
}

void	move_left(t_program *program, int *count)
{
	int	prow;
	int	pcol;

	prow = program->player.x;
	pcol = program->player.y;
	if (program->map.map[prow][pcol - 1] == 'E')
	{
		if (program->map.collectible == 0)
			exit_error(2);
		return ;
	}
	program->player.position = 0;
	*count = 1;
	program->map.map[prow][pcol] = '0';
	pcol -= 1;
	if (program->map.map[prow][pcol] == 'C')
	{
		program->map.map[prow][pcol] = '0';
		program->map.collectible -= 1;
	}
	program->map.map [prow][pcol] = 'P';
}

void	move_down(t_program *program, int *count)
{
	int	prow;
	int	pcol;

	prow = program->player.x;
	pcol = program->player.y;
	if (program->map.map[prow + 1][pcol] == 'E')
	{
		if (program->map.collectible == 0)
			exit_error(2);
		return ;
	}
	*count = 1;
	program->map.map[prow][pcol] = '0';
	prow += 1;
	if (program->map.map[prow][pcol] == 'C')
	{
		program->map.map[prow][pcol] = '0';
		program->map.collectible -= 1;
	}
	program->map.map [prow][pcol] = 'P';
}

void	move_up(t_program *program, int *count)
{
	int	prow;
	int	pcol;

	prow = program->player.x;
	pcol = program->player.y;
	if (program->map.map[prow - 1][pcol] == 'E')
	{
		if (program->map.collectible == 0)
			exit_error(2);
		return ;
	}
	*count = 1;
	program->map.map[prow][pcol] = '0';
	prow -= 1;
	if (program->map.map[prow][pcol] == 'C')
	{
		program->map.map[prow][pcol] = '0';
		program->map.collectible -= 1;
	}
	program->map.map [prow][pcol] = 'P';
}

int	move(int key, t_program *program)
{
	static int	i = 1;
	int			count;
	int			prow;
	int			pcol;

	count = 0;
	prow = program->player.x;
	pcol = program->player.y;
	if (key == RIGHT || key == D && program->map.map[prow][pcol + 1] != '1')
		move_right(program, &count);
	if (key == LEFT || key == A && program->map.map[prow][pcol - 1] != '1')
		move_left(program, &count);
	if (key == DOWN || key == S && program->map.map[prow + 1][pcol] != '1')
		move_down(program, &count);
	if (key == UP || key == W && program->map.map[prow - 1][pcol] != '1')
		move_up(program, &count);
	if (key == ESC)
		exit_error(6);
	if (count)
		printf("Moves: [%d]\n", i++);
	render_game(program);
	return (1);
}
