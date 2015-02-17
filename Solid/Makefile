#
# Assume standlone toolchain
#
#CC  = arm-linux-gnueabihf-gcc
#CXX = arm-linux-gnueabihf-g++
#AR  = arm-linux-gnueabihf-ar

DIR=$(shell pwd)/../

INCLUDES = \
	-I$(DIR) \
	-I$(DIR)/hardware \
	-I$(DIR)/hardware/arduino \
	-I$(DIR)/hardware/arduino/cores \
	-I$(DIR)/hardware/arduino/cores/arduino \
	-I$(DIR)/hardware/arduino/variants \
	-I$(DIR)/hardware/arduino/variants/sunxi \
	-I$(DIR)/libraries \
	-I$(DIR)/Solid/inc

CFLAGS = -fPIC -DPCDUINO=1 -DARDUINO_LINUX=1
#CFLAGS = $(INCLUDES)
#CFLAGS += -march=armv7-a -mfpu=neon

SRCS = \
	src/LCD_driver.c \
	src/gpiofile.c \


#OBJS = $(SRCS:%.c=%.o)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRCS)))

%.o: %.cpp
	@rm -f $@ 
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@ -Wno-deprecated-declarations

%.o: %.c
	@rm -f $@ 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -Wno-deprecated-declarations

LIB_STATIC = bin/LCD_driver.a
LIB_SHARE = bin/LCD_driver.so
LIB = $(LIB_STATIC) $(LIB_SHARE)

all: $(LIB) 
	make -C sample/


$(LIB): $(OBJS)
	$(AR) cq $(LIB_STATIC) $(OBJS)
	$(CXX) -shared -Wl,-soname,$(LIB_SHARE) -o $(LIB_SHARE) $(OBJS)

clean:
	rm -f $(LIB_STATIC) $(LIB_SHARE) $(OBJS)


