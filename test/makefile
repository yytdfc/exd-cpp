SRCS=$(wildcard ./*.cc)
EXES=$(SRCS:.cc=)
CXX = g++
CXX_FLAG = -std=c++11 -I../include
LD_FLAGS = 

.PHONY: all clean

all: $(EXES)

%: %.cc
	$(CXX) $(CXX_FLAG) $< $(LD_FLAGS) -o $@
	chmod +x $@
	./$@

clean:
	-rm -rf $(EXES)



