CC = gcc
CFLAGS = -Wall -O2
INCLUDES = -I /usr/local/poscodx2023/mariadb/include/mysql
LDFLAGS = -L /usr/local/poscodx2023/mariadb/lib -lmysqlclient
TARGET_DIR = target
TARGETS = $(TARGET_DIR)/test_conn $(TARGET_DIR)/test_insert $(TARGET_DIR)/test_delete $(TARGET_DIR)/test_select

all: $(TARGETS)

$(TARGETS): $(TARGET_DIR)/%: $(TARGET_DIR)/%.o
	gcc $(LDFLAGS) -o $@ $^
	
$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	gcc $(CFLAGS) $(INCLUDES) -c -o $@ $^ 

clean :
	rm -rf *.o $(TARGET_DIR)
