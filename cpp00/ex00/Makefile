# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 16:57:47 by ampjimen          #+#    #+#              #
#    Updated: 2024/08/20 18:35:41 by ampjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = megaphone

# Source Files
SRCS = megaphone.cpp

# Compilation Settings
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

# Utilities
RM = rm -rf

# Object Files
OBJS_DIR = obj/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

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

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@printf "$(CYAN)Compiling... \n"
	@sleep 0.1
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@$(title)
	@echo "$(WHITE)Try: ./$(NAME) "'"this is a test"'" $(RESET)"

define title
	@echo 
	@echo "$(GREEN)****************************$(RESET)"
	@echo "$(GREEN)*    📢 $(BOLD)MEGAPHONE 📢      *$(RESET)"
	@echo "$(GREEN)****************************$(RESET)"
endef

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Deleted files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable '$(NAME)' has been deleted $(RESET)"

re: fclean all

# Test Suite
check: $(NAME)
	@echo -e "$(BOLD)$(UNDERLINE)Running Tests$(RESET)\n"
	@echo "Expected  : SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	@echo -n "Megaphone : " && ./$(NAME) "shhhhh... I think the students are asleep..."
	@echo
	@echo "Expected  : DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	@echo -n "Megaphone : " && ./$(NAME) "Damnit ! Sorry students, I thought this thing was off."
	@echo
	@echo "Expected  : * LOUD AND UNBEARABLE FEEDBACK NOISE *"
	@echo -n "Megaphone : " && ./$(NAME)
	@echo "$(GREEN)Tests finished! Time to party! 🎉$(RESET)"

.PHONY: all clean fclean re check title
