// #define PROBLEM
#define FIX

#ifdef PROBLEM
#include <iostream>
using namespace std;

class Base {
    protected:
        int iData;
    public:
        Base() { iData = 10; }
};

class Derived1 : public Base { };
class Derived2 : public Base { };

class Derived3 : public Derived1, public Derived2 {
    public: 
        int GetData() { return iData; } 
};

int main (int argc, char**argv)
{ 
    Derived3 obj;
    cout << obj.GetData() << endl;
}
#endif


#ifdef FIX
// EXAMPLE: Demonstrate the usage of virtual base class in the Diamond problem to fix the compilation error

#include <iostream> 
using namespace std; 

class Base { 
    protected: 
        int iData; 
    public:
        Base() { iData = 10; }
};

class Derived1 : virtual public Base { };
class Derived2 : virtual public Base { }; 

class Derived3 : public Derived1, public Derived2 {
    public:
      int GetData() { return iData; } 
};

int main (int argc, char**argv)
{
    Derived3 obj;
    cout << obj.GetData() << endl;
}
#endif
