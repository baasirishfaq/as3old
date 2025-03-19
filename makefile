# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall
INCLUDE = -Iinclude

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/ishfaqBaasirA3Main.c \
       $(SRC_DIR)/createPlayList.c \
       $(SRC_DIR)/addNewSong.c \
       $(SRC_DIR)/playPlayList.c \
       $(SRC_DIR)/playSongGivenId.c \
       $(SRC_DIR)/playSongGivenName.c \
       $(SRC_DIR)/countNotesInASong.c \
       $(SRC_DIR)/deleteASongGivenId.c \
       $(SRC_DIR)/deletePlayList.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = $(BIN_DIR)/musicalLL

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
