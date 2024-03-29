NAME = container
CC = c++ -std=c++98 #-fsanitize=address -g
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAIN=   tests/stack_main.cpp #tests/vector_main.cpp #tests/map_main.cpp #tests/stack_main.cpp


HEADERS = map/avl.hpp map/bidirectional_iterator.hpp map/make_pair.hpp map/map.hpp map/pair.hpp map/node.hpp \
		  stack/stack.hpp\
		  vector/enable_if.hpp  vector/equal.hpp  vector/is_integral.hpp  vector/iterator_traits.hpp  vector/lexicographical_compare.hpp vector/random_access_iterator.hpp\
		  vector/reverse_iterator.hpp vector/vector.hpp

all : $(NAME)

$(NAME) : $(MAIN) $(HEADERS)
			@$(CC) $(FLAGS) $(MAIN) -o $(NAME)

clean :

fclean :  clean 
			@$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re