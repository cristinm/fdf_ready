/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:06:55 by cristinm          #+#    #+#             */
/*   Updated: 2024/09/13 13:05:07 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Correct usage: %s <input_file>\n", argv[0]), 1);
	initialize_data(&data);
	if (check_map(argv[1]) == -1)
	{
		ft_printf("Error validating the input file.\n");
		return (cleanup(&data), 1);
	}
	if (init_mlx_resources(&data) == -1)
		return (cleanup(&data), 1);
	if (process_map(argv[1], &data) == -1)
	{
		ft_printf("Error processing map.\n");
		return (cleanup(&data), 1);
	}
	adjust_to_window(&data);
	draw_iso_grid(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, &close_x, &data);
	mlx_key_hook(data.win_ptr, &close_esc, &data);
	mlx_loop(data.mlx_ptr);
	cleanup(&data);
	return (0);
}
