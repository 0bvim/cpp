CXX := c++
CXXFLAGS := -std=c++98 -g3 -Wall -Wextra -Werror -Iinclude
CXXFLAGS_TEST := -g3 -Wall -Wextra -Werror -Iinclude -isystem $(GTEST_DIR)/include

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TESTS_DIR := tests
TEST_BUILD_DIR := $(TESTS_DIR)/build
TEST_BIN_DIR := $(TESTS_DIR)/bin

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
NAME := $(BIN_DIR)/megaphone

TEST_SRCS := $(wildcard $(TESTS_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TESTS_DIR)/%.cpp, $(TEST_BUILD_DIR)/%.o, $(TEST_SRCS))
TEST_TARGET := $(TEST_BIN_DIR)/tests

GTEST_DIR := /usr/src/gtest
GTEST_LIB := /usr/lib/libgtest.a /usr/lib/libgtest_main.a

.PHONY: all clean fclean re run tests run_tests

all: $(NAME)

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TEST_OBJS) $(TEST_BIN_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all
	@echo "Rebuilding..."

run: all
	@./$(NAME) $*

tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) | $(TEST_BIN_DIR)
	$(CXX) $(CXXFLAGS_TEST) -pthread -o $@ $(TEST_OBJS) $(GTEST_LIB)

$(TEST_BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp | $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS_TEST) -c -o $@ $<

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

run_tests: tests
	@./$(TEST_TARGET)
	@rm -rf $(TEST_BIN_DIR) $(TEST_BUILD_DIR)
