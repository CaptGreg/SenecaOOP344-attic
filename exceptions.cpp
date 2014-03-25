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
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main (int argc, char**argv) {
  try
  {
    // GB START
    long long size = 1000 * 1000 * 1000;
    if(argc > 1) size *= atoi(*++argv);
    double *p = new double [size];
    delete [] p;
    // GB STOP

    throw myex;
  }
  catch (std::bad_alloc& ba){ // GB
    cerr << "bad_alloc caught: " << ba.what() << endl;
  }
  catch (exception& e)
  {
    cout << "standard exception " << e.what() << '\n';
  }
  catch (...)   // GB
  {
    cout << "caught ...\n";
  }
  return 0;
}
