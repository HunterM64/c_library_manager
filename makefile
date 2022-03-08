#compiler
CC = gcc

#compiler flags 
CFLAGS = -Wall -lncurses -lmenu -I/usr/include/mysql -L/usr/lib64/mysql -lmysqlclient -lpthread -lz -lm -ldl -lssl -lcrypto

#build target executable
TARGET = library

all: $(TARGET)

$(TARGET): $(TARGET).c $(TARGET).h
	$(CC) -o $(TARGET) $(TARGET).c $(CFLAGS)

clean:
	$(RM) $(TARGET)