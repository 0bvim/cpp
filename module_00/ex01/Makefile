
# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Source file
SRC = (addprefix src/, Contact.cpp PhoneBook.cpp)
# Output executable

OUT = call_me_baby

# Targets
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -Iinclude -o $(OUT) $(SRC)

# Clean
clean:
	rm -f $(OUT)
