CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGETS = $(TARGET_DIR)/ex01 $(TARGET_DIR)/ex02 $(TARGET_DIR)/ex03 $(TARGET_DIR)/ex04 $(TARGET_DIR)/ex05

all: $(TARGETS)

$(TARGETS): $(TARGET_DIR)/%: $(TARGET_DIR)/%.o
	gcc -o $@ $^
	
$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	gcc $(CFLAGS) -c -o $@ $^ 

clean:
	rm -rf $(TARGET_DIR)