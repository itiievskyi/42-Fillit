# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 12:47:31 by itiievsk          #+#    #+#              #
#    Updated: 2018/04/04 17:11:25 by averemiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ_PATH = ./obj/

SRC_LIB_NAME = ft_atoi.c ft_bzero.c ft_strlen.c ft_memset.c ft_strcat.c ft_strdup.c \
	  ft_strncat.c ft_strncpy.c ft_memcpy.c ft_strcpy.c ft_strchr.c ft_strrchr.c \
	  ft_strcmp.c ft_strstr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memccpy.c \
	  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strlcat.c \
	  ft_memalloc.c ft_memdel.c ft_strtrim.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJ_LIB_NAME = $(SRC_LIB_NAME:.c=.o)

SRC_LIB_PATH = ./srcl/
SRC_LIB_PATH_OBJ = ./objlib/

SRC_PATH = ./
SRC_NAME = 	main.c\
			ft_check_tetr.c\
			ft_quit.c\
			ft_create_tetr_list.c\
			ft_solve.c\
			ft_malloc_arr.c\
			ft_record_str.c\
			ft_erase_array.c\
			ft_delete_list.c\
			ft_clean_all.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = fillit.h

LIB = libft.a

CFLAGS = -Werror -Wall -Wextra

LIB_SRC = $(addprefix $(SRC_LIB_PATH), $(SRC_LIB_NAME))
LIB_OBJ = $(addprefix $(SRC_LIB_PATH_OBJ), $(OBJ_LIB_NAME))
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	ar rc $(LIB) $(LIB_OBJ)
	gcc $(CFLAGS) $(INC) -o $(NAME) $(LIB) $(OBJ)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	gcc $(CFLAGS) $(INC) $< -o $@ -c

$(SRC_LIB_PATH_OBJ)%.o: $(SRC_LIB_PATH)%.c
	@mkdir $(SRC_LIB_PATH_OBJ) 2> /dev/null || echo "" > /dev/null
	gcc $(CFLAGS) $< -o $@ -c

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	rm -fv $(LIB_OBJ)
	@rmdir $(SRC_LIB_PATH_OBJ) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)
	rm -fv $(LIB)

re: fclean all

.PHONY: all clean fclean re norme
