#include <iostream>
using namespace std;

int setBit(int target, int bit)
{
  int mask = (1 << bit);
  return target | mask;
}

int main(int argc, char ** argv, char ** env)
{
  cout << "cout: argc = " << argc << endl;
  for(int row = 0; row < argc; row++)
     cout << "cout: argv[" << row << "] ==>" << argv[row] << "<==\n";

  for(int row = 0; env[row]; row++) {
     cout << "cout: env["<<row<<"]==>"<<env[row]<<"<==\n";
     
     char *p = env[row];
     int column = 0;
     while(*p) {
        cout <<  "[" << row << "][" << column <<"] = " << *p << endl;
        p++;
        column++;
     }
  }

  for( int bit = 0; bit < 8; bit++ ) {
    int target = 0;
    target = setBit(target, bit);
    cout << "bit = " <<bit <<", target=" << target <<endl;
  }
}
