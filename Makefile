#CC=gcc
#CPPFLAGS=-Wall -Wextra -Werror -std=gnu99 -O3

#SRC=src/util.o src/board.o src/precalc.o src/ai.o src/interface.o src/main.o src/test.o
#TARGET=2048

#all: $(SRC)
#	$(CC) -o $(TARGET) $(SRC) $(CPPFLAGS)

#clean:
#	rm -f $(TARGET) src/*.o

#----------------options----------------#
#environment
CC = gcc
FLAGS_DEBUG = -g
FLAGS_COMPILE = -c -Wall -Wextra -Werror -std=gnu99 -O3

#directory
SHELL = /bin/sh
DIR = $(PWD)
DIR_OBJ = $(DIR)/obj/
DIR_SRC = $(DIR)/src/
DIR_BIN = $(DIR)/bin/
DIR_LIB = $(DIR)/lib/
DIR_INC = $(DIR)/inc/

#target
TARGET = 2048

#vpath
#vpath %.cpp $(DIR_SRC)
#vpath %.o $(DIR_OBJ)

#src
SRC=$(wildcard ${DIR_SRC}*.c)

#include
INC=-I$(DIR_INC)

#lib
#LIBS depends on your needs
#for instance: LIBS=-lsky which means there is a libsky.a file in DIR_LIB direction
LIBS=
LIB=-L$(DIR_LIB)$(LIBS)

#obj
OBJ=$(patsubst %.c,${DIR_OBJ}%.o,$(notdir ${SRC}))

#----------------macro---------------#
.PHONY:dir clean make
#debug
debug:$(OBJ)
	@echo "linking..."
	@cd $(DIR_OBJ);$(CC) *.o -o $(DIR_BIN)$(TARGET)
	@echo "linking end..."
	@echo "execute the $(TARGET) in $(DIR_BIN)$(TARGET)"

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	@echo "compiling..."
	@echo "SRC:$<"
	$(CC) $(FLAGS_DEBUG) $(FLAGS_COMPILE) $< -o $@
	@echo "compiling end..."

#clean
clean:
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_BIN)

#objects & executable direction
dir:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_BIN)

#help
help:
	@echo "......------------Makefile------------......"
	@echo "Include four commands: #1.de; #2.clean; #3.dir; #4.help"
	@echo "#1.de:"
	@echo "    debug the source file into a executable file that is included in the $(DIR_BIN)!"
	@echo "#2.clean:"
	@echo "    delete the debug files and directions"
	@echo "#3.dir:"
	@echo "    mkdir a new directions for objects and executable file:"
	@echo "    $(DIR_BIN) for executable file"
	@echo "    $(DIR_OBJ) for object file"
	@echo "#4.help:"
	@echo "    help for using this makefile to debug a project which includes source files include files"
	@echo "......------------End------------......"

#make all the commands and get the executable file
make:
	@echo "start debugging..."
	@$(MAKE) -s dir
	@$(MAKE) -s debug
	@echo "finish..."
	@echo "******************************"
	@echo "*    ____  ____  _   ________*"
	@echo "*   / __ \/ __ \/ | / / ____/*"
	@echo "*  / / / / / / /  |/ / __/   *"
	@echo "* / /_/ / /_/ / /|  / /___   *"
	@echo "*/_____/\____/_/ |_/_____/   *"
	@echo "******************************"
	@echo "You want the executable file run itself?"
	@echo "'Y' for yes,'N' for no"
	@read -s -n1 key;\
		read -s -n5 interface;\
		Y="Y";\
		y="y";\
		if [ $$key == $$Y ] || [ $$key == $$y ]; then\
		cd $(DIR_BIN);\
		$(DIR_BIN)$(TARGET) --$$interface;\
		exit 0;\
		else\
		echo "Not Execute the File!";\
		fi
	@echo "done"


