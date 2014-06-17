#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Calc {
private:
  stack<double> s;

  void op(string& opCode)
  {
    if(s.size() >= 2) {
      double a = s.top(); s.pop();
      double b = s.top(); s.pop();
      double result;
           if(opCode == "+") result = a + b;
      else if(opCode == "-") result = a - b;
      else if(opCode == "*") result = a * b;
      else if(opCode == "/") result = a / b;
      else {
        cout << "unknown operator " << opCode.c_str() << endl;
        return;
      }
      cout << result << endl;
      s.push(result);
    } else
      cout << "need two numbers\n";
  }
public:
  void calc() {
    string input;
    cout << "q to quit\n";

    while(true) {
      cout << "input>";
      cin >> input;

      if(input == "q")
        break;

      double d;
      if(istringstream(input) >> d)  // use stringstream to convert string to number
        s.push(d);
      else if(input == "+") op(input);
      else if(input == "-") op(input);
      else if(input == "*") op(input);
      else if(input == "/") op(input);
      else cout << input << "<== not understood\n";
    }
  }
  
  void print()
  {
    // no iterators with stack.

    // for(stack<double>::iterator it = s.begin(); it ; it != s.end())
      // cout << *it << endl;

    // for(auto d : s)
      // cout << d << endl;
  }
};

int main(int argc, char **argv)
{
  try {
    Calc c;
    c.calc();
  } catch(const char* err) {
    cout << "caught a char* err=" << err << endl;
  }
}
