# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 11:27:54 by flima             #+#    #+#              #
#    Updated: 2025/08/10 14:09:14 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BOLD	= \033[1m

CXXFLAGS = -Wall -Wextra -Werror -g
CXXFLAGS += -std=c++11
CXXFLAGS += -Wshadow
# CXXFLAGS += -Wno-shadow
CXXFLAGS += -fsanitize=address

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS_DIR = objs/
OBJS_O = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_O))

all: $(NAME)

$(NAME): $(OBJS)
	@g++ $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compiling program...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)\n"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@g++ $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

clean:
	@rm -fr $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re