// system details
// Wed Apr 16 20:55:43 EDT 2014

// uname -a
// Linux amd1100t 3.13.0-24-generic #46-Ubuntu SMP Thu Apr 10 19:11:08 UTC 2014 x86_64 x86_64 x86_64 GNU/Linux

// lsb_release -a
// No LSB modules are available.
// Distributor ID: Ubuntu
// Description:    Ubuntu 14.04 LTS
// Release:        14.04
// Codename:       trusty


// GB works with both compilers
// g++     -std=c++0x   c++threads.cpp -pthread -o c++threads && ./c++threads
// foo
// bar
// clang++ -std=c++11   c++threads.cpp -pthread -o c++threads && ./c++threads
// c++threads.cpp:14:1: warning: control reaches end of non-void function [-Wreturn-type]
// foo
// bar


#include <iostream>
#include <thread>
#include <exception>
using namespace std;

void foo() { cout <<"foo\n"; }
void bar() { cout <<"bar\n"; }

int main(int argc, char**argv)
{
    try {
        thread tFoo(foo);
        thread tBar(bar);

        tFoo.join();
        tBar.join();
    }
    catch(const exception& e) {
        cerr << "caught " << e.what() << endl;
    }

    return 0;
}
