# pm = poly-morphism
# mi = mulitple-inheritence

ARCH     = -m32

CXX = clang++
CC  = clang
CXXFLAGS = $(ARCH) -Wall -ggdb -std=c++11 -pthread
CXX = g++
CC  = gcc
CXXFLAGS = $(ARCH) -Wall -ggdb -std=c++0x -pthread
CXX = g++-4.8
CC  = gcc-4.8
CXXFLAGS = $(ARCH) -Wall -ggdb -std=c++11 -pthread


ERRORS = \
	ll-dbl \


ALL = \
	args \
	assignment-op \
	bintree \
	bits \
	cirq \
	clocks \
	cmdline \
	copy-ctor \
	copyswap \
	cppcallc \
	cppthreads \
	c_str \
	data \
	derived-class \
	exceptions \
	expression-templates \
	file-in-out \
	files \
	GB-templates \
	getopt \
	getsubopt \
	inheritance \
	initialize \
	iter-diy \
	lambda \
	ll \
	ll2 \
	ll2-problem \
	ll-xor \
	max-template \
	mi-1 \
	mi-2 \
	mi-3 \
	mi-4 \
	mi-5 \
	mi-6 \
	mi-7 \
	mi-diamond \
	mutable \
	myPrintf \
	OOP344_20141_T1_V1 \
	overload \
	overload-op \
	parser \
	pm-1 \
	pm-2 \
	pm-3 \
	pm-4 \
	q \
	q2 \
	rpncalc \
	rpncalc2 \
	stack-template \
	stl-algo \
	stl-iterator \
	stl-iterator2 \
	stl-iterator3 \
	stl-vector \
	string \
	str-namespace \
	strtok \
	swap-xor \
	type-id \
	xor \

all : $(ALL)

# "clocks" need to link with -lrt to use the time functions
# need to link time with -lrt
clocks: clocks.cpp
	$(CXX) clocks.cpp -o clocks -lrt

cppcallc  : cppcallc.cpp cfun.h cfun.c
	$(CXX) -c cppcallc.cpp
	$(CC) -c cfun.c
	$(CXX) cppcallc.o cfun.o -o cppcallc

cppthreads : cppthreads.cpp Makefile
	$(CXX) $(CXXFLAGS) -pthread   cppthreads.cpp -o cppthreads


clean:
	rm $(ALL) *.o
