# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:52:05 by vsteffen          #+#    #+#              #
#    Updated: 2018/09/17 16:07:12 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libfts.a

CC		=	/usr/bin/clang
RM		=	/bin/rm
MAKE	=	/usr/bin/make -C
MKDIR	=	/bin/mkdir -p
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
NASM	=	/Users/vsteffen/.brew/bin/nasm
LD		=	/usr/bin/ld
GIT		=	/usr/bin/git

OBJ		=	$(patsubst %.s, $(OPATH)/%.o, $(SRC))

CFLAGS	=	-Wall -Wextra -Werror -g

ROOT	=	$(shell /bin/pwd)
OPATH	=	$(ROOT)/objs
ASMPATH	=	$(ROOT)/srcs
HPATH	=	-I $(ROOT)/includes

TESTS	=	$(ROOT)/tests
TESTSRC	=	$(TESTS)/main.c

SRC	=	ft_atoi.s \
		ft_bzero.s \
		ft_cat.s \
		ft_isalnum.s \
		ft_isalpha.s \
		ft_isascii.s \
		ft_isdigit.s \
		ft_isprint.s \
		ft_isspace.s \
		ft_memcpy.s \
		ft_memset.s \
		ft_putchar.s \
		ft_putnbr.s \
		ft_puts.s \
		ft_putstr.s \
		ft_strcat.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_tolower.s \
		ft_toupper.s

.PHONY: all clean fclean re tests

all: $(NAME)

$(NAME): $(OPATH) $(OBJ)
	@echo "Building $@"
	@$(AR) rc $@ $(OBJ)
	@echo "\033[32m ╔════════════════╗"
	@echo " ║  All is done ! ║"
	@echo " ╚════════════════╝\033[0m"
	@$(CC) -o maintest $(TESTSRC) libfts.a $(HPATH)

$(OPATH)/%.o: $(ASMPATH)/%.s
	@$(NASM) -f macho64 -o $@ $<

$(OPATH):
	@echo "\n\033[33m\033[4m\033[1m → Libft \"Make\"\033[0m"
	@echo "Creating OBJ directory and files if they don't exist or have changed"
	@$(MKDIR) $@

clean:
	@echo "\n\033[33m\033[4m\033[1m → Libft \"Clean\"\033[0m"
	@echo "Deleting OBJS."
	@$(RM) -rf $(OPATH)
	@$(RM) -rf $(TEST)
	@echo "\033[32mOBJS deleted.\033[0m\n"

fclean: clean
	@echo "\033[33m\033[4m\033[1m → Libft \"Fclean\"\033[0m"
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@$(RM) -f maintest
	@echo "\033[32m$(NAME) deleted.\033[0m\n"

tests:
	@echo "Building maintest"
	@$(CC) -o maintest $(TESTSRC) libfts.a $(HPATH)

re: fclean all
