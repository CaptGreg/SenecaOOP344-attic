#include <iostream>
using namespace std;

#include <typeinfo>

int main()
  {
     int i;
     unsigned u;
     short s;
     long l;
     long long ll;
     float f;
     double d;
     long double ld;
     char *c;

     cout << "The type of a is: " << typeid(i).name() << endl;
     cout << "The type of u is: " << typeid(u).name() << endl;
     cout << "The type of s is: " << typeid(s).name() << endl;
     cout << "The type of l is: " << typeid(l).name() << endl;
     cout << "The type of ll is: " << typeid(ll).name() << endl;
     cout << "The type of f is: " << typeid(f).name() << endl;
     cout << "The type of d is: " << typeid(d).name() << endl;
     cout << "The type of ld is: " << typeid(ld).name() << endl;
     cout << "The type of c is: " << typeid(c).name() << endl;
     return 0;
  }

