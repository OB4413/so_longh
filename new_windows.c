/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/19 10:39:35 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *opne_windows(t_data *data)
{
    void *mlx;

    mlx = mlx_new_window(data->mlx, data->win_width * 60, data->win_height * 60, "so_long");
    return (mlx);
}
