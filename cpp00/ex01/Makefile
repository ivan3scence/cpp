CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g -fsanitize=address

NAME = phone_book

SRC = Contact.cpp PhoneBook.cpp main.cpp

SRC_DIR = ./src/

INC_DIR = ./include/

INC = Contract.hpp PhoneBook.hpp

SOURCES = $(addprefix ${SRC_DIR}, ${SRC})

INCLUDES = $(addprefix ${INC_DIR}, ${INC})

BUILDIR = ./obj/

OBJS = ${SRC:.cpp=.o}

REMOVE = rm -rf

all:	${BUILDIR} ${NAME}

${NAME}:	${SOURCES}
	${CC} ${FLAGS} -I ${INC_DIR} $? -o $@

${BUILDIR}:
	mkdir $@

%.o:	%.cpp ${INCLUDES} Makefile
	${CC} ${FLAGS} -I ${INC_DIR} -c $< -o $@

clean:
	${REMOVE} ${OBJS}
	
fclean:	clean
	${REMOVE} ${NAME}

re: fclean all
