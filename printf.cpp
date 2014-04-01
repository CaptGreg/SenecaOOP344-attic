#include <iostream>

extern "C" {
#include "myfunc.h"
};


int main(int argc, char **argv)
{
	std::cout << "Hi there\n";
	myFunc(1);
}

