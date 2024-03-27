# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Source file
SRC = megaphone.cpp

# Output executable
OUT = megaphone

# Targets
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

# Clean
clean:
	rm -f $(OUT)
