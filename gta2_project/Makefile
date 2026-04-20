# ==============================================================================
# Makefile для GTA 2 Reversed Engine
# ==============================================================================
# REVERSE ENGINEERING LOG:
# Этот файл заменяет оригинальный проект Visual Studio из IDA Pro.
# Оригинал: gta2.exe/gid/gta2.exe.vcp
# 
# Компиляция: make
# Очистка: make clean
# Запуск: ./gta2
# ==============================================================================

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -O2
CFLAGS += -I./include -I./include/core -I./include/ai -I./include/math_types

# Линковщик
LDFLAGS = -lm

# Для Windows раскомментировать:
# LDFLAGS += -lgdi32 -ldinput8 -lddraw -lwinmm
# Для Linux (SDL2):
# LDFLAGS += $(shell sdl2-config --cflags --libs)

# Директории
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Исходные файлы
CORE_SRCS = $(SRC_DIR)/core/memory_pool.c \
            $(SRC_DIR)/core/random.c \
            $(SRC_DIR)/core/time_manager.c \
            $(SRC_DIR)/core/event_manager.c

MATH_SRCS = $(SRC_DIR)/math_types/vector2d.c \
            $(SRC_DIR)/math_types/rect2d.c

AI_SRCS = $(SRC_DIR)/ai/ped_ai.c

GAME_SRCS = $(SRC_DIR)/collision.c \
            $(SRC_DIR)/navigation.c \
            $(SRC_DIR)/world_objects.c \
            $(SRC_DIR)/camera.c \
            $(SRC_DIR)/game_objects.c

ENTITY_SRCS = $(SRC_DIR)/vehicle_pool.c \
              $(SRC_DIR)/ped_pool.c \
              $(SRC_DIR)/player.c \
              $(SRC_DIR)/weapon.c

SYSTEM_SRCS = $(SRC_DIR)/resource_loader.c \
              $(SRC_DIR)/sound_manager.c \
              $(SRC_DIR)/renderer.c \
              $(SRC_DIR)/hud.c \
              $(SRC_DIR)/savegame.c

GAMEPLAY_SRCS = $(SRC_DIR)/mission_manager.c \
                $(SRC_DIR)/menu_system.c \
                $(SRC_DIR)/debug_console.c

MAIN_SRC = $(SRC_DIR)/main.c

# Все исходники
SRCS = $(CORE_SRCS) $(MATH_SRCS) $(AI_SRCS) $(GAME_SRCS) $(ENTITY_SRCS) \
       $(SYSTEM_SRCS) $(GAMEPLAY_SRCS) $(MAIN_SRC)

# Объектные файлы
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Целевой файл
TARGET = $(BIN_DIR)/gta2

# ==============================================================================
# Правила сборки
# ==============================================================================

.PHONY: all clean dirs run

all: dirs $(TARGET)
	@echo "=========================================="
	@echo "Сборка завершена: $(TARGET)"
	@echo "=========================================="

dirs:
	@mkdir -p $(OBJ_DIR)/core
	@mkdir -p $(OBJ_DIR)/math_types
	@mkdir -p $(OBJ_DIR)/ai
	@mkdir -p $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "[LINK] Создание исполняемого файла..."

# Компиляция исходников
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[CC] $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	@echo "[CLEAN] Удаление объектных файлов..."
	rm -rf $(OBJ_DIR)/*
	rm -f $(TARGET)
	@echo "[CLEAN] Готово."

# Запуск игры
run: $(TARGET)
	@echo "[RUN] Запуск игры..."
	./$(TARGET)

# Отладочная сборка
debug: CFLAGS += -DDEBUG -g3 -O0
debug: clean all

# Проверка зависимостей
depend:
	@makedepend -- $(CFLAGS) -- $(SRCS) 2>/dev/null || true

# Информация о проекте
info:
	@echo "GTA 2 Reversed Engine"
	@echo "Компилятор: $(CC)"
	@echo "Флаги: $(CFLAGS)"
	@echo "Исходников: $(words $(SRCS))"
	@find $(SRC_DIR) -name "*.c" | wc -l
	@find $(INC_DIR) -name "*.h" | wc -l

# Помощь
help:
	@echo "Доступные команды:"
	@echo "  make        - Сборка проекта"
	@echo "  make clean  - Очистка объектных файлов"
	@echo "  make run    - Сборка и запуск"
	@echo "  make debug  - Отладочная сборка"
	@echo "  make info   - Информация о проекте"
	@echo "  make help   - Эта справка"

# ==============================================================================
# Конец Makefile
# ==============================================================================
