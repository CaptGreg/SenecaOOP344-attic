// g++ x.cpp parms.cpp -o parms

#include "x.h"

#include <iostream>
using namespace std;

#include <memory.h>

const int SIZE = 100;

  X::X() { p = new int[SIZE]; }

  X::~X() { delete [] p; }

  X::X (const X& other) { p = new int[SIZE]; memcpy(p, other.p, SIZE * sizeof(int)); }

  X& X::operator= (const X& other) { if(this != &other) {delete [] p; p = new int[SIZE]; memcpy(p, other.p, SIZE * sizeof(int));} return *this; }

  void X::setX(int val) {for(int i = 0; i < SIZE; i++) p[i] = val; }

  int X::getXatIndex(int index) {return p[index]; }
