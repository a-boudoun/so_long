
RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = solong_test

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

CFILES = solong_test.c

OBJ = $(CFILES:%.c=%.o)


all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAG) -o $@ $(CFILES)

%.o : %.c 
	@$(CC) $(CFLAGS) $^ -c 
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 