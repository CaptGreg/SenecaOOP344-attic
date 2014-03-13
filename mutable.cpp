#include <exception>
#include <iostream>
using namespace std;
// http://msdn.microsoft.com/en-us/library/4h2h0ktk%28v=vs.80%29.aspx
// mutable - This keyword can only be applied to non-static and non-const data members of a class. 
// If a data member is declared mutable, then it is legal to assign a value to this data member from a const member function.

// mutable member-variable-declaration;

// Remarks

// For example, the following code will compile without error because m_accessCount has been declared to be mutable, 
// and therefore can be modified by GetFlag even though GetFlag is a const member function.

// mutable.cpp
class XYZ
{
public:
   bool GetFlag() const // const so can't change anything
   {
      m_accessCount++;  // except for 'mutable' m_accessCount, 'mutable' overides 'const'
      return m_flag;
   }
private:
   bool m_flag;
   mutable int m_accessCount;
};


// http://stackoverflow.com/questions/105014/does-the-mutable-keyword-have-any-purpose-other-than-allowing-the-variable-to
int main1(int argc, char**argv)
{
  try {
    int x = 0;
    cout << x << endl;

    auto f1 = [=]() mutable {x = 42;};  // OK
    cout << x << endl;
    // f1 = 19;
    // cout << f1 << endl;

    // auto f2 = [=]()         {x = 42;};  // Error: a by-value capture cannot be modified in a non-mutable lambda
    // cout << x << endl;

  } catch (exception& e) {
    cout << "standard exception " << e.what() << '\n';
  }

}

// http://users.soe.ucsc.edu/~pohl/code/mut.htm
// In several of my books the mutable example uses a non-const member function incorrectly as was 
// pointed out by Paul Ezust (see for example C++ for C Programmers:3rd edition p156.) The indicated 
// change corrects the problem. The following code is a small variation on the book that incorporates 
// the correction.

#include <iostream>
#include <string>
using  namespace std;

class person {
public:
  person(const string n, int a, const unsigned long ss)
      :name(n), age(a), soc_sec(ss) {}

  void bday() const  {++age;}  //had been non-const

  void print() const
  { 
     cout << name << " is  " << age 
     << "  years old with SSN  " << soc_sec << endl;
  }
private:
  const string name;
  mutable int age;
  const unsigned long soc_sec;
};

int main2(int argc, char**argv)
{
   const person ira("Ira Pohl", 38, 1110111UL);
   ira.print();
   ira.bday();
   ira.print();

}

int main(int argc, char**argv)
{
  main1(argc, argv);
  main2(argc, argv);
}
