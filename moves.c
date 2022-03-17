#include"so_long.h"

void move_right(t_program *program, bool *trigger)
{
	int x;
	int y;

	x = program->player.x;
	y = program->player.y;
	if (program->map.map[x + 1][y] == 'C')
	{
		
	}

}

void move_left(t_program *program, bool *trigger)
{
	int x;
	int y;

	x = program->player.x;
	y = program->player.y;

}

void move_down(t_program *program, bool *trigger)
{
	int x;
	int y;

	x = program->player.x;
	y = program->player.y;

}

void move_up(t_program *program, bool *trigger)
{
	int x;
	int y;

	x = program->player.x;
	y = program->player.y;

}

int moves(int key, t_program *program)
{
	static int moves = 1;
	bool trigger;
	int x;
	int y;

	x = program->player.x;
	y = program->player.y;
	trigger = false;

	if ((key == W || key == UP) && program->map.map[x][y - 1] != 1)
		move_up(program, &trigger);
	if ((key == A || key == RIGHT) && program->map.map[x + 1][y] != 1)
		move_right(program, &trigger);
	if ((key == S || key == DOWN) && program->map.map[x][y + 1] != 1)
		move_down(program, &trigger);
	if ((key == D || key == LEFT) && program->map.map[x - 1][y] != 1)
		move_left(program, &trigger);
	if (trigger)
		ft_printf("moves : %d\n", moves++);
	render_game(program);
	return (1);
}
