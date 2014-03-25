#include <iostream>

#include "cfun.h"

int main(int argc, char**argv)
{
    std::cout << "cpp code calling c-code\n";

    cfun();

    std::cout << "c-code returned\n";
}
