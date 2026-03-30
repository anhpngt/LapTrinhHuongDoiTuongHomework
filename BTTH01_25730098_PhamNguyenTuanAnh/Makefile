# Compiler and flags
CXX = g++ # use g++ to compile C++
CXXFLAGS = -Wall -std=c++17

NUMS := 1 2 3 4 5 6 7 8
.PHONY: $(NUMS)
$(NUMS):
	$(CXX) $(CXXFLAGS) $@.cpp -o $@
	./$@

# Remove all compiled binaries
clean:
	rm -f [0-9]

help:
	@echo "Usage:"
	@echo "  make N        - compile and run N.cpp (N = 1..8)"
	@echo "  make clean    - remove all compiled binaries"
	@echo ""
	@echo "Example:"
	@echo "  make 1"
