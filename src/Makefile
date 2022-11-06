OBJDIR	:= ../objects
NAME	:= $(OBJDIR)/src.a
CFLAGS	:= -Wall -Wextra -Werror -I ../includes -c
FILES	:= ft_checkflag.c\
		   ft_utils.c

OBJ		:= $(FILES:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJDIR)/ft_*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
