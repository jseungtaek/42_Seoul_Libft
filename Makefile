# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 23:26:50 by sejeon            #+#    #+#              #
#    Updated: 2022/01/07 16:56:29 by sejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isascii.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_substr.c ft_atoi.c \
	ft_isdigit.c ft_memchr.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_bzero.c ft_isprint.c \
	ft_memcmp.c ft_putendl_fd.c  ft_striteri.c ft_strncmp.c ft_toupper.c ft_calloc.c \
	ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isalnum.c ft_memmove.c \
	ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalpha.c ft_memset.c ft_split.c \
	ft_strlcpy.c ft_strtrim.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -f
all : $(NAME)
%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
bonus : $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $^
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : fclean all
.PHONY : all clean fclean re
