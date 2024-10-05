CC = g++
CFLAGS = -Wall -O2

SRCS = driver.cpp car.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = prog1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(OBJS) $(TARGET)

