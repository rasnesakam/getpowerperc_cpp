NAME	= getpowerperc
SRCS	= main.cpp
CXXARGS = -Wall -Wextra -Werror -std=c++98
CXX	= g++

$(NAME): $(SRCS)
	$(CXX) $(CXXARGS) -o $(NAME) $(SRCS)

all: $(NAME)

clean: $(NAME)
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re
