# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:52:05 by vsteffen          #+#    #+#              #
#    Updated: 2019/04/15 16:08:26 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	=	LibftASM
NAME	=	libfts.a

CC		=	/usr/bin/clang
RM		=	/bin/rm
MAKE	=	/usr/bin/make -C
MKDIR	=	/bin/mkdir -p
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
NASM	=	nasm
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


COMPILE = no

define PRINT_RED
    @printf "\033[31m$(1)\033[0m"
endef

define PRINT_GREEN
    @printf "\033[32m$(1)\033[0m"
endef

define PRINT_YELLOW
    @printf "\033[33m$(1)\033[0m"
endef

define PRINT_STATUS
	@printf '['
	$(if $(filter $(2),SUCCESS),$(call PRINT_GREEN,$(1)))
	$(if $(filter $(2),FAIL),$(call PRINT_RED,$(1)))
	$(if $(filter $(2),WARN),$(call PRINT_YELLOW,$(1)))
	$(if $(filter $(2),INFO),printf $(1))
	$(if $(filter $(3),-n),printf $(1),echo ']')
endef

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OPATH) $(OBJ)
	$(if $(filter $(COMPILE),yes),@echo ']')
	@printf $(PROJECT)": Building $@ ... "
	@$(AR) rc $@ $(OBJ)
	@$(RANLIB) $@
	@$(call PRINT_STATUS,DONE,SUCCESS)

$(OPATH)/%.o: $(ASMPATH)/%.s
	@$(NASM) -f macho64 -o $@ $<
	$(if $(filter $(COMPILE),no),@printf $(PROJECT)': Files compiling [')
	@$(eval COMPILE := yes)
	$(call PRINT_GREEN,.)

$(OPATH):
	@$(MKDIR) $@ $@$(PRINTF)
	@echo $(PROJECT)": Directory for objects created"

clean:
	@$(RM) -Rf $(OPATH)
	@echo $(PROJECT)": Objects cleaned "
	@printf $(PROJECT)": clean rule "
	@$(call PRINT_STATUS,DONE,SUCCESS)

fclean: clean
	@$(RM) -f $(NAME)
	@echo $(PROJECT)": executable clean"
	@printf $(PROJECT)": fclean rules "
	@$(call PRINT_STATUS,DONE,SUCCESS)

re: fclean all
