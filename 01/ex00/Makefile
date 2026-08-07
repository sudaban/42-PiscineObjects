NAME		=	relationship
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I.

SRCS		=	Position.cpp \
				Statistic.cpp \
				Tool.cpp \
				Shovel.cpp \
				Hammer.cpp \
				Worker.cpp \
				Workshop.cpp \
				main.cpp

OBJS		=	$(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
