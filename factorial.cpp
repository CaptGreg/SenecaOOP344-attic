#include <iostream>
#include <exception>
using namespace std;

int factorial(int n)
{
    return n > 1? n*factorial(n-1): 1;
}

int main (int argc, char**argv) {
  try
  {
    int n = 10;
    if(argc > 1) n = atoi(argv[1]);

    cout << n <<"!=" <<factorial(n) << endl;

  }
  catch (exception const& e)
  {
    cout << "standard exception " << e.what() << '\n';
  }
  return 0;
}
