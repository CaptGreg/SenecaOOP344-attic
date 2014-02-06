// http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm

#include <iostream>
using namespace std;
 
class printData 
{
   public:
      void print(short s) {
        cout << "Printing short: " << s << endl;
      }
 
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(float  f) {
        cout << "Printing float: " << f << endl;
      }
 
      void print(double  d) {
        cout << "Printing double: " << d << endl;
      }
 
      void print(char* c) {
        cout << "Printing character string: ==>" << c << "<==" << endl;
      }
};
 
int main(void)
{
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   // Call print to print short
   pd.print((short) 12345);
   // Call print to print double
   pd.print(500.263);
   // Call print to print float
   pd.print(600.374f);
   // Call print to print character string
   pd.print((char*) "Hello C++");
 
   return 0;
}
