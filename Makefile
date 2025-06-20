# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:49:32 by jmoucach          #+#    #+#              #
#    Updated: 2019/11/11 16:34:00 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= libft.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC= ./ft_putchar.c\
	 ./ft_putchar_fd.c\
	 ./ft_putnbr.c\
	 ./ft_putnbr_fd.c\
	 ./ft_putstr.c\
	 ./ft_putstr_fd.c\
	 ./ft_putendl.c\
	 ./ft_putendl_fd.c\
	 ./ft_strlen.c\
	 ./ft_isalpha.c\
	 ./ft_isdigit.c\
	 ./ft_isalnum.c\
	 ./ft_isascii.c\
	 ./ft_isprint.c\
	 ./ft_toupper.c\
	 ./ft_tolower.c\
	 ./ft_strcmp.c\
	 ./ft_strncmp.c\
	 ./ft_strcpy.c\
	 ./ft_strncpy.c\
	 ./ft_strdup.c\
	 ./ft_strcat.c\
	 ./ft_strncat.c\
	 ./ft_strlcat.c\
	 ./ft_atoi.c\
	 ./ft_itoa.c\
	 ./ft_strstr.c\
	 ./ft_strnstr.c\
	 ./ft_strchr.c\
	 ./ft_strrchr.c\
	 ./ft_strequ.c\
	 ./ft_strnequ.c\
	 ./ft_strclr.c\
	 ./ft_striter.c\
	 ./ft_striteri.c\
	 ./ft_strmap.c\
	 ./ft_strmapi.c\
	 ./ft_strnew.c\
	 ./ft_strdel.c\
	 ./ft_strsub.c\
	 ./ft_strjoin.c\
	 ./ft_strtrim.c\
	 ./ft_strsplit.c\
	 ./ft_memset.c\
	 ./ft_memalloc.c\
	 ./ft_memdel.c\
	 ./ft_memcpy.c\
	 ./ft_memccpy.c\
	 ./ft_memcmp.c\
	 ./ft_memmove.c\
	 ./ft_memchr.c\
	 ./ft_bzero.c\
	 ./ft_lstnew.c\
	 ./ft_lstdelone.c\
	 ./ft_lstdel.c\
	 ./ft_lstadd.c\
	 ./ft_lstiter.c\
	 ./ft_lstmap.c\
	 ./ft_strrev.c\
	 ./get_next_line.c\
	 ./ft_sqrt.c\
	 ./ft_replace.c\
	 ./ft_strtrimc.c\
	 ./ft_strlen_chr.c\
	 ./ft_abs.c\
	 ./ft_htoi.c
SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR= obj/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
INCLUDES=	libft.h
###############################################################################
#								Rules										  #
###############################################################################

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@ echo "$(GREEN)Creating $@ executable$(WHITE)"
	@ ar rc $(NAME) $(OBJS)
	@ ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INCLUDES) Makefile
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
ifneq ($(wildcard $(OBJ_DIR)*.o), )
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(wildcard $(OBJ_DIR)*.o); do \
		rm -rf $$i;\
		echo "$(RED)- Deleted $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
endif

fclean: clean
ifneq ($(wildcard $(OBJ_DIR)/), )
	@ rm -rf $(wildcard $(OBJ_DIR))
	@ echo "$(YELLOW)Deleted obj directory...$(WHITE)"
endif
ifneq ($(wildcard $(NAME)), )
	@ rm -rf $(NAME)
	@ echo "$(GREEN)Executable deleted$(WHITE)"
endif

re: fclean all

FORCE:

.PHONY: all re fclean clean