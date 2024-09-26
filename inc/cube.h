/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
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
# include <fcntl.h> 
# include <errno.h>

/****************************************************************************/
/*                              Structures                                  */
/****************************************************************************/

typedef struct s_map
{
	int		x;
	int		y;
	char	value;
}	t_map;

typedef struct s_program
{
	int			err;
	int			bonus;
	int			parameters;
	char		*n_path;
	int			n;
	char		*s_path;
	int			s;
	char		*e_path;
	int			e;
	char		*w_path;
	int			w;
	int			f_colors;
	int			f;
	int			c_colors;
	int			c;
	int			map_file;
	t_vector	*vemap;
	t_map		*map;
	int			map_size;
	int			start_x;
	int			start_y;
	char		start;
}	t_program;

/****************************************************************************/
/*                               Init                                       */
/****************************************************************************/

int		ft_init_data(t_program *data);

/****************************************************************************/
/*                               Parsing                                    */
/****************************************************************************/

int		ft_parsing(int argc, char *argv, t_program *data);
int		ft_check_args(char *args, int argc, t_program *data);
/*Parameters*/
int		ft_read_param(char *line, t_program *data);
int		ft_save_path(char *line, char **path, t_program *data, int *param);
int		ft_save_colors(char *line, int *colors, t_program *data, int *param);
/*Map*/
int		ft_read_map(char *line, t_vector *vector, t_program *data);
int		ft_parse_map(t_vector *vector, t_program *data);
int		ft_map_validity(char **array);
void	ft_fill_map(char **array, t_program *data, int line_len);
/*Parsing utils*/
int		ft_max_len(char **array);
int		ft_count_dot(char **array);
int		ft_hlimit(char *str, int line);
int		ft_vlimit(char *str, int line, int *start);

/****************************************************************************/
/*                            Error management                              */
/****************************************************************************/

enum	e_errors
{
	FILE_ERR	= 2,
	FEW_ARGS	= 3,
	MANY_ARGS	= 4,
	OPEN_ERR	= 5,
	GNL_ERR		= 6,
	W_PARAM		= 7,
	SPLIT_MEM	= 8,
	MEM_ERR		= 9,
	PATH_ERR	= 10,
	ATOI_ERR	= 11,
	TAB_ERR		= 12,
	INV_CHAR	= 13,
	NOT_CLOSED	= 14,
	MAP_SIZE	= 15,
	NO_START	= 16,
};

int		ft_parsing_err(int err, char *param, t_program *data);
int		ft_map_err(int err, int start, int line, char c);

/****************************************************************************/
/*                                   Free                                   */
/****************************************************************************/

void	ft_free_parsing(t_program *data);

#endif
