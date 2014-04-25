#include <string>
#include <iostream>
#include <cstdlib>      // atof()
using namespace std;

int main(int argc, char**argv)
{
    string s ="12.34";
    cout << "string s=" << s << endl;

    double d = atof(s.c_str());
    cout << "double d=" << d << endl;
}

