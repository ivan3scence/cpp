CC			= c++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -fsanitize=address -g
RM			= rm -rf
NAME		= ./dt
NAME_SHORT	= dt

INCS_DIR	= ./include/
MAIN_INC	= -I$(INCS_DIR)

INC			= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

INCS		= $(addprefix ${INCS_DIR}, ${INC})

SRCS_DIR 	= ./src/

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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
