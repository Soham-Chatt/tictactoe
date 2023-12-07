CC = g++
CFLAGS = -Wall -g -O3 -MMD -MP
TARGET = main

SRCS := main.cc game.cc
HEADERS := game.h
OBJS := $(SRCS:.cc=.o)
DEPS := $(SRCS:.cc=.d)

-include $(DEPS)

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
