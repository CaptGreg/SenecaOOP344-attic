#include <cinttypes>
#include <iostream>
using namespace std;

unsigned int intSetBit(unsigned int target, int bit)
{
    unsigned int mask = (1 << bit);
    return target | mask;
}

template <class T>
T setBit(T target, int bit)
{
    T mask = (1 << bit);
    return target | mask;
}

template <class T>
T clearBit(T target, int bit)
{
    T mask = (1 << bit);
    return target & (~mask);
}

template <class T>
bool testBit(T target, int bit)
{
    T mask = (1 << bit);
    return target & mask;
}

template <class T>
void printBits(T target)
{
    for(int bit = 8 * sizeof(T) -1; bit >=0 ; bit--) {
        cout << testBit(target,bit);
    }
}

int main(int argc, char ** argv, char ** env)
{
    for(int bit = 0; bit < 8; bit++ ) {
        unsigned int target  = 0;
        target = intSetBit(target, bit);
        cout <<"intSetBit: bit " << bit << " on, target = " << target << endl;
    }

    for(int bit = 0; bit < 8; bit++ ) {
        unsigned int target  = 0;
        target = setBit(target, bit);
        cout <<"setBit (template function) bit " << bit << " on, target = " << target << endl;
    }

    unsigned short target;
    cout << "sizeof(target) = "<< sizeof(target) << " bytes, " << 8 * sizeof(target) << " (bits)" << endl;
    for(int bit = 0; bit < 8*sizeof(target); bit++ ) {
        target  = ~0;
        target = clearBit(target, bit);
        // cout <<"clearBit (template function) bit " << bit << " on, target = " << target << endl;
        printBits(target);
        cout << endl;
    }


	uint8_t A = 23;
	uint8_t B = 32;

	cout << "A = " << (int) A << endl;
	cout << "B = " << (int) B << endl;
	cout << "A="; printBits(A);  cout << endl;
	cout << "B="; printBits(B);  cout << endl;
	cout << endl;

	A = A ^ B;
	cout << "after A = A ^ B;" << endl;
	cout << "A="; printBits(A);  cout << endl;
	cout << "B="; printBits(B);  cout << endl;
	cout << endl;

	B = A ^ B;
	cout << "after B = A ^ B;" << endl;
	cout << "A="; printBits(A);  cout << endl;
	cout << "B="; printBits(B);  cout << endl;
	cout << endl;

	A = A ^ B;
	cout << "after A = A ^ B;" << endl;
	cout << "A="; printBits(A);  cout << endl;
	cout << "B="; printBits(B);  cout << endl;
	cout << endl;

	cout << "A = " << (int) A << endl;
	cout << "B = " << (int) B << endl;
}
