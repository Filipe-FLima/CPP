# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipe <filipe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 15:54:11 by filipe            #+#    #+#              #
#    Updated: 2025/11/19 13:09:18 by filipe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BOLD    = \033[1m

CXXFLAGS = -Wall -Wextra -Werror -MMD -g
CXXFLAGS += -std=c++17
CXXFLAGS += -fsanitize=address

SRCS = main.cpp RPN.cpp
OBJS_DIR = objs/
OBJS_O = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_O))
DEP = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
		@g++ $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "\n$(GREEN)Compiling program...$(RESET)"
		@echo "$(GREEN)Done!$(RESET)\n"

-include $(DEP)

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
