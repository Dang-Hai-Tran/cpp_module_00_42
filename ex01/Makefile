NAME = phonebook
C++ = c++
FLAGS = -std=c++11 -Wall -Wextra -Werror -g

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all : $(NAME)

%.o : %.c
	$(C++) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
