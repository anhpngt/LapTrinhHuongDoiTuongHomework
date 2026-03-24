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
	@echo "  make baiN     - compile and run baiN.cpp"
	@echo "  make clean    - remove all compiled binaries"
	@echo ""
	@echo "Examples:"
	@echo "  make bai1"
	@echo "  make bai2"
