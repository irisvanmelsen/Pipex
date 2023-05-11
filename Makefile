# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 17:56:52 by ivan-mel          #+#    #+#              #
#    Updated: 2023/05/11 15:01:45 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	pipex
LIBS		:=	./libft/libft.a
HEADER		:=	-I libft
HEADERS		:=	libft/libft.h

#UTILS
FLAGS 		=	-Wall -Werror -Wextra
CC 			= 	gcc
RM 			=	rm -rf
SRC			=	main.c \
				parsing.c \
				parsing_utils.c \
				free.c \
				error.c

#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src

# Reset
Color_Off	=	"\033[0m"			# Text Reset

# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

# Avoid relinking in bonus
ifdef WITH_BONUS
	OBJ_RAW = $(OBJ_FILES) $(OBJB_FILES)
else
	OBJ_RAW = $(OBJ_FILES)
endif

# Add obj / src directory to obj / src path
OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all:	${NAME}

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${MAKE} -C libft
	@${CC} $^ ${LIBS} ${FLAGS} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
# @mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
#bonus:
#	@$(MAKE) WITH_BONUS=true all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${OBJ_DIR}
fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${NAME}
	
re:	fclean all

.PHONY: all bonus clean fclean re