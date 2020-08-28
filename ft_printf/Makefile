# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 14:22:41 by rlucas        #+#    #+#                  #
#    Updated: 2020/08/28 13:08:20 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = printf_tester

ifeq ($(shell uname), Linux)
	CC = gcc
else
	CC = clang
endif

INCLUDES = -Iincludes/

SRCDIR = src/

OBJDIR = obj/

LIBS = -L. -lftprintf

REAL_OUTPUT = real.output
TEST_OUTPUT = test.output
DIFF_FILE = diff.output

DEFINES = -D REAL_OUTPUT_FILE="\"$(REAL_OUTPUT)\"" \
		  -D TEST_OUTPUT_FILE="\"$(TEST_OUTPUT)\""

SRC = testmain.c

OBJ := $(addprefix $(OBJDIR), $(SRC:%.c=%.o))
SRC := $(addprefix $(SRCDIR), $(SRC))

all: $(OBJ)
	@echo "Compiling executable..."
	@$(CC) $(DEFINES) $(OBJ) -o $(NAME) $(INCLUDES) $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@echo "Compiling $@"
	@$(CC) -c $(DEFINES) -o $@ $< $(INCLUDES) $(LIBS)

clean:
	@echo "Removing objects..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Deleting executable..."
	@rm -f $(NAME)
	@echo "Deleting output files..."
	@rm -f $(REAL_OUTPUT) $(TEST_OUTPUT)
	@rm -f $(DIFF_FILE)

re: fclean all

.PHONY: clean fclean all re
