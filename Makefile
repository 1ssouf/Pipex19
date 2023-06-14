NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		utils/utils.a\

SRCS_BONUS = 	src_bonus/pipex_bonus.c\
				src_bonus/utils_bonus.c\
				utils/utils.a\

$(NAME) :
	make all -C utils
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C utils

clean :
	$(RM) $(NAME)
	make clean -C utils

re : fclean all

bonus : clean
	make all -C utils
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)