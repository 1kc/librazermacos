.PHONY: all clean re

NAME=razermacos
LIB_TARGET_NAME=lib$(NAME).so
SRC=src
LIB=lib
OBJ=obj
INCLUDE=include

LIB_SOURCES=$(wildcard $(SRC)/$(LIB)/*.c)
LIB_OBJECTS=$(patsubst $(SRC)/$(LIB)/%.c, $(OBJ)/%.o, $(LIB_SOURCES))

CLI_SOURCES=$(wildcard $(SRC)/*.c)
CLI_OBJECTS=$(patsubst $(SRC)//%.c, $(OBJ)/%.o, $(CLI_SOURCES))

GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

CC=gcc

# Flags and Header
ARCHFLAGS=-arch arm64 -arch x86_64
OSFLAGS=-mmacosx-version-min=10.5
CFLAGS=-Wall -Wextra -framework CoreFoundation -framework IOKit 

all: sample_cli

clean:
	@rm -f $(LIB_OBJECTS) $(LIB_TARGET_NAME)
	@printf "$(BLUE) ✗ Deletion of object files\n";
	@printf "$(RED) ✗ Deletion of $(LIB_TARGET_NAME)\n";
	@printf "$(RED) ✗ Deletion of sample_cli\n";

# Remake
re: clean all

sample_cli: $(LIB_TARGET_NAME) $(CLI_OBJECTS)
	@$(CC) $(ARCHFLAGS) $(OSFLAGS) $(CFLAGS) -L. -I$(SRC)/$(INCLUDE) -o sample_cli $(SRC)/sample_cli.c -l$(NAME)
	@printf "$(GREEN) ✓ Building sample_cli\n"


$(LIB_TARGET_NAME): $(LIB_OBJECTS)
	@$(CC) $(ARCHFLAGS) $(OSFLAGS) $(CFLAGS) -fPIC -o $@ $^ -shared
	@printf "$(GREEN) ✓ Building $(LIB_TARGET_NAME)\n"
 
$(OBJ)/%.o: $(SRC)/$(LIB)/%.c | $(OBJ)
	@$(CC) $(ARCHFLAGS) $(OSFLAGS) -I$(SRC)/$(INCLUDE) -c $< -o $@
	@printf "$(GREEN) ✓ Building $@\n"

$(OBJ):
	@mkdir -p $@
	@printf "$(GREEN) ✓ Creating $(OBJ) dir\n"
