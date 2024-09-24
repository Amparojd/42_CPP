# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 13:28:38 by ampjimen          #+#    #+#              #
#    Updated: 2024/09/24 10:40:31 by ampjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = animals

# Files
SRCS_DIR = src/
SRCS =	main.cpp \
		AAnimal.cpp \
		Cat.cpp\
		Dog.cpp \
		Brain.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp 
		
INCS_DIR = inc/
INCLUDE = -I$(INCS_DIR)

DEPS = $(INCS_DIR)/

# Compilation Settings
CC		= c++
FLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDE) -g -fsanitize=address

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
	@echo "$(GREEN)*   $(BOLD)🟣 Abstract class 🟣   *$(RESET)"
	@echo "$(GREEN)****************************$(RESET)"
endef

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Deleted files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable '$(NAME)' has been deleted $(RESET)"

re: fclean all


.PHONY: all clean fclean re
