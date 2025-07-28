NAME		:= Matrix

SRCS		:= srcs/Matrix.cpp

DIR_SRCS	:= srcs
DIR_OBJS	:= .objs

OBJS		:= $(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.cpp=.o)))

CC			:= c++
CFLAGS		:= -Wall -Wextra -std=c++17 -g
IFLAGS		:= -I include/

RM			:= rm -rf

DEBUG		?= 0

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp
	mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -D DEBUG=$(DEBUG) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(DIR_OBJS)
	$(RM) $(NAME)
re: fclean all

.PHONY :all clean fclean re
