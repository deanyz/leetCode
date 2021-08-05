CXX = g++
CPPFLAGS = -g -std=c++11 -Wall

SRCS=$(wildcard ./*.cpp)
TARGETS=$(patsubst %.cpp, out/%, $(SRCS))

#TARGETS = 15.3-sum \
# test_utl

.PHONY: all
all: $(TARGETS) 
	# echo "$(TARGETS)"
	
out/%:%.cpp 
	# $(CXX) $(CPPFLAGS) $< -o $@
	$(CXX) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(TARGETS)
