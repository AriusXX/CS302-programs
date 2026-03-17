CXX = g++
CXXFLAGS = -std=c++14 -Wall -g  

TARGET = shamrock_race
SRC = main_shamrock.cpp datastructure.cpp shamrock.cpp  
OBJ = $(SRC:.cpp=.o)

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule (DO NOT DELETE .cpp FILES, ONLY OBJECTS & EXECUTABLE)
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean
