CC			= c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
RM			= rm -rf
NAME		= ./st
NAME_SHORT	= st

INCS_DIR	= ./include/
MAIN_INC	= -I$(INCS_DIR)

INC			= ClapTrap.hpp ScavTrap.hpp

INCS		= $(addprefix ${INCS_DIR}, ${INC})

SRCS_DIR 	= ./src/

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp

SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

OBJS		= $(SRCS:.cpp=.o)

%.o			: %.cpp $(INCS) Makefile
			$(CC) $(MAIN_INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(MAIN_INC) $(OBJS) -o $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
