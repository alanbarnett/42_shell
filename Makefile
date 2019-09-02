# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 13:42:22 by alan              #+#    #+#              #
#    Updated: 2019/09/02 14:00:51 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuration is done in config.mk, you shouldn't need to edit this file!

# Includes all needed variables
include config.mk

C_SRCS :=		$(wildcard $(SRC_DIR)/*.c)
#C_SRCS +=		$(wildcard $(SRC_DIR)/builtins/*.c)
#C_SRCS +=		$(wildcard $(SRC_DIR)/command/*.c)
#C_SRCS +=		$(wildcard $(SRC_DIR)/environment/*.c)
#C_SRCS +=		$(wildcard $(SRC_DIR)/expansions/*.c)
C_OBJS :=		$(patsubst %.c,%.o,$(C_SRCS))
DEPENDS :=		$(patsubst %.c,%.d,$(C_SRCS))
DEPFLAGS +=		-MMD -MT $@

MAKE_LIBRARY :=	make -C $(LIB_DIR) -f $(LIB_MAKEFILE) --no-print-directory
LIB :=			$(LIB_DIR)/$(LIB_NAME)

.PHONY:			all clean fclean re install

all: tags $(NAME)

tags: $(C_SRCS) $(LIB_SRCS)
	@- ctags -R

$(LIB): $(LIB_SRCS)
	@ $(MAKE_LIBRARY)

$(NAME): $(LIB) $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPENDS)

clean:
	@- $(MAKE_LIBRARY) clean
	@- $(RM) $(C_OBJS) $(DEPENDS)

fclean: clean
	@- $(MAKE_LIBRARY) fclean
	@- $(RM) $(NAME)

re: fclean all

install: $(NAME)
	ln -siv $(shell pwd)/$(NAME) ~/bin/oort
