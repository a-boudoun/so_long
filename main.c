#include "so_long.h"

int main(int argc, char **argv){
	t_program program;
	int i;

	i = 0;
	if (argc != 2)
		exit_error(0);
	parsing_map(argv[1], &program);
	//components_check(argv[1], &program);
}