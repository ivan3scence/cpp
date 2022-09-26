CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g -fsanitize=address

NAME = phone_book

SRC = Contact.cpp PhoneBook.cpp main.cpp

INCLUDES = Contract.hpp PhoneBook.hpp

all:	${NAME}

${NAME}:	${SRC}
	${CC} ${FLAGS} -I ${INCLUDES} $? -o $@