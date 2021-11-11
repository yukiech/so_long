/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:33:21 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/11 19:33:55 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_ennemi
{
	int	exist;
	int	x;
	int	y;
	int	x_restart;
	int	y_restart;
	int	move;
} t_ennemi;

typedef struct s_ready
{
	int	player;
	int	coin;
	int	end;
}	t_ready;

typedef struct s_img
{
	void	*tile;
	void	*wall;
	void	*player_w1;
	void	*player_w2;
	void	*player_a1;
	void	*player_a2;
	void	*player_s1;
	void	*player_s2;
	void	*player_d1;
	void	*player_d2;
	void	*coin1;
	void	*end;
	void	*end2;
	void	*scoreboard;
	void	*ennemi_1;
	void	*ennemi_2;
	void	*endscreen;
	void	*winscreen;
}	t_img;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			movement;
	int			start;
	int			coins;
	t_player	player;
	t_ennemi	ennemi;
	char		**map;
	int			map_height;
	int			map_width;
	int			exit_x;
	int			exit_y;
	int			ended;
	int			argc;
	char		**argv;
}	t_info;

# define ROW 11
# define COL 15
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_B 11

void	check_char(t_info *info, int i, int j);
void	init_ready(t_ready *ready);
void	check_equipped(t_info *info, int i, int j, t_ready *ready);
void	check_ready(t_ready ready);
void	check_map(t_info *info);
void	draw_player1(t_info *info, int x, int y, int keycode);
void	draw_player2(t_info *info, int x, int y, int keycode);
void	draw_player(t_info *info, int keycode);
int		ft_strlen(char *str);
char	*ft_first(char c, int i);
int		ft_strcat(char **str, char c);
int		get_next_line(int fd, char **line);
void	draw_map(t_info *info);
void	init(t_info *info, char *file);
void	move_player(t_info *info, int keycode);
int		deal_key(int keycode, t_info *info);
void	draw_tile(t_info *info, int x, int y);
void	draw_wall(t_info *info, int x, int y);
void	draw_coin(t_info *info, int x, int y);
void	draw_end(t_info *info, int x, int y);
void	draw_end2(t_info *info, int x, int y);
void	draw_img(t_info *info, int i, int j);
void	draw_scoreboard(t_info *info, int i, int j);
void	draw_ennemi(t_info *info, int i, int j);
void	draw_ennemi2(t_info *info, int i, int j);
void    endscreen(t_info *info, int x, int y);
char	*ft_itoa(int n);
int		name_check(char *file);
int		linecount(char *file);
char	**malloc_height(t_info *info, char *file);
void	load_map(t_info *info, char *file);
int		check_end(int keycode, t_info *info);
int		check_coin(int keycode, t_info *info);
int		is_wall_or_end(t_info *info, int x, int y);
int		check_wall(int keycode, t_info *info);
void	load_images(t_info *info, int img_width, int img_height);
void	check_images(t_info *info);
int		ft_close(t_info *info);
int		is_valid_char(char c);
void	print_end(char *str, int len);
void	game(int argc, char **argv);
void	startscreen(t_info *info, int x, int y);
void    sound_music(void);
void    sound_coin(void);
void    sound_door(void);
void    sound_death(void);
void    sound_kill(void);

#endif
