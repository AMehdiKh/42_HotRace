# !NOT DONE

################################################
#                  FILES                       #
################################################

NAME         = hotrace

SRCS         = main.c hashing.c utils.c

OBJS         = $(SRCS:%.c=%.o)

INC	         = hotrace.h


################################################
#             COMPILER SETTINGS                #
################################################

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -O3 # -Ofast -fsanitize=address -Wunreachable-code

################################################
#                   RULES                      #
################################################

all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Built $(NAME)$(RESET)"

# Compiling into object files
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

################################################
#                 CLEANING                     #
################################################

clean:
	rm -rf *.o

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
