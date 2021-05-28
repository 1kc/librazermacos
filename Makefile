NAME=razermacos
LIB_TARGET_NAME=lib$(NAME).so
SRC=src
LIB=lib
OBJ=obj
INCLUDE=include

LIBRARY_SOURCES=$(wildcard $(SRC)/$(LIB)/*.c)
OBJECTS=$(patsubst $(SRC)/$(LIB)/%.c, $(OBJ)/%.o, $(LIBRARY_SOURCES))

GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

CC=gcc
# Flags and Header
# CFLAGS=-Wall -Wextra -Werror -framework CoreFoundation -framework IOKit 
CFLAGS=-Wall -framework CoreFoundation -framework IOKit 


# all: $(LIB_TARGET_NAME)
all: cli

clean:
	@rm -f $(OBJECTS) $(LIB_TARGET_NAME)
	@printf "$(BLUE) ✗ Deletion of object files\n";
	@printf "$(RED) ✗ Deletion of $(NAME)\n";


# Remake
re: clean all

cli: $(LIB_TARGET_NAME)
	@$(CC) $(CFLAGS) -L. -I$(SRC)/$(INCLUDE) -o cli $(SRC)/cli.c -l$(NAME)
	@printf "$(GREEN) ✓ Building cli\n"
        

$(LIB_TARGET_NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -fPIC -o $@ $^ -shared
	@printf "$(GREEN) ✓ Building $(LIB_TARGET_NAME)\n"
 
$(OBJ)/%.o: $(SRC)/$(LIB)/%.c | $(OBJ)
	@$(CC) -I$(SRC)/$(INCLUDE) -c $< -o $@
	@printf "$(GREEN) ✓ Building $@\n"

$(OBJ):
	@mkdir -p $@
	@printf "$(GREEN) ✓ Creating $(OBJ) dir\n"
