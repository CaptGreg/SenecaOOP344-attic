#include <iostream>
using namespace std;

class A {
public:
  int i;
  A() : i(10) { }
};

class B {
public:
  int j;
  B() : j(20) {
    cout << "Constructor B(), j = " << j << endl;
  }

  B(B& arg) : j(arg.j) {
    cout << "Copy constructor B(B&), j = " << j << endl;
  }

  B(const B&, int val = 30) : j(val) {
    cout << "Copy constructor B(const B&, int), j = " << j << endl;
  }
};

class C {
public:
  C() { }
  C(C&) { }
};

int main(int argc, char **argv) {
  A a;
  A a1(a);
  B b;
  const B b_const;
  B b1(b);
  B b2(b_const);
  const C c_const;
  // C c1(c_const);
}
