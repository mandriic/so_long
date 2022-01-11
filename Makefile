LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \
					ft_iferr.c \
					ft_keycodes.c \
					ft_open_images.c \
					ft_open_map.c \
					ft_parsing_XC.c \
					ft_prints.c \
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c

SOURCES_BONUS	=	so_long.c \
					ft_iferr.c \
					ft_keycodes.c \
					ft_open_images.c \
					ft_open_map.c \
					ft_parsing_XC.c \
					ft_prints.c\
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c


SOURCES_DIR		=	src
BONUS_DIR		=	src_bonus

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework OpenGL -framework AppKit

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(LIBFT) $(MLXFLAGS) $(OBJECTS)  $(MINILIBX) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS)  $(MLXFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all