# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 11:37:08 by flima             #+#    #+#              #
#    Updated: 2025/07/17 11:38:26 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BOLD	= \033[1m

CPPFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS += -std=c++11
CPPFLAGS += -fsanitize=address

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS_DIR = objs/
OBJS_O = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_O))

all: $(NAME)

$(NAME): $(OBJS)
	@g++ $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Creating virus...$(RESET)"
	@echo "$(GREEN)Done! You can use it!$(RESET)\n"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

clean:
	@rm -fr $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re