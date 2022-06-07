NAME = 
CC = c++ -stdd=c++98
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

DIR_SRCS = ./src/

HEADERS = ./header/container.hpp
SRC = 

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

all : $(NAME)

$(NAME) : $(SRCS)  $(HEADERS)
			@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :

fclean :  clean 
			@$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re