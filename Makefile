NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

FRAMEWORKS = -framework OpenGL -framework AppKit -g

FS = -fsanitize=address

SOURCES = src/read_file.c src/utils.c src/utils2.c\
		  src/draw.c src/colors.c src/control.c src/main.c\
		  get_next_line/get_next_line.c\
		  get_next_line/get_next_line_utils.c

INCLUDES = ft_printf/libftprintf.a mlx/libmlx.a

all:
	@make -C ./ft_printf
	@make -C ./mlx
	@$(CC) $(SOURCES) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)
	@echo "\n=========Compiled Successfully!==========\n"

clean:
	@make clean -C ./ft_printf
	@make clean -C ./mlx

fclean: clean
	@make fclean -C ./ft_printf
	@rm -f $(NAME)
	@rm -rf fdf.dSYM
	@echo "\n=========Cleaned Successfully!==========\n"

re: fclean all
