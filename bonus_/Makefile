
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
		../gnl/get_next_line.c \
		../gnl/get_next_line_utils.c\
		initialize_bonus.c \
		check_component_bonus.c \
		ft_itoa.c \
		get_images_bonus.c \
		render_bonus.c \
		moves_bonus.c \

FTPRINTF_DIR = ../printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GET_NEXT_LINE_OBJ = get_next_line.o get_next_line_utils.o

OBJ = $(CFILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(FTPRINTF_LIB)
	@$(CC) $(FLAGS) $(MLX_FLAG) $(FTPRINTF_LIB) -o $@ $(CFILES)

%.o : %.c 
	@$(CC) $(FLAGS) $^ -c 
	@echo "$(GREEN)" "compiling $<"

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME) $(GET_NEXT_LINE_OBJ)
	rm	$(FTPRINTF_LIB) 
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 