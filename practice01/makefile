CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGETS = prob01 prob02

all: $(TARGETS)

$(TARGETS): %: %.o  | $(TARGET_DIR)
	gcc -o $(TARGET_DIR)/$@ $^

$(TARGET_DIR):
	mkdir -p $@
	
%.o: %.c
	gcc -c $^ 

clean :
	rm -rf *.o $(TARGET_DIR)
