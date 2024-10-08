/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  cub3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:50:16 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/21 15:50:17 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/****************************************************************************/
/*                              Includes                                    */
/****************************************************************************/

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>

/****************************************************************************/
/*                              Defines                                     */
/****************************************************************************/

# define PI 3.14
# define BLOC_SIZE 64
# define MOVE_SPEED 0.02
# define ANGLE_SPEED 0.004
# define WEIGHT 640
# define HEIGHT 640
# define GREEN 0x0000FF00
# define WHITE 0xFFFFFFFF
# define GREY 0x00696969

/****************************************************************************/
/*                              Structures                                  */
/****************************************************************************/

typedef struct s_data
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_minimap
{
	int				scale;
	int				minimap_x;
	int				minimap_y;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
}					t_minimap;

typedef struct s_point
{
	float			x;
	float			y;
}					t_point;

typedef struct s_player
{
	double			plane_x;
	float			fov;
	float			angle;
	float			speed_move;
	bool			up;
	bool			strafe_left;
	bool			down;
	bool			strafe_right;
	bool			a;
	bool			d;
	int				dir_x;
	int				dir_y;
	t_point			position;
}					t_player;

typedef struct s_ray
{
	t_point			vec_ray;
	t_point			unit_step;
	t_point			dir;
	double			perp_wall_dist;
	double			wall_x;
	float			inter_x;
	float			inter_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				start;
	int				end;
	int				floor_begin;
	int				celling_begin;
	int				tex_x;
	int				tex_y;
	int				wall_y;
	int				i;
	int				res;
}					t_ray;

typedef struct s_game
{
	int				old_x;
	int				x;
	int				y;
	int				c_color;
	int				f_color;
	void			*mlx;
	void			*win;
	char			**map;
	int				bonus;
	t_player		player;
	t_data			img;
	t_data			e;
	t_data			w;
	t_data			s;
	t_data			n;
	t_data			minimap;
	struct timeval	begin;
	struct timeval	end;
}					t_game;

typedef struct s_program
{
	int				err;
	int				bonus;
	int				parameters;
	int				n;
	int				s;
	int				e;
	int				w;
	int				f_colors;
	int				f;
	int				c_colors;
	int				c;
	int				map_file;
	t_vector		*vemap;
	int				nb_line;
	int				nb_column;
	int				start_x;
	int				start_y;
	char			start;
	t_game			game;
	int				game_init;
}					t_program;

/****************************************************************************/
/*                               Init                                       */
/****************************************************************************/

int					ft_init_data(t_program *data);
int					ft_init_game(t_program *data);
void				ft_init_ray(t_ray *ray, double plane_x);
void				ft_init_player(t_program *data);
void				ft_second_init(t_program *data);

/****************************************************************************/
/*                               Parsing                                    */
/****************************************************************************/

int					ft_parsing(int argc, char *argv, t_program *data);
int					ft_check_args(char *args, int argc, t_program *data);
/*Parameters*/
int					ft_read_param(char *line, t_program *data);
int					ft_save_path(char *line, t_data *view, t_program *data,
						int *param);
int					ft_save_colors(char *line, int *colors, t_program *data,
						int *param);
/*Map*/
int					ft_read_map(char *line, t_vector *vector, t_program *data);
int					ft_parse_map(t_vector *vector, t_program *data);
int					ft_map_validity(char **array);
int					ft_fill_map(char **array, t_program *data, int line_len,
						int nb_line);
/*Parsing utils*/
int					ft_max_len(char **array);
int					ft_count_dot(char **array);
int					ft_hlimit(char *str, int line);
int					ft_vlimit(char *str, int line, int *start);

/****************************************************************************/
/*                            Error management                              */
/****************************************************************************/

enum				e_errors
{
	FILE_ERR = 2,
	FEW_ARGS = 3,
	MANY_ARGS = 4,
	OPEN_ERR = 5,
	GNL_ERR = 6,
	W_PARAM = 7,
	SPLIT_MEM = 8,
	MEM_ERR = 9,
	PATH_ERR = 10,
	ATOI_ERR = 11,
	TAB_ERR = 12,
	INV_CHAR = 13,
	NOT_CLOSED = 14,
	MAP_SIZE = 15,
	NO_START = 16,
	LOAD_ASSET = 17,
	ASSET_ADDR = 18,
	SERV_INIT = 19,
	WINDOW_ERR = 20,
	MMAP_IMG = 21,
	MMAP_ADDR = 22,
	GAME_IMG = 23,
	GAME_ADDR = 24,
};

int					ft_parsing_err(int err, char *param, t_program *data);
int					ft_map_err(int err, int start, int line, char c);
int					ft_assets_err(int err, char *path, t_program *data);
int					ft_serv_err(int err, t_program *data);

/****************************************************************************/
/*                                   Free                                   */
/****************************************************************************/

void				ft_free_parsing(t_program *data);
void				end_game(t_program *data);

/******************************MAP******************************/
void				ft_draw_minimap(t_program *data);
void				ft_minimap(t_program *data);

/******************************EVENT******************************/
int					ft_on_key_press(int keycode, t_program *data);
int					ft_on_key_release(int keycode, t_player *player);
void				ft_move_up(char **map, t_player *player, double delta_time);
void				ft_move_down(char **map, t_player *player,
						double delta_time);
void				ft_move_left(char **map, t_player *player,
						double delta_time);
void				ft_move_right(char **map, t_player *player,
						double delta_time);
void				ft_event_handler(t_program *data);

/******************************PLAYER******************************/
int					ft_update_player_position(t_game *game);
void				ft_get_player_dir(t_game *game);

/******************************RAYCASTING******************************/
int					ft_raycasting(t_program *data);
void				ft_set_ray_position(t_point *vec_ray, t_point *dir,
						t_player *player, int i);
int					ft_raycast(t_game *game);
void				ft_first_raycast(t_game *game);

/******************************MATH******************************/
float				ft_cos(float degree);
float				ft_sin(float degree);
float				ft_tan(float degree);
void				ft_normalize_vector(double x, double y, t_point *dir);
t_point				ft_get_distance_for_next_intersection(t_point dir);
void				ft_get_first_intersection_coordinates(t_ray *ray,
						t_game *game);
void				ft_find_nearest_wall(t_ray *ray, t_game *game);
void				ft_get_wall_info(t_ray *ray, t_game game, int i);

/******************************DRAWING******************************/
void				draw(t_data *data, int x, int y, int color);
void				ft_draw_wall(t_ray ray, t_game *game, int x);
void				ft_draw_floor_and_celling(t_ray ray, t_game *game, int x);
void				ft_draw_player_viewpoint(t_ray ray, t_game *game, int x);

/******************************TIME******************************/
struct timeval		ft_get_current_time(void);
double				ft_get_time_in_millisecond(struct timeval *time);

/******************************CLEAR_IMAGE******************************/
void				ft_clear_image(int *addr, int weight, int height);

/******************************MOUVE******************************/
int					ft_mouse_move(t_game *game);
int					ft_manage_mouse(t_game *game);

#endif
