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

CXXFLAGS = -m32

all : $(ALL)

# need to line time with -lrt
clocks: clocks.cpp
	g++ clocks.cpp -o clocks -lrt

clean:
	rm $(ALL)
