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

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR}

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

SOURCES_PATH	=	src/

SOURCES_MAIN	= 	main.c \

SOURCES_INIT	= 	init/init_data.c \

SOURCES_PARSING	=	parsing/parsing.c \
					parsing/check_args.c \
					parsing/parameters/read_parameters.c \
					parsing/parameters/save_path.c \
					parsing/parameters/save_colors.c \
					parsing/map/read_map.c \
					parsing/map/parse_map.c \
					parsing/map/parse_map_utils.c \

SOURCES_ERRORS	=	errors/parsing_errors.c \

SOURCES_FREE	=	free/free_parsing.c \

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

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./inc/

INCLD			=	${INCLD_DIR}cube.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

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

clean:
	@rm -rf ${OBJECTS_PATH}
	@make fclean -C libft/ --no-print-directory
	@make clean -C minilibx-linux/ --no-print-directory

fclean:
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}
	@echo "${COLOUR_GREEN}\nCub3d cleaned\n${COLOUR_END}"
	@make fclean -C libft/ --no-print-directory
	@make clean -C minilibx-linux/ --no-print-directory > /dev/null 2>&1
	@echo "${COLOUR_GREEN}Minilibx cleaned\n${COLOUR_END}"
	

re: fclean all

.PHONY: fclean clean all re
