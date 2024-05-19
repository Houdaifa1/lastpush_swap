NAME = push_swap

CFILES = ft_atoi.c ft_split.c ft_strjoin.c push_swap.c small_sort.c sorting_utils.c sorting.c swap_funs.c parsing_utils.c parsing_utils_2.c rotate_funs.c

all : $(NAME)

$(NAME) : $(CFILES)
	cc  -Wall -Wextra -Werror $(CFILES) -o $(NAME)

fclean :
	rm -rf $(NAME)

clean :

re : fclean all