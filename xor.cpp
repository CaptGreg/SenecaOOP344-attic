#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
    int a = 10;
    int b = 99;

    cout << "before three liner\n";
    cout << "a=" <<a << endl;
    cout << "b=" <<b << endl;

    a = a^b;
    b = a^b;
    a = a^b;

    cout << "after three liner\n";
    cout << "a=" <<a << endl;
    cout << "b=" <<b << endl;

    a^=(b^=(a^=b));
    cout << "after one liner\n";
    cout << "a=" <<a << endl;
    cout << "b=" <<b << endl;
}
