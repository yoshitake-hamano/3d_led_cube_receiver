### Defines ####################################################################
UNAME := ${shell uname}
ifeq ($(ENABLE_REAL_3D_LED_CUBE), false)
else
ifeq ($(UNAME), Linux)
ENABLE_REAL_3D_LED_CUBE := true
CXXDEFS := -DENABLE_REAL_3D_LED_CUBE
endif
endif
$(info ENABLE_REAL_3D_LED_CUBE is $(ENABLE_REAL_3D_LED_CUBE))

CXX       := g++
CXXFLAGS  := -Wall -std=c++0x -v $(CXXDEFS)

TARGET    := receiver
PROJ_ROOT := $(realpath ..)
VPATH     := $(PROJ_ROOT)/receiver
INCLUDES  := `pkg-config opencv --cflags` \
	     -I $(PROJ_ROOT)/common
SRCS      := main.cpp
LIBS      := -lpthread \
	     -ldl \
	     `pkg-config opencv --libs` \
	     -lboost_serialization \
	     -lboost_system \
	     -lm
ifeq ($(ENABLE_REAL_3D_LED_CUBE), true)
SRCS := $(SRCS) spi.cpp
LIBS := $(LIBS) -lbcm2835
endif

OBJS      := $(SRCS:.cpp=.o)

### Rules ######################################################################

.PHONY: all
all: $(TARGET)
.PHONY: make
make: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -v -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) -f $(TARGET) *.o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $<
