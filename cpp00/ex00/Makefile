CC = c++

RM = rm -rf

FLAGS = -std=c++98 -Wall -Werror -Wextra

INCS_DIR	= ./

MAIN_INC	= -I$(INCS_DIR)

NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${FLAGS} $? -o $@

%.o			: %.cpp
			$(CC) ${FLAGS} $(MAIN_INC) -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all