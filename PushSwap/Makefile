NAME = push_swap

BNAME = checker

SOURCES = ./ft_atoi.c\
./calculate_target.c\
./check_parameters.c\
./execute_actions.c\
./push.c\
./rotate.c\
./sort_3_less.c\
./sort.c\
./split_numbers.c\
./start.c\
./swap.c\
./utils.c\
./push_swap.c\

BSOURCES = ./gnl.c\
./ft_atoi.c\
./calculate_target.c\
./check_parameters.c\
./execute_actions.c\
./push.c\
./rotate.c\
./sort_3_less.c\
./sort.c\
./split_numbers.c\
./start.c\
./swap.c\
./utils.c\
./checker.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(BNAME): $(BOBJECTS)
			$(CC) $(CFLAGS) -o $(BNAME) $(BOBJECTS)
clean:
		$(RM) $(OBJECTS) $(BOBJECTS)
fclean:	clean
		$(RM) $(NAME) $(BNAME)
re:		fclean all

.PHONY: all, clean, fclean, re
