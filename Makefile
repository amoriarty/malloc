# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/13 12:17:39 by alegent           #+#    #+#              #
#    Updated: 2016/05/11 16:48:56 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME= libft_malloc_$(HOSTTYPE).so
SUBNAME = libft_malloc.so

SRC_PATH= sources/
SRC_NAME= free.c \
		  malloc.c \
		  realloc.c \
		  show_alloc_mem.c \
		  aligners/page_align.c \
		  aligners/ptr_align.c \
		  allocating/new_alloc.c \
		  allocating/new_block.c \
		  allocating/new_heap.c \
		  allocating/split_block.c \
		  checker/check_free_block.c \
		  checker/check_free_heap.c \
		  listing/delete_block.c \
		  listing/delete_heap.c \
		  listing/find_by_ptr.c \
		  listing/find_by_type.c \
		  listing/find_free.c \
		  listing/find_last_heap.c \
		  listing/push_block.c \
		  listing/push_heap.c \
		  tools/ft_malloc.c \
		  tools/get_preload.c \
		  tools/putnbr.c \
		  tools/singleton.c \
		  tools/print_addr.c

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

GCC= clang -Wall -Wextra -Werror

INC_LIB= libft/
INC_PATH= includes/
INC= -I $(INC_LIB) -I $(INC_PATH)

LIB= -L $(INC_LIB) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(INC_LIB)
	@$(GCC) $(INC) $(LIB) $(FRAMWORK) $(OBJ) -o $(NAME) -shared
	@ln -s $(NAME) $(SUBNAME)
	@echo "Your librairy is ready to go !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(OBJ_PATH)/aligners 2> /dev/null
	@mkdir -p $(OBJ_PATH)/allocating 2> /dev/null
	@mkdir -p $(OBJ_PATH)/checker 2> /dev/null
	@mkdir -p $(OBJ_PATH)/listing 2> /dev/null
	@mkdir -p $(OBJ_PATH)/tools 2> /dev/null
	$(GCC) $(INC) -o $@ -c $<

clean:
	@make -C $(INC_LIB) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "Object files has been deleted"

fclean: clean
	@make -C $(INC_LIB) fclean
	@rm -rf $(SUBNAME)
	@rm -rf $(NAME)
	@rm -rf main_test show_test 2> /dev/null
	@echo "Librairy has been deleted"

re: fclean all

test: re
	$(GCC) $(INC) -o main_test $(NAME) tests/main_tests.c
	$(GCC) $(INC) -o show_test $(NAME) tests/show_test.c
	@./main_test; ./show_test

norme:
	@norminette $(INC_LIB)*.[ch]
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h

.PHONY: clean fclean re norme

