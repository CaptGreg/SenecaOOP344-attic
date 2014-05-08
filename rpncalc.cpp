// for infix to postfix see
// https://www.youtube.com/watch?v=vq-nUF0G4fI

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  https://www.youtube.com/watch?v=zla7ha0OORM

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, stack<double>& caclStack);

int main(int ardc, char**argv)
{
    stack<double> calcStack;
    string input;

    cout <<"Welcome to RPN calculator\n";
    cout <<"q to quit\n";
    while(true)
    {
        // display prompt
        cout <<">>";

        // get input
        cin >> input;

        // check for numeric value
        double num;
        if(istringstream(input) >> num)
        {
            calcStack.push(num);
        }
        // check for operator
        else if(isOperator(input))
        {
            performOp(input, calcStack);
        }
        // check for quit
        else if(input == "q")
        {
            return 0;
        }
        // invalid output
        else 
        {
        cout << "Invalid input\n";
        }
    }
}
bool isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};

    for(int i=0; i < 4; i++)
    {
        if(input == ops[i])
            return true;
    }
    return false;
}

void performOp(const string& input, stack<double>& calcStack)
{
    double lVal, rVal, result;

    rVal = calcStack.top();
    calcStack.pop();

    lVal = calcStack.top();
    calcStack.pop();

    if(input == "-")
    {
        result = lVal - rVal;
    }
    else if(input == "+")
    {
        result = lVal + rVal;
    }
    else if(input == "*")
    {
        result = lVal * rVal;
    }
    else if(input == "/")
    {
        result = lVal / rVal;
    }
    cout << result << endl;

    calcStack.push(result);
}
