
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
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c\
		initialize.c \
		check_component.c \
		get_images.c \
		render.c \
		moves.c \

FTPRINTF_DIR = printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GET_NEXT_LINE_OBJ = get_next_line.o get_next_line_utils.o

OBJ = $(CFILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(FTPRINTF_LIB)
	@$(CC) $(CFLAGS) $(MLX_FLAG) $(FTPRINTF_LIB) -o $@ $(CFILES)

%.o : %.c 
	@$(CC) $(CFLAGS) $^ -c 
	@echo "$(GREEN)" "compiling $<"

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(OBJ)
	$(MAKE) clean -C $(FTPRINTF_DIR)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME) $(GET_NEXT_LINE_OBJ)
	$(RM) $(FTPRINTF_LIB) 
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 