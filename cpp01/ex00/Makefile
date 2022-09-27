CC			= c++ -Wall -Wextra -Werror -std=c++98 
RM			= rm -rf
NAME		= ./zombie
NAME_SHORT	= zombie

INCS_DIR	= ./include/
MAIN_INC	= -I$(INCS_DIR)

INC			= Zombie.hpp

INCS		= $(addprefix ${INCS_DIR}, ${INC})

SRCS_DIR 	= ./src/

SRC			= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

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
