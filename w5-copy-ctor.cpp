#include <iostream>
using namespace std;

#include <cstring>

// #define nullptr ((char*) 0)   // old g++ compilers don't know about 'nullptr'

// Rule of three: If you define any one of 
// 1: destructor 
// 2: copy ctor
// 3: assignment operator
// then define all three.

class Employee {
private:
  int   eNo;
  char *ePName;

public:

  Employee() { // Employee e3; 
    cout<<"shallow ctor\n";
    ePName = nullptr; 
    eNo = -1; 
  }  // ctor - shallow, no 'deep stuff'
  
  Employee(int no, char *name) {  // ctor - handles 'deep stuff'  Employee e1(123, "Mr. 123");
    cout << "deep ctor\n";
    eNo = no;
    ePName = new char [ strlen(name) + 1]; // add 'deep stuff'
    strcpy(ePName, name);
  }

  ~Employee() { if(ePName) delete [] ePName; }
  
  Employee( Employee& e) { // copy ctor  // Employee e2 = e1;
    // 'this' is the new instance of the class that were are making
    // 'e' is the instance of the old class
    cout << "copy ctor: e.ePName = " << e.ePName << endl;
  
    this->ePName = new char [ strlen(e.ePName) + 1]; 
    strcpy(this->ePName, e.ePName);
    this->eNo = e.eNo;
  }
  
  Employee & operator= ( const Employee& other) { // assignent operator  // e3 = e2;
    cout << "assignent operator\n"; 
    if(this != &other) { // ignore if called to assign 'ourself' to 'ourself'
      // example: want to avoid doing anything if called as in: Employee e1; e1 = e1;
  
      char * newMem = nullptr;
      if(other.ePName) {
        // strategy: 1. get new mem, 2. delete old, 3. assign new to old.
        newMem = new char [ strlen(other.ePName) + 1]; 
        if(newMem) {
          strcpy(newMem, other.ePName);
        }

        if(this->ePName) { // if there is 'deep stuff', delete it.
          delete [] this->ePName;
        }
      }
  
      this->ePName = newMem;
      this->eNo = other.eNo;
    }
    return *this;  // by convention, always return *this
  }

  void print(){ cout << "emp no=" << eNo << " ePName = " << (ePName? ePName: "not assigned") << endl; }

}; //end class Employee

int main (int argc, char **argv)
{
  Employee e1(123, (char*) "Mr 123");
  e1.print();

  cout << "\ncalling copy ctor to make e2\n";
  Employee e2 = e1;  // call copy ctor
  e2.print();


  cout << "\ncreating e3 without any name or employee number\n";
  Employee e3;
  e3.print();

  cout << "\ncalling assignment operator '=' to copy e2 to e3\n";
  e3 = e2;
  e3.print();

  return 0;
} // end main
