#include <iostream>
using namespace std;

class A {
public:
  A() {}
  A& operator=(const A&) {
    cout << "A::operator=(const A&)" << endl;
    return *this;
  }

  A& operator=(A&) {
    cout << "A::operator=(A&)" << endl;
    return *this;
  }
};

class B {
public:
  B() {}
private:
  A a;
};

class C {
public:
  C() {}
  C& operator=(const C&) {
    cout << "C::operator=(const C&)" << endl;
    return *this;
  }
  C& operator=(C&) {
    cout << "C::operator=(C&)" << endl;
    return *this;
  }
};

int main() {
  A a1;
  A a2;
  cout << "our class 'a' assignment operator\n";
  a1 = a2;

  B b1;
  B b2;
  cout << "compiler generated assignment operator for class 'b' which in turn calls our class 'a' assignment operator\n";
  b1 = b2;

  C c1;
  C c2;
  const C c3;
  c1 = c2;
  c1 = c3;
}

