# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awallet <awallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 18:03:30 by awallet           #+#    #+#              #
#    Updated: 2022/07/26 21:25:33 by awallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   ft_atoi.c \
       		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_striteri.c \
		ft_itoa.c \
		ft_usleep.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
       		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_strstr.c \
		ft_rev_print.c \
		ft_strcspn.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_printf.c \
		ft_print_base.c \
		ft_print_nbr.c \
		ft_print_ptr.c \
		ft_print_utils.c
		       
OBJS = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

%.o:  %.c 
	${CC} ${CCFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re
