CFLAGS := -g -Wall
CC := gcc
RM := rm

SRC_PATH := src/
OBJ_PATH := build/
INC_PATH := -Iinclude/

TARGET := udp_client
DEPS := transport.o network.o l1nk.o utils.o
SRC := $(notdir $(wildcard $(SRC_PATH)*.c ))
OBJ := $(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))
DEPS := $(addprefix $(OBJ_PATH), $(DEPS))

.PHONY: clean

all: $(TARGET)

.SECONDEXPANSION:
$(TARGET): $(DEPS) $(OBJ_PATH)$$@.o
	@echo [INFO] Creating Binary Executable [$@]
	@$(CC) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH) 

clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*
	@$(RM) -rfv $(TARGET)