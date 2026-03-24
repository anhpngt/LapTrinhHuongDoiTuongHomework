# Compiler and flags
CXX = g++ # use g++ to compile C++
CXXFLAGS = -Wall -std=c++17

.PHONY: 1
1:
	$(CXX) $(CXXFLAGS) 1.cpp -o bai1
	./bai1

# Remove all compiled binaries
clean:
	rm -f bai[0-9]*

help:
	@echo "Usage:"
	@echo "  make baiN     - compile and run baiN.cpp"
	@echo "  make clean    - remove all compiled binaries"
	@echo ""
	@echo "Examples:"
	@echo "  make bai1"
	@echo "  make bai2"
