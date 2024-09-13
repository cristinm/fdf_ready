# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 16:08:44 by cristinm          #+#    #+#              #
#    Updated: 2024/08/24 14:20:24 by cristinm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

# Name of the library
NAME = libft.a
NAME_BONUS = .bonus
# Source files
SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_is_space.c\
		ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
		ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
		ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c  \
		ft_isascii.c ft_memcpy.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c \
		ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
		ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
		ft_strtrim.c ft_striteri.c get_next_line.c get_next_line_utils.c

SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
# Compiler to use
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror
# Remove command with -f to avoid error if no file
RM = rm -f
INCLUDE = libft.h

# RULES

all: $(NAME) # Default rule: creates the library

$(NAME): $(OBJS) $(INCLUDE) # Dependencies of the library
	ar rcs  $(NAME) $(OBJS)
# ar: archive; rcs: replace, create, index symbol table 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	touch .bonus
	
clean: # Clean object files created during compilation.
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean # Clean object files and the library
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all # re: rebuild. Clean and build again

.PHONY : all clean fclean re 
# Phony targets: not associated with files. Rules always executed even if file 
#with same name exists


