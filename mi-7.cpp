#include <iostream>
using namespace std;


class base1
{
  public:
     void some_function1( )
     { cout << "base1 some_function1\n";  }  
};

class base2
{
  public:
    void some_function2( )
     { cout << "base2 some_function2\n";  }  
};

class derived : public base1, public base2
{
    
};

int main()
{
    derived obj;
    
//  Error because compiler can't figure out which function to call either same_function( ) of base1 or base2 
    // obj.some_function( )  

    obj.some_function1( );  /* Function of class base1 is called. */
    obj.some_function2( );  /* Function of class base2 is called. */
}

