// http://www.catonmat.net/blog/cpp-polymorphism/

// The Four Polymorphisms in C++

// When people talk about polymorphism in C++ they usually mean the thing of using a derived class through the base class pointer or reference, which is called subtype polymorphism. But they often forget that there are all kinds of other polymorphisms in C++, such as parametric polymorphism, ad-hoc polymorphism and coercion polymorphism.

// These polymorphisms also go by different names in C++,
// 
    // Subtype polymorphism is also known as runtime polymorphism.
    // Parametric polymorphism is also known as compile-time polymorphism.
    // Ad-hoc polymorphism is also known as overloading.
    // Coercion is also known as (implicit or explicit) casting.

// In this article I'll illustrate all the polymorphisms through examples in C++ language and also give insight on why they have various other names.
// Subtype Polymorphism (Runtime Polymorphism)

// Subtype polymorphism is what everyone understands when they say "polymorphism" in C++. It's the ability to use derived classes through base class pointers and references.

// Here is an example. Suppose you have various cats like these felines,

// Polymorphic Cats
// Polymorphic cats on a mat by James Halliday.

// Since they are all of CatFamilyae biological family, and they all should be able to meow, they can be represented as classes inheriting from CatFamily base class and overriding the meow pure virtual function,

#include <iostream>
// #include "cats.h"
// file cats.h

class Leg {
	double legLength;
	double longestClawLength;
	struct colour_t { double red; double green; double blue; } hairColour;
};

class CatFamily {
private:
	
	Leg *legTable;
public:
	CatFamily() { legTable = new Leg[4]; } // cats have 4 legs.
	~CatFamily() {delete [] legTable; }

#ifdef VIRTUAL
 	virtual void meow() { std::cout << "who called the base class?\n"; }
#else
 	void meow() { std::cout << "who called the base class?\n"; }
#endif

};

class Cat : public CatFamily {
public:
 void meow() { std::cout << "regular cat! meow!\n"; }
};

class Tiger : public CatFamily {
public:
 void meow() { std::cout << "tiger! MREOWWW!\n"; }
};

class Cougar : public CatFamily {
public:
 void meow() { std::cout << "cougar! rrrrrrrrrrrrr!-hiss!\n"; }
};

void do_meowing(CatFamily *cat) {
 cat->meow();
}

int main1() {
std::cout <<"main1: Subtype Polymorphism (Runtime Polymorphism \n";
 Cat cat;
 Tiger tiger;
 Cougar cougar;

 do_meowing(&cat);
 do_meowing(&tiger);
 do_meowing(&cougar);
}

// Here the main program passes pointers to cat, tiger and cougar to do_meowing function that expects a pointer to CatFamily. Since they are all CatFamilys, the program calls the right meow function for each felid and the output is:

// Meowing like a regular cat! meow!
// Meowing like a tiger! MREOWWW!
// Meowing like an cougar! mews!

// Subtype polymorphism is also called runtime polymorphism for a good reason. The resolution of polymorphic function calls happens at runtime through an indirection via the virtual table. Another way of explaining this is that compiler does not locate the address of the function to be called at compile-time, instead when the program is run, the function is called by dereferencing the right pointer in the virtual table.

// In type theory it's also known as inclusion polymorphism.
// Parametric Polymorphism (Compile-Time Polymorphism)

// Parametric polymorphism provides a means to execute the same code for any type. In C++ parametric polymorphism is implemented via templates.

// One of the simplest examples is a generic max function that finds maximum of two of its arguments,

#include <iostream>
#include <string>

template <class T>
T max(T a, T b) {
 return a > b ? a : b;
}

int main2() {
std::cout <<"main2: Parametric Polymorphism (Compile-Time Polymorphism) \n";
 std::cout << ::max(9, 5) << std::endl;     // 9

 std::string foo("foo"), bar("bar");
 std::cout << ::max(foo, bar) << std::endl; // "foo"
}

// Here the max function is polymorphic on type T. Note, however, that it doesn't work on pointer types because comparing pointers compares the memory locations and not the contents. To get it working for pointers you'd have to specialize the template for pointer types and that would no longer be parametric polymorphism but would be ad-hoc polymorphism.

// // Since parametric polymorphism happens at compile time, it's also called compile-time polymorphism.
// Ad-hoc Polymorphism (Overloading)

// Ad-hoc polymorphism allows functions with the same name act differently for each type. For example, given two ints and the + operator, it adds them together. Given two std::strings it concatenates them together. This is called overloading.

// Here is a concrete example that implements function add for ints and strings,

#include <iostream>
#include <string>

int add(int a, int b) {
 return a + b;
}

std::string add(const char *a, const char *b) {
 std::string result(a);
 result += b;
 return result;
}

int main3() {
 
std::cout <<"main3: Parametric Polymorphism (Compile-Time Polymorphism) mixing ints and strings \n";
 std::cout << add(5, 9) << std::endl;
 std::cout << add("hello ", "world") << std::endl;
}

// Ad-hoc polymorphism also appears in C++ if you specialize templates. Returning to the previous example about max function, here is how you'd write a max for two char *,

#include <cstring>  // needed for strcmp

template <>
const char *max(const char *a, const char *b) {
 return strcmp(a, b) > 0 ? a : b;
}

// Now you can call ::max("foo", "bar") to find maximum of strings "foo" and "bar".
// Coercion Polymorphism (Casting)

// Coercion happens when an object or a primitive is cast into another object type or primitive type. For example,

float b = 6; // int gets promoted (cast) to float implicitly
int a = 9.99; // float gets demoted to int implicitly

// Explicit casting happens when you use C's type-casting expressions, such as (unsigned int *) or (int) or C++'s static_cast, const_cast, reinterpret_cast, or dynamic_cast.

// Coercion also happens if the constructor of a class isn't explicit, for example,

#include <iostream>

class A {
 int foo;
public:
 A(int ffoo) : foo(ffoo) {}
 void giggidy() { std::cout << foo << std::endl; }
};

void moo(A a) {
 a.giggidy();
}

int main4() {
std::cout <<"main4: coercion Polymorphism (Casting)\n";
 moo(55);     // prints 55
}

// If you made the constructor of A explicit, that would no longer be possible. It's always a good idea to make your constructors explicit to avoid accidental conversions.

// Also if a class defines conversion operator for type T, then it can be used anywhere where type T is expected.

// For example,

class CrazyInt {
 int v;
public:
 CrazyInt(int i) : v(i) {}
 operator int() const { return v; } // conversion from CrazyInt to int
};

// The CrazyInt defines a conversion operator to type int. Now if we had a function, let's say, print_int that took int as an argument, we could also pass it an object of type CrazyInt,

#include <iostream>

void print_int(int a) {
 std::cout << a << std::endl;
}

int main5() {
std::cout <<"main5: coercion Polymorphism (Casting) with operator, operator int() ... \n";
 CrazyInt b = 55;
 print_int(999);    // prints 999
 print_int(b);      // prints 55
}

// Subtype polymorphism that I discussed earlier is actually also coercion polymorphism because the derived class gets converted into base class type.
// Have Fun!

// Have fun with all the new knowledge about polymorphism!

int main(int argc, char ** argv)
{
  main1();
  main2();
  main3();
  main4();
  main5();
}
