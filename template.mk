
ifndef TARGET
	TARGET = a.out
endif
ifndef	SRCS
	SRCS =
endif
.SUFFIXES: .cpp .o .hpp .h .tpp
.PHONY: all clean cleanobj cleanbin re

CXX = c++

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

LDFLAGS = $(addprefix -fsanitize=, address undefined)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(TARGET)
clean : cleanobj cleanbin
cleanobj :
	rm -rf $(OBJS_DIR)
cleanbin :
	rm -rf $(TARGET)
re : clean; make all

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS): |$(OBJS_DIR)

$(addprefix $(OBJS_DIR), %.o): %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)