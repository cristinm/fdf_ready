/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:58:09 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/24 17:21:02 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	init_mlx_resources(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("Error initializing MiniLibX\n");
		return (-1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, LENGTH, "Fdf");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error creating the window\n");
		return (-1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, LENGTH);
	if (data->img.img_ptr == NULL)
	{
		ft_printf("Error creating the image\n");
		return (-1);
	}
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&(data->img.bpp), &(data->img.l_len), &(data->img.endian));
	if (data->img.img_pixels_ptr == NULL)
		return (ft_printf("Error retrieving the address\n"), -1);
	return (0);
}

void	initialize_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img_ptr = NULL;
	data->grid = NULL;
	data->iso_grid = NULL;
	data->colors = NULL;
	data->rows = 0;
	data->cols = 0;
	data->sc = 1.0;
	data->off_x = 0;
	data->off_y = 0;
	data->min_x = 3.40282347e+38F;
	data->max_x = -3.40282347e+38F;
	data->min_y = 3.40282347e+38F;
	data->max_y = -3.40282347e+38F;
	data->start_color = 0xFFFFFF;
	data->end_color = 0xFFFFFF;
	data->adjusted_width = 0;
	data->adjusted_height = 0;
	data->margin_x = 0;
	data->margin_y = 0;
}

void	init_line_points(t_line *line)
{
	line->p1.x = line->t_x1;
	line->p1.y = line->t_y1;
	line->p2.x = line->t_x2;
	line->p2.y = line->t_y2;
}

void	init_line(t_line *line)
{
	init_line_points(line);
	if (line->p1.x < line->p2.x)
	{
		line->dx = line->p2.x - line->p1.x;
		line->sx = 1;
	}
	else
	{
		line->dx = line->p1.x - line->p2.x;
		line->sx = -1;
	}
	if (line->p1.y < line->p2.y)
	{
		line->dy = line->p2.y - line->p1.y;
		line->sy = 1;
	}
	else
	{
		line->dy = line->p1.y - line->p2.y;
		line->sy = -1;
	}
	line->err = line->dx - line->dy;
	line->length = sqrt(line->dx * line->dx + line->dy * line->dy);
	line->current_x = line->p1.x;
	line->current_y = line->p1.y;
}
