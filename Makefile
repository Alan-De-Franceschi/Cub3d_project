# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 15:58:55 by ade-fran          #+#    #+#              #
#    Updated: 2024/08/21 15:58:57 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CFLAGS			=	-g3 -Wall -Wextra -Werror -I ${INCLD_DIR}

CC				=	cc

COLOUR_GREEN	=	\033[0;32m

YELLOW			=	\033[0;33m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  MINILIBX                                    #
#                                                                              #
# **************************************************************************** #

MLX_FLAGS 		=	-L minilibx-linux/ -lmlx -lXext -lX11

MLX 			=	minilibx-linux/libmlx_Linux.a

# **************************************************************************** #
#                                                                              #
#                                   LIBFT                                      #
#                                                                              #
# **************************************************************************** #

LIB				=	libft.a

LIBFT_FOLDER 	=	libft/

LIB_DIR			=	${LIBFT_FOLDER}lib/

LIB_SRC			=	${LIBFT_FOLDER}*/*.c

LIB_INCLD_DIR	=	${LIBFT_FOLDER}inc/

LIB_INCLD		= 	${LIB_INCLD_DIR}libft.h

LIB_PATH		=	$(addprefix ${LIB_DIR}, ${LIB})

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH		=	src/

SOURCES_MAIN		= 	main.c \

SOURCES_INIT		= 	init/init_data.c \
						init/init_game.c \

SOURCES_PARSING		=	parsing/parsing.c \
						parsing/check_args.c \
						parsing/parameters/read_parameters.c \
						parsing/parameters/save_path.c \
						parsing/parameters/save_colors.c \
						parsing/map/read_map.c \
						parsing/map/parse_map.c \
						parsing/map/map_validity.c \
						parsing/map/fill_map.c \
						parsing/map/parse_map_utils.c \

SOURCES_ERRORS		=	errors/parsing_errors.c \

SOURCES_FREE		=	free/free_parsing.c \
						free/end_game.c \

SOURCES_MATH		=	math/dda_algorithm.c \
						math/get_wall_height.c \
						math/intersection.c \
						math/math.c \

SOURCES_MINIMAP		=	minimap/draw_minimap.c \
						minimap/minimap.c \

SOURCES_MOUSE		=	mouse/mouse_move.c \

SOURCES_PLAYER		=	player/get_player_dir.c \
						player/update_player.c \

SOURCES_RAYCASTING	=	raycasting/raycasting.c \
						raycasting/set_ray_position.c \

SOURCES_TIME		=	time/get_current_time.c \

SOURCES_CLEAR_IMAGE	=	clear_image/clear_image.c \

SOURCES_DRAWING		=	drawing/draw_floor_and_celling.c \
						drawing/draw_player_viewpoint.c \
						drawing/draw_wall.c \
						drawing/draw.c \

SOURCES_EVENT		=	event/events_handler.c \
						event/key_press.c \
						event/key_release.c \
						event/player_mvt.c \

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_MAIN:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_INIT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PARSING:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_ERRORS:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_FREE:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_MATH:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_MINIMAP:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_MOUSE:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_RAYCASTING:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_TIME:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PLAYER:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_CLEAR_IMAGE:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_DRAWING:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./inc/

INCLD			=	${INCLD_DIR}cub3d.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  mlx ${NAME}

${LIB_PATH}: ${LIB_SRC} ${LIB_INCLD}
	@make -C ${LIBFT_FOLDER} --no-print-directory
	@echo "${COLOUR_GREEN}\33[2K\nLibft compiled${COLOUR_END}"

${MLX}:
	@echo ""
	@make -C minilibx-linux/ --no-print-directory > /dev/null 2>&1
	@echo "${COLOUR_GREEN}\33[2K\nMinilibx compiled\n${COLOUR_END}"

${NAME}: $(LIB_PATH) $(MLX) ${OBJECTS} ${INCLD}
	@${CC} ${CFLAGS} ${OBJECTS} $(LIB_PATH) $(MLX_FLAGS) -o ${NAME} -lm
	@echo "${COLOUR_GREEN}\33[2K\nCub3d compiled with : \n${COLOUR_END}"
	@echo "	${CC} ${CFLAGS} $(LIB_PATH) $(MLX_FLAGS) -o ${NAME} -lm\n"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling Cub3d :${COLOUR_END} $@"

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git

clean:
	@rm -rf ${OBJECTS_PATH}
	@make fclean -C libft/ --no-print-directory
	@make clean -C minilibx-linux/ --no-print-directory

fclean:
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}
	@rm -rf minilibx-linux
	@echo "${COLOUR_GREEN}\nCub3d cleaned\n${COLOUR_END}"
	@make fclean -C libft/ --no-print-directory
	@echo "${COLOUR_GREEN}Minilibx cleaned\n${COLOUR_END}"
	

re: fclean all

.PHONY: fclean clean all re
