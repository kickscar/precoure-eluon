CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGET = $(TARGET_DIR)/helloworld
OBJS = $(TARGET_DIR)/main.o $(TARGET_DIR)/helloworld.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS) $(TARGET_DIR)
	