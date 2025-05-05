# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 12:54:07 by nsilva-n          #+#    #+#              #
#    Updated: 2024/12/26 14:38:29 by nsilva-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	main.c														\
		ft_child.c			ft_execute.c		ft_free_split.c		\
		ft_get_path.c		ft_parent.c			ft_strjoin_gnl.c

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_LIB = ./lib/libft
INCLUDE_LFT = ./lib/libft/libft.a

all: $(LIBFT) $(NAME)

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C $(LIBFT_LIB)
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} $(INCLUDE_LFT)

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C ./$(LIBFT_LIB)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./$(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re