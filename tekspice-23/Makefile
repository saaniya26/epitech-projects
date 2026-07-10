# test_elementary_gates: tests/test_elementary_gates.cpp \
# 	src/components/elementary/and_component.cpp \
# 	src/components/elementary/or_component.cpp \
# 	src/components/elementary/xor_component.cpp \
# 	src/components/elementary/not_component.cpp \
# 	src/core/AComponent.cpp
# 	$(CXX) $(CXXFLAGS) $^ -o test_elementary_gates
NAME := nanotekspice

CXX := c++
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Iinclude -Isrc -Isrc/components/special -Isrc/components/elementary \
	-Isrc/components/gates -Isrc/components/advanced -Isrc/core

SRCS := $(shell find src -name "*.cpp")
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_input

re: fclean all

test_input: tests/test_input.cpp src/components/special/input_component.cpp src/core/AComponent.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_input

.PHONY: all clean fclean re test_input

SRC_TESTS = $(filter-out src/main.cpp, $(shell find src -name "*.cpp"))

TEST_FILE = tests/test_gates.cpp

TEST_FLAGS = -lcriterion --coverage

tests_run:
	$(CXX) $(CXXFLAGS) -o unit_tests $(SRC_TESTS) $(TEST_FILE) $(TEST_FLAGS)
	./unit_tests

clean_tests:
	rm -f unit_tests *.gcda *.gcno

.PHONY: tests_run clean_tests