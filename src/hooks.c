/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:48:16 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/22 17:44:33 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_x(t_data *data)
{
	ft_printf("X clicked. Closing window\n");
	cleanup(data);
	exit(0);
	return (0);
}

int	close_esc(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Esc pressed. Closing window\n");
		cleanup(data);
		exit(0);
	}
	return (0);
}
