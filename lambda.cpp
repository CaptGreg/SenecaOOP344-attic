#include <exception>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

using namespace std;

// http://www.cprogramming.com/c++11/c++11-lambda-closures.html

// One of the most exciting features of C++11 is ability to create lambda functions 
// (sometimes referred to as closures). What does this mean? A lambda function is a 
// function that you can write inline in your source code (usually to pass in to another 
// function, similar to the idea of a functor or function pointer). With lambda, creating 
// quick functions has become much easier, and this means that not only can you start 
// using lambda when you'd previously have needed to write a separate named function, 
// but you can start writing more code that relies on the ability to create quick-and-easy 
// functions. In this article, I'll first explain why lambda is great--with some 
// examples--and then I'll walk through all of the details of what you can do with lambda.

// Why Lambdas Rock

// Imagine that you had an address book class, and you want to be able to provide a search 
// function. You might provide a simple search function, taking a string and returning all 
// addresses that match the string. Sometimes that's what users of the class will want. But 
// what if they want to search only in the domain name or, more likely, only in the username 
// and ignore results in the domain name? Or maybe they want to search for all email addresses 
// that also show up in another list. There are a lot of potentially interesting things to 
// search for. Instead of building all of these options into the class, wouldn't it be nice 
// to provide a generic "find" method that takes a procedure for deciding if an email address 
// is interesting? Let's call the method findMatchingAddresses, and have it take a "function" 
// or "function-like" object.

class Foo
{
public:
    Foo () : _x( 3 ) {}
    void func ()
    {
        // a very silly, but illustrative way of printing out the value of _x
        [this] () { cout << _x; } ();
    }

private:
        int _x;
};

int main1()
{
    Foo f;
    f.func(); // prints 3
    cout << endl;
    return 0;
}

int main2()
{

    [] { cout << "Hi there, my friends\n"; }(); // prints as expected

    auto i = [] () { return 42; }; // compiler knows this returns an integer
    cout << i << "\n";  // prints 1 --- ???

    auto j = []    { return 43; }; // compiler knows this returns an integer
    cout << j << "\n";  // prints 1 --- ???

    auto k = []    { return 44; }; // compiler knows this returns an integer
    cout << k << "\n";  // prints 1 --- ???

    auto l = [] () -> int { return 45; }; // now we're telling the compiler what we want
    // l++; // error: no ‘operator++(int)’ declared for postfix ‘++’ 
    cout << l << "\n";  // prints 1 --- ???

    // replace
    vector<int> v1;
    v1.push_back( 10 );
    v1.push_back( 20 );
    //...
    for ( auto itr = v1.begin(), end = v1.end(); itr != end; itr++ )
    {
        cout << *itr << endl;
    }

    // with
    vector<int> v2;
    v2.push_back( 30 );
    v2.push_back( 40 );
    //...
    for_each( v2.begin(), v2.end(), [] (int val) { cout << val << endl; } );

    return 0;
}
// A Note About Function Pointers

// Under the final C++11 spec, if you have a lambda with an empty capture specification, 
// then it can be treated like a regular function and assigned to a function pointer. 
// Here's an example of using a function pointer with a capture-less lambda:

typedef int (*func)();
func f = [] () -> int { return 2; };
int main3()
{
  f();
  return 0;
}

// This works because a lambda that doesn't have a capture group doesn't need its own class--it 
// can be compiled to a regular old function, allowing it to be passed around just like a normal 
// function. Unfortunately, support for this feature is not included in MSVC 10, as it was added 
// to the standard too late.
// Making Delegates with Lambdas

// Let's look at one more example of a lambda function--this time to create a delegate. What's a 
// delgate, you ask? When you call a normal function, all you need is the function itself. When you 
// call a method on an object, you need two things: the function and the object itself. It's the 
// difference between func() and obj.method(). To call a method, you need both. Just passing in the 
// address of the method into a function isn't enough; you need to have an object to call the method on.

// Let's look at an example, starting with some code that again expects a function as an argument, 
// into which we'll pass a delegate.

#include <functional>
#include <string>

class EmailProcessor
{
public:
    void receiveMessage (const std::string& message)
    {
        if ( _handler_func ) 
        {
            _handler_func( message );
        }
        // other processing
    }
    void setHandlerFunc (std::function<void (const std::string&)> handler_func)
    {
        _handler_func = handler_func;
    }

private:
        std::function<void (const std::string&)> _handler_func;
};

// This is a pretty standard pattern of allowing a callback function to be registered with a class 
// when something interesting happens.

// But now let's say we want another class that is responsible for keeping track of the longest message 
// received so far (why do you want to do this? Maybe you are a bored sysadmin). Anyway, we might create 
// a little class for this:

#include <string>

class MessageSizeStore
{
public:
    MessageSizeStore () : _max_size( 0 ) {}
    void checkMessage (const std::string& message ) 
    {
        const int size = message.length();
        if ( size > _max_size )
        {
            _max_size = size;
        }
    }
    int getSize ()
    {
        return _max_size;
    }

private:
    int _max_size;
};

int main4()
{
// What if we want to have the method checkMessage called whenever a message arrives? We can't just pass 
// in checkMessage itself--it's a method, so it needs an object.

// EmailProcessor processor;
// MessageSizeStore size_store;
// processor.setHandlerFunc( checkMessage ); // this won't work

// We need some way of binding the variable size_store into the function passed to setHandlerFunc. Hmm, 
// sounds like a job for lambda!

    EmailProcessor processor;

    MessageSizeStore size_store;

    processor.setHandlerFunc( 
        [&] (const std::string& message) { size_store.checkMessage( message ); } 
);

// Isn't that cool? We are using the lambda function here as glue code, allowing us to pass a regular function 
// into setHandlerFunc, while still making a call onto a method--creating a simple delegate in C++.

  return 0;
}


int main(int argc, char**argv)
{
  int ret = -1;

  try {
    main1();
    main2();
    main3();
    main4();
    ret =  0;
  } catch (exception& e) {
    cout << "standard exception " << e.what() << '\n';
  }

  return ret;
}
