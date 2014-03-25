// OOP344 Test 1
// 
// V1
// 
// 20141
// November 19, 2014
// 
// 
// 
// 
// 
// 
// First Name:        ___________________________________
// Last Name:        ___________________________________
// Student No.:        __ __ __ - __ __ __ - __ __ __ 
// Section:                __
// Allowed Aids:
// * OOP344 Text Book (purchased from book store)
// * OOP244 Text Book (purchased from book store)
// * IPC144 Text Book (purchased from book store)
// * 1 double sided, 8.5”x11” reference sheet, to be handed in with test
// * 1 English paper dictionary
// ________________
// Question 1, walkthrough: [20 Marks]
// Please write the EXACT OUTPUT of the following program.


#include <iostream>

// Please fill in the following digits with digits 4, 5, 6 of your student number
// This define will be used throughout the walkthrough.
// As a result, output of walkthrough will be unique to your student number.

// For example, if Mary's student number was 081-808-769, her defines would be:
// #define S4 8
// #define S5 0
// #define S6 8
#define S4 8
#define S5 0
#define S6 8

#define Test (S4 + S5 + S6) < 14

void walk1();   // 4, Baseline
void walk2();   // 4, Baseline
void walk3();   // 4, Baseline, 60%
void walk4();   // 2, Good, 70%
void walk5();   // 2, Very good, 80%
void walk6();   // 2, Excellent, 90%
void walk7();   // 2, Superb, 100%

int main(){
   walk1();
   walk2();
   walk3();
   walk4();
   walk5();
   walk6();
   walk7();

   system("pause");

   return 0;
}
using namespace std;

#if Test
#define Brownie { return 1; }
#define Sting
#else
#define Brownie { return 2; }
#define Malign
#endif

int Slingshot(){
   return 3;
}

int Bow(){
   return 4;
}

#ifdef Sting
#define Pepper Slingshot
#define Salt Bow
#define Jalapeno Space
#endif

#ifdef Malign
#define Pepper Bow
#define Salt Slingshot
#define Jalapeno Time
#endif

namespace Space {
#ifdef Sting
#undef Brownie
#define Brownie { return 5; }
#undef Sting
#define Malign
#undef Jalapeno
#define Jalapeno Time
#endif

#ifdef Malign
#undef Brownie
#define Brownie { return 6; }
#undef Malign
#define Sting
#undef Jalapeno
#define Jalapeno Space
#endif


    int Pepper () Brownie;
   using ::Salt;

   void Secure(int* L, int* R){
       *L = Slingshot();
       *R = Bow();
   }
}


namespace Time {
#undef Brownie
#ifdef Sting
#define Brownie { return 7; }
#undef Jalapeno
#define Jalapeno Space
#endif

#ifdef Malign
#define Brownie { return 8; }
#undef Jalapeno
#define Jalapeno Time
#endif
   int Salt () Brownie;
   using ::Pepper;

   void Secure(int* L, int* R){
#undef Sting
#undef Malign
       *L = Slingshot();
       *R = Bow();
   }
}

void walk1(){
   cout << "Walk1: 4 marks" << endl;
   cout << "Slingshot: " << Slingshot() << ", Bow: " << Bow() << endl;

   int apple, orange;
   Space::Secure(&apple, &orange);
   cout << "Apple: " << apple << ", Orange: " << orange << endl;
   Time::Secure(&apple, &orange);
   cout << "Apple: " << apple << ", Orange: " << orange << endl;
   Jalapeno::Secure(&apple, &orange);
   cout << "Apple: " << apple << ", Orange: " << orange << endl;

   cout << endl;
}


// ________________


const char* TheBank(const char* val, int idx){
   static const char* minds[7];
   if (val){
       minds[idx] = val;
       return NULL;
   }

   return minds[idx];
}

const char* pavilion(){
   const char* minds[] = {
       "I", "bring", "party", "thrills", "chills", "tortilla", "ice"
   };
   static int argument = 3;
   const char* val = minds[argument];
#if Test
   argument = argument + 1;
#else
   argument = argument - 1;
#endif
   return val;
}

void flux(const char* begin){
   static int argument = 0;
   TheBank(begin, argument);
   argument = argument + 1;
}

const char* drop(){
   static int argument = 3;
   const char* val = TheBank(NULL, argument);
   argument = argument - 1;
   return val;
}

void walk2(){
   // Note for Reviewers: static, memory; difficulty: baseline

   cout << "Walk2: 4 marks" << endl;
   for (int i = 0; i < 4; i++) flux(pavilion());
   for (int i = 0; i < 4; i++) cout << "Drop " << i << ": " << drop() << endl;
   cout << endl;
}


// ________________


void walk3(){
   cout << "Walk3: 4 marks" << endl;
   // generic pointers
   cout << endl;
}

void walk4(){
   cout << "Walk4: 2 marks" << endl;
   // typedef
   cout << endl;
}

void walk5(){
   cout << "Walk5: 2 marks" << endl;
   // operators
   cout << endl;
}

void walk6(){
   cout << "Walk6: 2 marks" << endl;
   // polymorphism
   cout << endl;
}

void walk7(){
   cout << "Walk7: 2 marks" << endl;
   // function pointers
   cout << endl;
}


// OOP344 20141 Test 1 V1                                                                Page  of
