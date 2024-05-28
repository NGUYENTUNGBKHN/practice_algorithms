
BUILD_DIR=build
OBJS_DIR=$(BUILD_DIR)/objs

FLATFORM=$(shell uname)

ifeq ($(FLATFORM),Linux)
TARGET_NAME=queue
else
TARGET_NAME=queue.exe
endif

CC=gcc
SIZE=size

CCFLAGS=

LIBS=

SRC_FILE=$(wildcard *.c)

INC_FOLDER= \

OBJECTS=$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILE))

.PHONY: all clean default

default: all

all: $(BUILD_DIR)/$(TARGET_NAME)

$(BUILD_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(LIBS) $(INC_FOLDER) -c $< -o $@


$(BUILD_DIR)/$(TARGET_NAME): $(OBJECTS)
	@echo "LINK $@"
	@$(CC) $(CCFLAGS) $(LIBS) $(INC_FOLDER) $(OBJECTS) -o $@
	@$(SIZE) $@ 


clean:
	rm -r $(BUILD_DIR)



