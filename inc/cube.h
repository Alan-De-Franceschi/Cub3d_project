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

typedef struct	s_program
{
	int		map_file;
	char	*n_path;
	char	*s_path;
	char	*e_path;
	char	*w_path;
	int		*f_colors;
	int		*c_colors;
	int		parameters;
	int		err;
	
}	t_program;

/****************************************************************************/
/*                               Init                                       */
/****************************************************************************/

void	ft_init_data(t_program *data);

/****************************************************************************/
/*                               Parsing                                    */
/****************************************************************************/

int		ft_parsing(int argc, char *argv, t_program *data);
int		ft_check_args(char *args, int argc, t_program *data);
int		ft_read_file(char *argv, t_program *data);

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
};

int		ft_parsing_err(int err, t_program *data);

/****************************************************************************/
/*                                   Free                                   */
/****************************************************************************/

void	ft_free_parsing(t_program *data);

#endif
