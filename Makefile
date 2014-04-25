# pm = poly-morphism
# mi = mulitple-inheritence

ARCH     = -m32
CXXFLAGS = $(ARCH) -Wall -ggdb -std=c++11 -pthread

CXX = clang++
CC  = clang
CXX = g++-4.8
CC  = gcc-4.8
CXX = g++
CC  = gcc


ERRORS = \
	ll-dbl \
	stl-iterators \


ALL = \
	args \
	assignment-op \
	copy-ctor \
	data \
	derived-class \
	files \
	GB-templates \
	inheritance \
	max-template \
	mi-1 \
	mi-2 \
	mi-3 \
	mi-4 \
	mi-5 \
	mi-6 \
	mi-7 \
	mi-diamond \
	overload \
	overload-op \
	pm-1 \
	pm-2 \
	pm-3 \
	pm-4 \
	stack-template \
	string \
	stl-algo \
	stl-vector \
	strtok \
	swap-xor \
	type-id \
	clocks \
	myPrintf \
	exceptions \
	initialize \
	mutable \
	lambda \
	OOP344_20141_T1_V1 \
	ll \
	ll2 \
	ll2-problem \
	q \
	q2 \
	str-namespace \
	cppcallc \
	getopt \
	getsubopt \
	ll-xor \
	bintree \
	c_str \
	cirq \
	copyswap \
	iter-diy \
	xor \
	cppthreads \

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
