CFILES = get_next_line.c  get_next_line_utils.c 
OFILES = $(CFILES:.c=.o)

CC = gcc
W = -c -Wall -Werror -Wextra
INC = get_next_line.h
NAME = nextline.a

all : $(NAME)

$(NAME) : $(OFILES) $(INC)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)

clean:
	@rm -rf $(OFILES)
fclean : clean
	@rm -rf $(NAME)
re : fclean all