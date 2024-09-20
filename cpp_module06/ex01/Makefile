CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS =

SRCS_DIR = srcs
OBJS_DIR = objs
HDRS_DIR = .hpp

TARGET = serializer

SRCS = $(wildcard $(SRCS_DIR)/*.cpp)

OBJS = $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

HDRS = $(wildcard $(HDRS_DIR)/*.h)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HDRS)
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all