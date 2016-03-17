CXX = g++
CFLAGS = -std=c++11
LFLAGS = -lconfig++ -lev
TARGET = httpd

main = main.cpp
server = server/server.cpp server/server.h server/server_conf.cpp server/server_conf.h
SOURCES = $(main) $(server)

all:
	$(CXX) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LFLAGS)