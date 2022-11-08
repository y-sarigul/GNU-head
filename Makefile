NAME		:= head.a 
OBJDIR		:= objects
SRC		:= $(OBJDIR)/src.a
GET_NEXT_LINE := $(OBJEDIR)/get_next_line.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I ./includes 

$(NAME): $(OBJDIR) $(SRC) $(GET_NEXT_LINE)
	@ar -rcs $(NAME) $(OBJDIR)/*.o 
	@gcc -Wall -Wextra -Werror -o head head.c head.a -I ./includes

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SRC):
	@make -C src

$(GET_NEXT_LINE):
	@make -C get_next_line

all: $(NAME)

clean:
	@rm -f $(OBJDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@rm -rf head

re: fclean all

git: fclean
	@rm -f *.txt

.PHONY: all re clean fclean
