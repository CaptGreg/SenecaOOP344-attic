#include <iostream>
using namespace std;

class A
{
    public:
      void display()
      {
          cout<<"Base class content.\n";
      }
};

class B : public A
{

};

class C : public B
{
 
};

int main()
{
    C c;
    c.display();
    return 0;
}
