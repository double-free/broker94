## ==> make -f Makefile

TARGET := option_api_tester

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst %cpp,%o,$(SRCS))

INC_DIR   = OesApi_0.16.1.9-20201120/oes_libs-0.16.1.9-release/include
LIB_DIR   = OesApi_0.16.1.9-20201120/oes_libs-0.16.1.9-release/linux64
#LIB_DIR   = ../../macos64
#LIB_DIR   = ../../win32
#LIB_DIR   = ../../win64

CC_CFLAGS = -g -Wall
CC_LFLAGS = -loes_api -lpthread -lm


all : $(TARGET) cleanObjs

$(TARGET) : $(OBJS)
	g++ -L$(LIB_DIR) -o $(TARGET) $(OBJS) $(CC_LFLAGS)

%.o : %.cpp
	g++ $(CC_CFLAGS) -I$(INC_DIR) -o $@ -c $<

.PHONY : cleanObjs
cleanObjs:
	rm -f $(OBJS)

.PHONY : clean
clean:
	rm -f $(OBJS) $(TARGET)
