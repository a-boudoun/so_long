#include"so_long.h"

void exit_error(int error)
{
	if (error == 0)
		ft_printf("error \nusage: <./so_long> <map.ber>");
	else if (error == 1)
		ft_printf("error \ninvalid map");
	else if (error == 2)
		ft_printf("error \nmalloc error");
	exit(1);
}