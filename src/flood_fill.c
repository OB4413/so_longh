/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:17:45 by obarais           #+#    #+#             */
/*   Updated: 2025/02/06 21:46:03 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(int x, int y, t_data *data)
{
	static int	i = 0;

	if (x < 0 || y < 0 || x >= data->win_width || y >= data->win_height
		|| data->str[y][x] == '1')
		return ;
	if (data->str[y][x] == 'C')
		i++;
	if (data->str[y][x] == 'E' && data->i != i)
	{
		data->str[y][x] = '1';
		return ;
	}
	data->str[y][x] = '1';
	ft_flood_fill(x + 1, y, data);
	ft_flood_fill(x - 1, y, data);
	ft_flood_fill(x, y + 1, data);
	ft_flood_fill(x, y - 1, data);
}

void	postion_player(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->x = j * 60;
				data->y = i * 60;
				return ;
			}
			j++;
		}
		i++;
	}
	printf("Error: Player not found\n");
	exit(1);
}

void	ft_check_flood(int x, int y, t_data *data)
{
	ft_count_coin_enemy(data->map, data);
	ft_flood_fill(x, y, data);
	ft_count_coin_enemy(data->str, data);
	if (data->i != 0)
	{
		free_map(data->map);
		free_map(data->str);
		printf_error(1);
	}
	if (ft_count_exit(data->str) != 0)
	{
		free_map(data->map);
		free_map(data->str);
		printf_error(1);
	}
}
