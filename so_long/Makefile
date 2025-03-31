NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = srcs/
SRCS = main.c map_reader.c map_validator.c

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libft.a

FT_PRINTF_DIR = ../ft_printf/
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

INCLUDES = -I./includes -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

MLX_FLAGS = -lmlx -lXext -lX11

all: $(NAME)

$(LIBFT):
    make -C $(LIBFT_DIR)

$(FT_PRINTF):
    make -C $(FT_PRINTF_DIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
    make -C $(LIBFT_DIR) clean
    make -C $(FT_PRINTF_DIR) clean
    $(RM) $(OBJS)

fclean: clean
    make -C $(LIBFT_DIR) fclean
    make -C $(FT_PRINTF_DIR) fclean
    $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
