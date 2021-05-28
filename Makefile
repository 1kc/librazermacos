NAME=librazermacos.so
SRC=src
OBJ=obj

SOURCES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

CC=gcc
# Flags and Header
CFLAGS=-Wall -Wextra -Werror -Iinclude -framework CoreFoundation -framework IOKit 


all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(NAME)
	@printf "$(BLUE) ✗ Deletion of object files\n";
	@printf "$(RED) ✗ Deletion of $(NAME)\n";


# Remake
re: clean all
        

$(NAME): $(OBJECTS)
	@$(CC) -Iinclude -fPIC $(CFLAGS) -o $@ $^ -shared 
	@printf "$(GREEN) ✓ Building $(NAME)\n"
 
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@$(CC) -I$(SRC) -c $< -o $@
	@printf "$(GREEN) ✓ Building $@\n"

$(OBJ):
	@mkdir -p $@
	@printf "$(GREEN) ✓ Creating $(OBJ) dir\n"
