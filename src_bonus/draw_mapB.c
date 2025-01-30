/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mapB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:00:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/30 21:11:50 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int	draw_coin_b(t_data *data)
{
	static int	i = 1;
	static int	j = 0;
	static int  h = 1;
	static int	k = 0;

	if (j == (data->i * 2))
		j = 0;
	if (data->inlophok == 'S')
	{
		if (h == 6)
			h = 0;
		mlx_put_image_to_window(data->mlx, data->win, data->anwp[h], data->x, data->y);
		h++;
	}
	if (data->xyancion[j] != -1 && data->xyancion[j + 1] != -1)
	{
		if (i == 7)
			i = 0;
		if (data->xyancion[j] != -1 && data->xyancion[j + 1] != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[i], data->xyancion[j], data->xyancion[j + 1]);
		i++;
	}
	if (data->inlophok == 'W')
	{
		if (k == 9)
		{
			data->inlophok = 'S';
			k = 0;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->anwlp[k], data->x, data->y);
		k++;
	}
	j += 2;
	usleep(200000 / (data->i));
	return (0);
}

static void	the_rest_b(int fd, t_data *data, int x, int y)
{
	char	buffer[2];
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (buffer[0] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
		else if (buffer[0] == '0')
			mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		animation(data, buffer[0], x, y);
		if (buffer[0] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
		else if (buffer[0] == '\n')
		{
			y += 60;
			x = -60;
		}
		x += 60;
	}
}

void	ft_draw_map_b(t_data *data, char *map)
{
	int	fd;
	int	x;
	int	y;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		prinft_error(2);
	x = 0;
	y = 0;
	the_rest_b(fd, data, x, y);
	close(fd);
}
