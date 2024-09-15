# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 18:43:17 by ampjimen          #+#    #+#              #
#    Updated: 2024/08/30 17:52:43 by ampjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Program Name
NAME = balance


# Files
SRCS_DIR = src/
SRCS =	Account.cpp \
		tests.cpp
		
INCS_DIR = inc/
INCLUDE = -I$(INCS_DIR)

DEPS = $(INCS_DIR)/

# Compilation Settings
CC		= c++
FLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror $(INCLUDE) -g -fsanitize=address

# Utils
RM		= rm -rf

# Object Files
OBJS_DIR 	= 	obj/
OBJ 		= 	$(SRCS:.cpp=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))

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

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.cpp $(INCS_DIR)
	@mkdir -p $(OBJS_DIR)
	@printf "$(CYAN)Compiling... \n"
	@sleep 0.1
	@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	@$(CC)  $(FLAGS) -o $(NAME) $(OBJS)
	@$(title)
	@echo "$(WHITE)Try: ./$(NAME)$(RESET)"

define title
	@echo 
	@echo "$(GREEN)****************************$(RESET)"
	@echo "$(GREEN)*   $(BOLD) 💲   ACCOUNT   💲     *$(RESET)"
	@echo "$(GREEN)****************************$(RESET)"
endef

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Deleted files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable '$(NAME)' has been deleted $(RESET)"

re: fclean all

test: $(NAME)
	@./$(TEST_SCRIPT)

.PHONY: all clean fclean re test