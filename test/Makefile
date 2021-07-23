## ==> make -f Makefile

TARGET := tests

API_DIR := ../OesApi_0.16.1.9-20201120/oes_libs-0.16.1.9-release

SRCS := $(wildcard ./*.cpp) $(wildcard $(API_DIR)/samples/oes_sample_cpp/oes_client_sample.cpp)
OBJS := $(patsubst %cpp,%o,$(SRCS))

INC_DIR   = $(API_DIR)/include
LIB_DIR   = $(API_DIR)/linux64

CC_CFLAGS = -g -Wall
CC_LFLAGS = -loes_api -lpthread -lm -lgtest_main -lgtest


all : $(TARGET) cleanObjs

$(TARGET) : $(OBJS)
	g++ -L$(LIB_DIR) -o $(TARGET) $(OBJS) $(CC_LFLAGS)

%.o : %.cpp
	g++ $(CC_CFLAGS) -I$(INC_DIR) -I$(API_DIR)/samples/oes_sample_cpp -o $@ -c $<

.PHONY : cleanObjs
cleanObjs:
	rm -f $(OBJS)

.PHONY : clean
clean:
	rm -f $(OBJS) $(TARGET)
