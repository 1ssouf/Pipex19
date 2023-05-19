# Variables
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
LDFLAGS =

# Chemins des fichiers sources
SRCDIR = src
UTILSDIR = utils
INCDIR = include

# Noms des fichiers sources
SRCS = $(SRCDIR)/pipex.c $(SRCDIR)/utils.c $(UTILSDIR)/lib_utils.c $(UTILSDIR)/lib_utils1.c $(UTILSDIR)/split.c

# Nom de l'exécutable
NAME = pipex

# Commandes
all: $(NAME)

$(NAME): $(SRCS) $(INCDIR)/pipex.h
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCDIR) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
