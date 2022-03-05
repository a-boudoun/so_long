/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:46:49 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/05 17:47:32 by aboudoun         ###   ########.fr       */
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
	exit(1);
}
