/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:46:49 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/14 18:40:28 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	exit_error(int error)
{
	if (error == 0)
		ft_printf("error \nusage: <./so_long> <map.ber>");
	else if (error == 1)
		ft_printf("error \ninvalid map");
	else if (error == 2)
		ft_printf("error \nmalloc error");
	else if (error == 3)
		ft_printf("error \nmlx_init error");
	exit(1);
}
