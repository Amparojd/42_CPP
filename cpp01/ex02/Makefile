# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 20:57:06 by ampjimen          #+#    #+#              #
#    Updated: 2024/08/31 21:08:54 by ampjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = brain

# Files
SRCS = main.cpp
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# Compilation Settings
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

# Utils
RM = rm -rf

# Colors
GREEN = \033[92m
YELLOW = \033[93m
CYAN = \033[96m
WHITE = \033[97m
RED = \033[91m
PURPLE = \033[95m
RESET = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@$(title)
	@echo "$(WHITE)Try: ./$(NAME)$(RESET)"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@printf "$(CYAN)Compiling... \n"
	@sleep 0.1
	@$(CC) $(FLAGS) -c $< -o $@

define title
	@echo 
	@echo "$(GREEN)****************************$(RESET)"
	@echo "$(GREEN)* $(BOLD)🧠 HI THIS IS BRAIN 🧠   *$(RESET)"
	@echo "$(GREEN)****************************$(RESET)"
endef

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Deleted object files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable '$(NAME)' has been deleted $(RESET)"

re: fclean all

.PHONY: all clean fclean re
