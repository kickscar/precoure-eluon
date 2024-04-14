CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGET = helloworld
OBJS = main.o helloworld.o

$(TARGET): $(OBJS) | $(TARGET_DIR)
	$(CC) -o $(TARGET_DIR)/$@ $^

$(TARGET_DIR):
	mkdir -p $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS) $(TARGET_DIR)
	