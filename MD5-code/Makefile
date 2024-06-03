CC = g++
CFLAGS = -Wall -std=c++11

# 源文件
SRCS = main.cpp dealwithcode.cpp Update.cpp helpFunc.cpp MD5.cpp

# 目标文件
OBJS = $(SRCS:.cpp=.o)

# 可执行文件名称
TARGET = md5

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)