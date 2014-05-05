// http://www.cplusplus.com/doc/tutorial/exceptions/

// #include <exception> catches
// exception            description
// bad_alloc            thrown by new on allocation failure
// bad_cast             thrown by dynamic_cast when it fails in a dynamic cast
// bad_exception        thrown by certain dynamic exception specifiers
// bad_typeid           thrown by typeid
// bad_function_call    thrown by empty function objects
// bad_weak_ptr	        thrown by shared_ptr when passed a bad weak_ptr
// logic_error          error related to the internal logic of the program
// runtime_error        error detected during runtime

// using standard exceptions
#include <iostream>
#include <exception>
#include <math.h>
using namespace std;

class myexception: public exception
{
  public:
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main (int argc, char**argv) 
{
  try {
    throw "what happened?";
  } catch(const char* msg) {
    cerr << "const char* exception caught: " << msg <<  endl;
  }

  try {
    throw myex;
  } catch(myexception& e) {
    cerr << "myexception& caught: " << e.what() << endl;
  }

  try {
    long long size = 1000 * 1000 * 1000;
    if(argc > 1) size *= atoi( *(argv+1) );
    double *p = new double [size];
    delete [] p;
  } catch (exception& e) {
    cout << "standard exceptio " << e.what() << '\n';
  }

  try {
    asin(2.0);  // arcsine range error
  } catch (exception& e) {
    cout << "asin(2.0) standard exception& " << e.what() << '\n';
  }

  return 0;
}
