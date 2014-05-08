// for infix to postfix see
// https://www.youtube.com/watch?v=vq-nUF0G4fI
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// http://www.math.bas.bg/bantchev/place/rpn/rpn.c%2B%2B.html
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// RPN Calculator Specification
// 
// The following text provides a sufficiently detailed specification of the problem chosen to illustrate a considerable portion of the programming languages presented on this site. The specification is needed to ensure a common basis for doing implementations with the same functionality.
// 
// Within the restrictions imposed by the specification, there is a number of possible algorithmic options – of which some are depending on the language – that can be taken in a particular implementation. For an account of these, and to read and examine the implementations themselves follow the corresponding links at the top of the page.
// 
// For a general discussion on why this problem was chosen see the rationale section.
// 
// ————————
// 
// An RPN calculator program computes expressions written in RPN (Reverse Polish Notation).
// 
// An RPN expression (or a postfix expression) is one of the following:
// 
    // a number X, in which case the value of the expression is that of X;
    // a sequence of the form E1 E2 O, where E1 and E2 are postfix expressions and O is an arithmetic operation; in this case, the value of the expression is that of  E1 O E2.
// 
// Note that an RPN expression neither contains parentheses nor involves rules of precedence and associativiy among the operations. Note also that the hierarchy of computation within the expression (and thus its value) is unambiguously determined by the above definition.
// 
// The following are RPN expressions:
   // -52.980765
   // 3 5 /
   // 3 +5 8 * -7 + *
// 
// The value of the last of the above expressions is  3*(((+5)*8)+(-7)) = 99.
// 
// 
// An RPN calculator program reads lines of text from the standard input. If a line is not empty, the program responds with printing one line on the standard output as follows, before it reads the next line or stops:
// 
    // if the input line contains a valid RPN expression, the program outputs the value of that expression;
    // otherwise, an error message is output.
// 
// Empty input lines (including those containing only blanks) are accepted with no response.
// 
// The program stops when end-of-input (‘end-of-file’) is encountered.

// In the above definition of RPN expression, I have deliberately chosen to consider only dyadic operations. I will furthermore assume that an RPN calculator program only accepts + (addition), - (subtraction), * (multiplication), and / (division) as operators, and that for an expression to be considered valid there must be at least one blank character between each two tokens. Leading and trailing blanks are admissible in an expression, as well as more than one such character between tokens.
// 
// If possible within the programming language used, the program must exhibit no explicit limitations, such as placing a restriction on the length of the lines that can be read, or on the size of the expressions (measured as number of tokens) that can be handled. This means, for example, that if the implementation uses a stack or some other data container to hold intermediate values in the process of evaluating an expression, that container must not be (explicitly) limited in size, because for arbitrarily long expressions a container of arbitrary capacity may be needed.
// 
// The format of the numbers accepted should include reasonable representations of whole and fractional (with a decimal dot) numbers. E.g., if a decimal dot is present, it can occupy a leading or trailing position, and a number can have arithmetic sign, such as in 271., -0, or +.0. Exponential notation is admissible but not required to handle. (Some programming languages only permit restricted forms of representing numbers, so reading numbers according to a language's specific rules does not necessarily lead to a calculator that conforms to our specificaion.)
// 
// 
// The above specification of an RPN calculator program intentionally leaves out some possibilities, such as letting an expression be written across several lines of input, or introducing commands for manipulating (the values of) parts of the expression etc. – say, in the style of the traditional dc utility in Unix. These would have probably complicated the specification of the calculator, as well as the program implementations, without really making the problem more challenging, or the implementations more worth doing, in any interesting way.
// Historical Notes and Links
// 
// Although not directly related to writing an RPN calculator program, the following notes and links may be of interest.
// 
// The so called Polish notation was introduced in 1920 by the Polish logician Jan Łukasiewicz. It allowed expressions to be written unambiguously without the use of parentheses. The Reverse Polish Notation improves on this idea by enabling automatic computation of such expressions to avoid explicit addressing: thus the now ubiquitous stack (LIFO) data structure was born. RPN and the stack-based (zero-address) computations were invented in the mid 1950s by the Germans F.L. Bauer and K. Samelson, and independently by the Australian Charles Hamblin.
// 
// There exists a widely-known elegant algorithm for converting infix expressions to RPN: see e.g. here. Interestingly, the algorithm itself is also stack-based, only it is the expression's operators, not operands, that are stored in the stack.
// 
// The Hewlett-Packard company has been producing RPN pocket and desk calculators, including programmable ones, since 1968. (See also here.)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// RPN Calculator in C++
// 
// As C++ is an extension to C, when we consider an implementation in this language, it is natural to be interested in how we can do better than in plain C. As it turns out, the main advantage of C++ over C in solving our problem is reading and tokenizing the input. C++'s standard library is particularly convenient in this respect.
// 
// In the main function, the outer loop calls getline on cin to read lines into the variable s. The return value of getline is used to determine when the loop and the program are to be terminated due to exhausting the input. cin is a library-provided stream object associated with the standard input, and s is of class string. In contrast to the C implementation, lines of arbitrary length are read by a single function call, and the buffer needed to accomodate the data is automatically and transparently allocated.
// 
// For tokenizing the input, we create a ‘string stream’ sstr on s, so as, in the inner loop, individual tokens are extracted using the standard input operator >>. All tokens go into the stack tks, from where, unless the input line contained no tokens at all, they are passed to evalrpn, which evaluates the RPN expression by recursively working downwards on tks.
// 
// Within evalrpn, a token tk is popped off tks and checked for being an operator or a number. If an operator, we are also interested in whether tks contains the respective operands, pull them off the stack, and perform the corresponding arithmetical operation. If tk is not an operator, stod is used to read it as a number. In any case, the result goes into x, and is eventually returned as the value of evalrpn.
// 
// Syntax errors are signalled by throwing exceptions. For convenience, the test for an erroneous situation and the throwing itself are packed in a macro definition. As we do not want to differentiate between the various reasons that may cause a syntax error, what exactly value is being thrown is irrelevant. The call of evalrpn in main is nested in a try block. A throw occurs either directly in that block or within evalrpn, so all throws are handled by the single catch statement following the try block. An implicit throw takes place within stod whenever it fails to read tk as a number. The ellipsis in the handler stands for a ‘don't care’ parameter, meaning that it can accept any possible value thrown but is not actually using it.
// 
// For comparison, the C implementation handles errors by the setjmp/longjmp mechanism, which is less convenient to write or read, but also significantly less time-consuming than the throw/catch exception handling mechanism of C++ (although the latter does not matter here).
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

#define ASSERT(b)  if (!(b)) throw ""

double evalrpn(stack<string> & tks)  {
  ASSERT(!tks.empty());
  double x,y;
  auto tk = tks.top();  tks.pop();
  auto n = tk.size();
  if (n==1 && string("+-*/").find(tk)!=string::npos)  {
    y = evalrpn(tks);
    x = evalrpn(tks);
    if      (tk[0]=='+')  x += y;
    else if (tk[0]=='-')  x -= y;
    else if (tk[0]=='*')  x *= y;
    else                  x /= y;
  }  else  {
    unsigned i;  x = stod(tk,&i);  ASSERT(i==n);
  }
  return x;
}

int main()  {
  string s;
  while (getline(cin,s))  {
    stack<string> tks;
    istringstream sstr(s);
    string tk;
    while (sstr >> tk)  tks.push(tk);
    if (!tks.empty())
      try  {
        auto z = evalrpn(tks);
        ASSERT(tks.empty());
        cout << z << endl;
      }  
      catch (const char*e)  {cout << "error:" <<e <<"\n";}
      catch (...)  {cout << "error\n";}
  }
  return 0;
}
