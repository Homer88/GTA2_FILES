CC = gcc
CFLAGS = -Wall -Wextra -g -I./include -I./include/core -I./include/entities -I./include/world -I./include/systems -I./include/ui -I./include/ai -I./include/math_types -I./include/network -I./include/utils
LDFLAGS = -lm

OBJ_DIR = obj
LIB_DIR = lib

CORE_LIB = $(LIB_DIR)/libcore.a
ENTITIES_LIB = $(LIB_DIR)/libentities.a
WORLD_LIB = $(LIB_DIR)/libworld.a
SYSTEMS_LIB = $(LIB_DIR)/libsystems.a
UI_LIB = $(LIB_DIR)/libui.a
AI_LIB = $(LIB_DIR)/libai.a
MATH_LIB = $(LIB_DIR)/libmath.a
NETWORK_LIB = $(LIB_DIR)/libnetwork.a

ALL_LIBS = $(CORE_LIB) $(ENTITIES_LIB) $(WORLD_LIB) $(SYSTEMS_LIB) $(UI_LIB) $(AI_LIB) $(MATH_LIB) $(NETWORK_LIB)

CORE_SRCS = $(wildcard src/core/*.c)
ENTITIES_SRCS = $(wildcard src/entities/*.c)
WORLD_SRCS = $(wildcard src/world/*.c)
SYSTEMS_SRCS = $(wildcard src/systems/*.c)
UI_SRCS = $(wildcard src/ui/*.c)
AI_SRCS = $(wildcard src/ai/*.c)
MATH_SRCS = $(wildcard src/math_types/*.c)
NETWORK_SRCS = $(wildcard src/network/*.c)

CORE_OBJS = $(patsubst src/core/%.c,$(OBJ_DIR)/core/%.o,$(CORE_SRCS))
ENTITIES_OBJS = $(patsubst src/entities/%.c,$(OBJ_DIR)/entities/%.o,$(ENTITIES_SRCS))
WORLD_OBJS = $(patsubst src/world/%.c,$(OBJ_DIR)/world/%.o,$(WORLD_SRCS))
SYSTEMS_OBJS = $(patsubst src/systems/%.c,$(OBJ_DIR)/systems/%.o,$(SYSTEMS_SRCS))
UI_OBJS = $(patsubst src/ui/%.c,$(OBJ_DIR)/ui/%.o,$(UI_SRCS))
AI_OBJS = $(patsubst src/ai/%.c,$(OBJ_DIR)/ai/%.o,$(AI_SRCS))
MATH_OBJS = $(patsubst src/math_types/%.c,$(OBJ_DIR)/math_types/%.o,$(MATH_SRCS))
NETWORK_OBJS = $(patsubst src/network/%.c,$(OBJ_DIR)/network/%.o,$(NETWORK_SRCS))

MAIN_SRC = src/main.c
MAIN_OBJ = $(OBJ_DIR)/main.o
TARGET = gta2.exe

.PHONY: all clean dirs libs

all: dirs libs $(TARGET)

dirs:
	mkdir -p $(OBJ_DIR)/core $(OBJ_DIR)/entities $(OBJ_DIR)/world $(OBJ_DIR)/systems $(OBJ_DIR)/ui $(OBJ_DIR)/ai $(OBJ_DIR)/math_types $(OBJ_DIR)/network
	mkdir -p $(LIB_DIR)

libs: $(ALL_LIBS)

$(CORE_LIB): $(CORE_OBJS)
	ar rcs $@ $^

$(ENTITIES_LIB): $(ENTITIES_OBJS)
	ar rcs $@ $^

$(WORLD_LIB): $(WORLD_OBJS)
	ar rcs $@ $^

$(SYSTEMS_LIB): $(SYSTEMS_OBJS)
	ar rcs $@ $^

$(UI_LIB): $(UI_OBJS)
	ar rcs $@ $^

$(AI_LIB): $(AI_OBJS)
	ar rcs $@ $^

$(MATH_LIB): $(MATH_OBJS)
	ar rcs $@ $^

$(NETWORK_LIB): $(NETWORK_OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/core/%.o: src/core/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/entities/%.o: src/entities/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/world/%.o: src/world/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/systems/%.o: src/systems/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ui/%.o: src/ui/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ai/%.o: src/ai/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/math_types/%.o: src/math_types/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/network/%.o: src/network/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(MAIN_OBJ) $(ALL_LIBS)
	$(CC) $(MAIN_OBJ) $(ALL_LIBS) $(LDFLAGS) -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(TARGET)
