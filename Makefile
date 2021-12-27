# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 23:26:50 by sejeon            #+#    #+#              #
#    Updated: 2021/12/27 23:35:20 by sejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_isascii.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_substr.c ft_atoi.c \
       ft_isdigit.c ft_memchr.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_bzero.c ft_isprint.c \
	ft_memcmp.c ft_putendl_fd.c  ft_striteri.c ft_strncmp.c ft_toupper.c ft_calloc.c \
	ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isalnum.c ft_memmove.c \
	ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalpha.c ft_memset.c ft_split.c \
	ft_strlcpy.c ft_strtrim.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
     	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_BONUS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_BONUS)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
   	$(AR) $@ $^

bonus: $(OBJS_B)
      	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
