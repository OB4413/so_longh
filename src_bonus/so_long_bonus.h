/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:17 by obarais           #+#    #+#             */
/*   Updated: 2025/01/30 18:36:05 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../src/so_long.h"

void	load_images_b(t_data *data);
void	free_resources(t_data *data);
void	put_trmnation(char *str);
void	prinft_error(int i);
char	**ft_char_map(char *av, t_data *data);
void	free_map(char **map);
void	ft_draw_map_b(t_data *data, char *map);
int		close_window_b(t_data *data);
void	check_coin_exit_b(t_data *data, int keycode);
int		handle_keypress_b(int keycode, t_data *data);
void	help_check_coin_exit_b(t_data *data, int keycode);
int		draw_coin_b(t_data *data);
void	animation(t_data *data, char buffer, int x, int y);

#endif