# pm = poly-morphism
# mi = mulitple-inheritence

ALL = \
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
	type-id \
	clocks \
	myPrintf \
	exceptions \
	initialize \
	mutable \
	lambda \
	OOP344_20141_T1_V1 \
	ll2 \
	q \
	q2 \
	str-namespace \
	cppcallc \
	getopt \
	getsubopt \
	ll \

CXX = g++-4.8
ARCH     = -m32
CXXFLAGS = $(ARCH) -Wall -ggdb -std=c++0x
CXXFLAGS = -Wall -ggdb -std=c++0x

all : $(ALL)

# "clocks" need to link with -lrt to use the time functions
# need to link time with -lrt
clocks: clocks.cpp
	g++ clocks.cpp -o clocks -lrt

cppcallc  : cppcallc.cpp cfun.h cfun.c
	g++ -c cppcallc.cpp
	gcc -c cfun.c
	g++ cppcallc.o cfun.o -o cppcallc

clean:
	rm $(ALL) *.o
