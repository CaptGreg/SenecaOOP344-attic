#include <iostream>
#include <exception>
using namespace std;

uint64_t fibonacciRecursive(int n)
{
    return
        n >  1? fibonacciRecursive(n-2) + fibonacciRecursive(n-1):
        n == 1? 1:
        n == 0? 0:
                fibonacciRecursive(-n); // -ve arg
}
uint64_t fibonacciIterative(int n)
{
    uint64_t prev  = 0;
    uint64_t pprev = 1;
    uint64_t curr  = 0;

    for(int i = 1; i <=n; i++) {
        curr = pprev + prev;
        pprev = prev;
        prev = curr;
    }
    return curr;
}

int main (int argc, char**argv) {
  try
  {
    int n = 10;
    if(argc > 1) n = atoi(argv[1]);

    for(int i =0 ; i <= n; i++) {
        cout <<" fibonacci number (recursive) " <<i <<" is " <<fibonacciRecursive(i) << endl;
        cout <<" fibonacci number (iterative) " <<i <<" is " <<fibonacciIterative(i) << endl;
    }

  }
  catch (exception const& e)
  {
    cout << "standard exception " << e.what() << '\n';
  }
  return 0;
}
