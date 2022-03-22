
RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

CFILES = main.c \
		parsing_map.c \
		error_handler.c \
		initialize.c \
		check_component.c \
		get_images.c \
		render.c \
		moves.c \

FTPRINTF_DIR = printf
GETNEXTLINE_DIR = gnl
SOLONG_BO_DIR = bonus_

FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GETNEXTLINE_LIB = $(GETNEXTLINE_DIR)/nextline.a
SOLONG_B_EX = $(SOLONG_BO_DIR)/so_long_bonus

OBJ = $(CFILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(CFLAGS) $(MLX_FLAG)  $(FTPRINTF_LIB) $(GETNEXTLINE_LIB) -o $@ $(CFILES)

bonus : 
	@$(MAKE) -C $(SOLONG_BO_DIR)

%.o : %.c so_long.h
	@$(CC) $(CFLAGS) -c $^ 
	@echo "$(GREEN)" "compiling $<"

$(GETNEXTLINE_LIB):
	@$(MAKE) -C $(GETNEXTLINE_DIR)

$(FTPRINTF_LIB):
	@$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(FTPRINTF_DIR)
	@$(MAKE) clean -C $(GETNEXTLINE_DIR)
	@$(MAKE) clean -C $(SOLONG_BO_DIR)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@$(MAKE) fclean -C $(SOLONG_BO_DIR)
	@$(MAKE) fclean -C $(FTPRINTF_DIR)
	@$(MAKE) fclean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 