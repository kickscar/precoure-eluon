CC = gcc
CFLAGS = -Wall -O2
INCLUDES = -I /usr/local/poscodx2023/mariadb/include/mysql
LDFLAGS = -L /usr/local/poscodx2023/mariadb/lib -lmysqlclient
TARGET_DIR = target
TARGET = $(TARGET_DIR)/phonebook
OBJS = $(TARGET_DIR)/main.o $(TARGET_DIR)/phonebook.o $(TARGET_DIR)/phonebookdb.o

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)
	