#include <cstring> // needed for strlen, strcpy

#include <iostream> // needed for cout
using namespace std; // needed to use cout + endl in stead of std::cout + std::endl

// #define nullptr ((char*) 0)   // old g++ compilers don't know about 'nullptr'

// Rule of three: If you define any one of 
// 1: destructor 
// 2: copy ctor
// 3: assignment operator
// then define all three.

class Book {

private:
  char *name;
  int  pages;
  char type;

public:

  Book() {
    cout << "class Book ctor without paramters" << endl;
    name = nullptr;
    pages = 0;
    type = ' ';
  } 

  Book(const char *_name, int _pages, char _type) {
    cout << "class Book ctor with paramters" << endl;
    if(_name) {
      name = new char[strlen(_name) + 1];
      strcpy(name, _name);
    } else {
      name = nullptr;
    }
    pages = _pages;
    type  = _type;
  } 
  
  ~Book() { 
    cout << "class Book dtor for this= " << this << endl;
    if(name) delete[] name; 
    name = nullptr;
  }
  
  Book( const Book& other) { // copy ctor  // Book b2 = b1;
    cout << "class Book copy ctor" << endl;
  
    if(other.name) {
      this->name = new char[strlen(other.name) + 1];
      strcpy(this->name, other.name);
    } else {
      this->name = nullptr;
    }
    this->pages = other.pages;
    this->type  = other.type;
  }
  
  Book & operator= ( const Book& other) { // assignent operator  // b3 = b2;
    cout << "class Book assignent operator\n"; 
    if(this != &other) { // ignore if called to assign 'ourself' to 'ourself'
      // example: want to avoid doing anything if called as in: Book b1; b1 = b1;
      if(this->name) {
        delete[] this->name; 
	this->name = nullptr; 
      }
  
      if(other.name) {
        this->name = new char[ strlen(other.name) + 1];
        strcpy(this->name, other.name);
      } else {
        this->name = nullptr;
      }
      this->pages = other.pages;
      this->type  = other.type;
    } else {
      cout << "assignment operator called with this == &other\n";
    }

    return *this;  // by convention, always return *this
  }
  void display()
  {
    if(name) {
      cout << "name = \"" << name << "\"" << endl;
    } else {
      cout << "(no name) " << endl;
    }
    cout << " pages = " << pages << endl;
    cout << " type = ==>" << type << "<==" << endl;
  }
}; //end class Book

int main (int argc, char **argv)
{
  cout << "\ncalling ctor Book b1\n";
  Book b1;

  cout << "\ncalling b1.display()\n";
  b1.display();

  cout << "\ncalling copy ctor Book b2 = b1\n";
  Book b2 = b1;  // call copy ctor

  cout << "\ncalling ctor Book b3\n";
  Book b3("OOP244 Introduction to Object orientated Programming Using C++ 11", 181, 'C');
  b3.display();

  cout << "\ncalling assignment operator b2 = b3;\n";
  b2 = b3;

  cout << "\ncalling assignment operator b3 = b3;\n";
  b3 = b3;

  cout << endl;
  cout << "b1= " << &b1 << endl;
  cout << "b2= " << &b2 << endl;
  cout << "b3= " << &b3 << endl;

  cout << "\nb1, b2, b3 going out of scope\n";
  return 0;
} // end main
