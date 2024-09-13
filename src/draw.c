/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:38:03 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/22 18:18:40 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_put_opt(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < (img->l_len / (img->bpp / 8)) && y >= 0 && y < img->l_len)
	{
		offset = (y * img->l_len) + (x * (img->bpp / 8));
		*((unsigned int *)(img->img_pixels_ptr + offset)) = color;
	}
}

double	calculate_progress(t_line *line)
{
	double	dist_x;
	double	dist_y;

	dist_x = line->current_x - line->p1.x;
	dist_y = line->current_y - line->p1.y;
	if (line->length > 0)
		return (sqrt(dist_x * dist_x + dist_y * dist_y) / line->length);
	return (0);
}

void	draw_line(t_data *data, t_line *line)
{
	double	progress;
	int		color;

	while (1)
	{
		progress = calculate_progress(line);
		color = interpolate_color(data, line, progress);
		pixel_put_opt(&(data->img), line->current_x, line->current_y, color);
		if (line->current_x == line->p2.x && line->current_y == line->p2.y)
			break ;
		if (line->current_x > line->p2.x && line->current_y > line->p2.y)
			break ;
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			line->current_x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->current_y += line->sy;
		}
	}
}

void	render_line(t_data *data, t_line *line)
{
	init_line(line);
	draw_line(data, line);
}
