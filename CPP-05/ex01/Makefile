# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 21:19:42 by flima             #+#    #+#              #
#    Updated: 2025/09/03 20:20:10 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureacrat

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BOLD	= \033[1m

CXXFLAGS = -Wall -Wextra -Werror -g
CXXFLAGS += -std=c++11
CXXFLAGS += -fsanitize=address

HEADERS = Bureaucrat.hpp Form.hpp
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS_DIR = objs/
OBJS_O = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_O))

all: $(NAME)

$(NAME): $(OBJS)
	@g++ $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compiling program...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)\n"

$(OBJS_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@g++ $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

clean:
	@rm -fr $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re