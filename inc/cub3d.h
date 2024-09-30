/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:50:16 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/21 15:50:17 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/****************************************************************************/
/*                              Includes                                    */
/****************************************************************************/

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
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
# define RED 0x00FF0000
# define BLUE 0x0053F0FF
# define GREEN 0x0000FF00
# define WHITE 0xFFFFFFFF
# define GREY 0x00C0C0C0

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
	int				minimapX;
	int				minimapY;
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
	double			planeX;
	float			fov;
	float			angle;
	float			speedMove;
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
	t_point			vecRay;
	t_point			UnitStep;
	t_point			direction;
	double			perpWallDist;
	double			wallX;
	float			interX;
	float			interY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				Start;
	int				End;
	int				floorBegin;
	int				cellingBegin;
	int				tex_x;
	int				tex_y;
	int				d;
	int				i;
	int				res;
}					t_ray;

typedef struct s_game
{
	int				oldX;
	int				x;
	int				y;
	void			*mlx;
	void			*win;
	t_player		player;
	t_data			img;
	t_data			E;
	t_data			W;
	t_data			S;
	t_data			N;
	char			**map;
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
void				ft_init_ray(t_ray *ray, double planeX);

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
};

int					ft_parsing_err(int err, char *param, t_program *data);
int					ft_map_err(int err, int start, int line, char c);
int					ft_assets_err(int err, char *path, t_program *data);

/****************************************************************************/
/*                                   Free                                   */
/****************************************************************************/

void				ft_free_parsing(t_program *data);
void				end_game(t_game *game);

/******************************MAP******************************/
void				ft_draw_minimap(t_program *data);
void				ft_minimap(t_program *data);

/******************************EVENT******************************/
int					ft_on_key_press(int keycode, t_game *game);
int					ft_on_key_release(int keycode, t_player *player);
void				ft_move_up(char **map, t_player *player,
						double delta_time);
void				ft_move_down(char **map, t_player *player,
						double delta_time);
void				ft_move_left(char **map, t_player *player,
						double delta_time);
void				ft_move_right(char **map, t_player *player,
						double delta_time);
void				ft_event_handler(t_game *game);

/******************************PLAYER******************************/
int					ft_update_player_position(t_program *data);
void				ft_get_player_dir(t_game *game);

/******************************RAYCASTING******************************/
int					ft_raycasting(t_program *data);
void				ft_set_ray_position(t_point *vecRay, t_point *direction,
						t_player *player, int i);
int					ft_raycast(t_program *data);
void				ft_first_raycast(t_game *game);

/******************************MATH******************************/
float				ft_cos(float degree);
float				ft_sin(float degree);
float				ft_tan(float degree);
void				ft_normalize_vector(double x, double y, t_point *direction);
t_point				ft_get_distance_for_next_intersection(t_point direction);
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
