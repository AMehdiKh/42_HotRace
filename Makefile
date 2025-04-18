# !NOT DONE
# todo test for relinking add the gnl file the util file and the header file

################################################
#                  FILES                       #
################################################

NAME         = hotrace

SRCS         = main.c

OBJS         = $(SRCS:%.c=%.o)


################################################
#             COMPILER SETTINGS                #
################################################

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -03 # -Ofast -fsanitize=address -Wunreachable-code

################################################
#                   RULES                      #
################################################

all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	echo "$(GREEN)Built $(NAME)$(RESET)"

# Compiling into object files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

################################################
#                 CLEANING                     #
################################################

clean:
	rm -rf %.o

fclean: clean
	rm -f $(NAME)

re: fclean all

################################################
#                 .PHONY                       #
################################################

.PHONY: clean

################################################
#                 COLORS                       #
################################################

GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m
