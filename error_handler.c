#include"so_long.h"

void exit_error(int error){
	if(error == 0){
		ft_printf("argument Error");
		ft_printf("usage: <./so_long> <map.ber>");
	}
	
	exit(1);
}