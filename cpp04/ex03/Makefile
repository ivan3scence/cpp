CC			= c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
RM			= rm -rf
NAME		= ./mat
NAME_SHORT	= mat

INCS_DIR	= ./include/
MAIN_INC	= -I$(INCS_DIR)

INC			= AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp\
				IMateriaSource.hpp MateriaSource.hpp

INCS		= $(addprefix ${INCS_DIR}, ${INC})

SRCS_DIR 	= ./src/

SRC			= AMateria.cpp Ice.cpp Cure.cpp Character.cpp main.cpp MateriaSource.cpp

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
