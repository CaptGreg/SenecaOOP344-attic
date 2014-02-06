#include <iostream>
using namespace std;

class Base {
public:
  char* name;
  void display() {
    cout << name << endl;
  }
};

class Derived: public Base {
public:
  char* name;
  void display() {
    cout << name << ", " << Base::name << endl;
   }
};

int main() {
  Derived d;
  d.name       = (char *) "Derived Class";
  d.Base::name = (char *) "Base Class";

  // call Derived::display()
  d.display();

  // call Base::display()
  d.Base::display();
}
