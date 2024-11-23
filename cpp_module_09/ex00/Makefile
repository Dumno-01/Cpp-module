SRCS			:=	main.cpp \
					BitcoinExchange.cpp \

OBJS_D			:=	objs/

OBJS			:=	$(SRCS:%.cpp=$(OBJS_D)%.o)

HEAD_D			:=	includes/

HEAD			:=	BitcoinExchange.hpp\

HEAD_A			:=	$(addprefix $(HEAD_D), $(HEAD))

NAME			:=	btc

CC				:=	c++ -std=c++98

RM				:=	rm -rf

CFLAGS			:=	-Wall -Wextra -Werror

ASAN_F			:=	-g3 -fsanitize=address

all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS)
				$(CC) $(CFLAGS) $(ASAN_F) -o $(NAME) $(OBJS)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.cpp $(HEAD_A)
				$(CC) $(CFLAGS) $(ASAN_F) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

clean			:
				$(RM) $(OBJS) $(OBJS_D)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re FORCE