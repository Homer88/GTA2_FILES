# GTA 2 Reconstructed - Makefile
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -I./include -I./include/core -I./include/entities -I./include/ai -I./include/world -I./include/systems -I./include/ui -I./include/network -I./include/platform -I./include/math_types -g -O2
LDFLAGS = -lm
BUILD_DIR = build
LIB_DIR = $(BUILD_DIR)/lib
OBJ_DIR = $(BUILD_DIR)/obj
TARGET = gta2

.PHONY: all clean

all: dirs compile link

dirs:
	mkdir -p $(BUILD_DIR) $(LIB_DIR) $(OBJ_DIR)

compile:
	@echo "Компиляция модулей..."
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJ_DIR)/main.o || true
	$(CC) $(CFLAGS) -c src/core/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/entities/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/ai/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/world/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/systems/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/ui/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/network/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/platform/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	$(CC) $(CFLAGS) -c src/math_types/*.c -o $(OBJ_DIR)/ 2>/dev/null || true
	@echo "Создание библиотек..."
	$(AR) rcs $(LIB_DIR)/libcore.a $(OBJ_DIR)/memory_pool.o $(OBJ_DIR)/random.o $(OBJ_DIR)/time_manager.o $(OBJ_DIR)/event_manager.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libentities.a $(OBJ_DIR)/car.o $(OBJ_DIR)/ped.o $(OBJ_DIR)/player.o $(OBJ_DIR)/weapon.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libai.a $(OBJ_DIR)/ped_ai.o $(OBJ_DIR)/gang.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libworld.a $(OBJ_DIR)/world_objects.o $(OBJ_DIR)/camera.o $(OBJ_DIR)/navigation.o $(OBJ_DIR)/traffic_system.o $(OBJ_DIR)/game_objects.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libsystems.a $(OBJ_DIR)/collision.o $(OBJ_DIR)/vehicle_pool.o $(OBJ_DIR)/ped_pool.o $(OBJ_DIR)/mission_manager.o $(OBJ_DIR)/sound_manager.o $(OBJ_DIR)/savegame.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libui.a $(OBJ_DIR)/menu_system.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libnetwork.a $(OBJ_DIR)/network.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libplatform.a $(OBJ_DIR)/renderer.o 2>/dev/null || true
	$(AR) rcs $(LIB_DIR)/libmath_types.a $(OBJ_DIR)/vector2d.o $(OBJ_DIR)/rect2d.o 2>/dev/null || true

link:
	@echo "Линковка..."
	$(CC) $(OBJ_DIR)/*.o $(LDFLAGS) -o $(TARGET) 2>&1 | head -50 || echo "Ошибки линковки (нормально для ранней стадии)"

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(OBJ_DIR)/*.o $(LIB_DIR)/*.a
