NAME		:= head.a 
OBJDIR		:= objects
SRC		:= $(OBJDIR)/src.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I ./includes 

$(NAME): $(OBJDIR) $(SRC)
	@ar -rcs $(NAME) $(OBJDIR)/*.o 
	@gcc -Wall -Wextra -Werror -o head head.c head.a -I ./includes

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SRC):
	@make -C src

all: $(NAME)

clean:
	@rm -f $(OBJDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@rm -rf head

re: fclean all

.PHONY: all re clean fclean
