#if 0
// cut and paste this to a 'makefile'
// cut start ** cut start ** cut start ** cut start ** cut start **

# 'makefile' to 
# 1.  compile and build test1 
# 2.  compile again with VIRTUAL defined to make test1-virtual

all : test1 test1-virtual

test1: test1.cpp
	g++ test1.cpp -o test1

test1-virtual: test1.cpp
	g++ -DVIRTUAL test1.cpp -o test1-virtual

// cut stop ** cut stop ** cut stop ** cut stop ** cut stop **
#endif

#include <iostream>

class Leg {
public:
 double legLength;            // meters (m)
 double longestClawLength;    // meters (m)
 bool   missingClaw;          // yes/no
};

class CatFamily {   // base class
private:
 // properties of a cat
 bool   hungrey;              // yes/no
 double tailLength;           // meters (m)
 double weight;               // kilograms (kg)
 double earLength;            // meters (m)
 int    legCount;             // most cats have 4 legs, some cats have 3 legs
 Leg    *legTable;

 void setupLegs(int legs) { legCount = legs;  legTable = new Leg[legs]; } // some cats are missing a leg
public:
 CatFamily(int legs = 4) { setupLegs(legs); } // most have 4 legs.
 ~CatFamily() {delete [] legTable; }

#ifdef VIRTUAL
 virtual void meow() { std::cout << "who called the base class?\n"; }
#else
 void meow() { std::cout << "who called the base class?\n"; }
#endif

};

class Cat : public CatFamily { // derived class
public:
 void meow() { std::cout << "regular cat! meow!\n"; }
};

class Tiger : public CatFamily { // derived class
public:
 void meow() { std::cout << "tiger! MREOWWW!\n"; }
};

class Cougar : public CatFamily { // derived class
public:
 void meow() { std::cout << "cougar! rrrrrrrrrrrrr!-hiss!\n"; }
};

void speak(CatFamily *cat) {
 cat->meow();
}

int main(int argc, char **argv) {
#ifdef VIRTUAL
 std::cout <<"main: compiled with 'VIRTUAL' defined\n";
#else
 std::cout <<"main: compiled without 'VIRTUAL' defined\n";
#endif

 CatFamily    catFamily;
 Cat          cat;
 Tiger        tiger;
 Cougar       cougar;

 speak(&catFamily);
 speak(&cat);
 speak(&tiger);
 speak(&cougar);
 return 0;
}
