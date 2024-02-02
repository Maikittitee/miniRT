NAME	:= minirt

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror

LIB_DIR	:= ./lib/

RENDER_DIR = src/render/

RENDER_FILE	:= main.c \
				renderer.c \
				pnt.c \
				math.c \
				img.c

PARSER_DIR = src/parser/

PARSER_FILE	:= checkfile.c \
				ft_addvalue.c \
				ft_cal.c \
				ft_print.c \
				ft_cnt.c \
				ft_obj.c \


SRCS := $(addprefix $(RENDER_DIR), $(RENDER_FILE)) \
		$(addprefix $(PARSER_DIR), $(PARSER_FILE))

OBJS	:= $(SRCS:.c=.o)

LIBFT_DIR	:= $(LIB_DIR)libft_gnl
LIBFT	:= $(LIBFT_DIR)/libft.a

MLX_DIR	:= $(addprefix $(LIB_DIR), mlx/)
MINILIBX	:= $(MLX_DIR)libmlx.a

FRAME_W	:= -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

# $(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -I$(LIBFT_DIR)\
# 		-L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx $(FRAME_W) -o $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -I$(LIBFT_DIR)\
		-L$(LIBFT_DIR) -lft -o $(NAME)

# $(MINILIBX):
# 	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(PARSER_DIR)/*.o
	rm -f $(RENDER_DIR)/*.o
	rm -f *.o

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re