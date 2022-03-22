
RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = so_long_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

CFILES = main_bonus.c \
		parsing_map_bonus.c \
		error_handler_bonus.c \
		initialize_bonus.c \
		check_component_bonus.c \
		ft_itoa.c \
		get_images_bonus.c \
		render_bonus.c \
		moves_bonus.c \

FTPRINTF_DIR = ../printf
GETNEXTLINE_DIR = ../gnl

FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GETNEXTLINE_LIB = $(GETNEXTLINE_DIR)/nextline.a

OBJ = $(CFILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(FLAGS) $(MLX_FLAG) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB) -o $@ $(CFILES)

%.o : %.c so_long_bonus.h
	@$(CC) $(FLAGS) -c $^ 
	@echo "$(GREEN)" "compiling $<"

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_DIR)

$(GETNEXTLINE_LIB):
	$(MAKE) -C $(GETNEXTLINE_DIR)

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@rm	$(FTPRINTF_LIB) $()
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 