NAME = globalbank
C++ = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = $(shell find ./ -type f -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all : $(NAME)
test : all
	@printf "Run test...\n"
	@./cp.sh

%.o : %.c
	$(C++) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) user.log test.log cp.log

re : fclean all

.PHONY : all clean fclean re
