# Makefile for compiling C++ files with g++

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Source directories
SRCDIR = .
DES_SRCDIR = DES
RSA_SRCDIR = RSA

# Source files
SRCS = $(wildcard *.cpp)
DESSRCS = $(wildcard $(DES_SRCDIR)/*.cpp)
RSASRCS = $(wildcard $(RSA_SRCDIR)/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)
DESOBJS = $(DESSRCS:.cpp=.o)
RSAOBJS = $(RSASRCS:.cpp=.o)

# Target executable
TARGET = chat

all: $(TARGET)

$(TARGET): $(OBJS) $(DESOBJS) $(RSAOBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DES_SRCDIR)/%.o: $(DES_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(RSA_SRCDIR)/%.o: $(RSA_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DESOBJS) $(RSAOBJS) $(TARGET)
