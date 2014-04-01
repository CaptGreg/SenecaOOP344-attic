#include <iostream>
using namespace std;

#include "x.h"

void y1(int  x) {  x = 27; cout << "inside y1  x = " <<  x << endl; }
void y2(int *x) { *x = 37; cout << "inside y2 *x = " << *x << endl; }
void y3(int &x) {  x = 47; cout << "inside y3  x = " <<  x << endl; }

int main(int argc, char **arg, char **env)
{
	int x = 19;

	cout << "x = " << x << endl;

	y1(x);
	cout << "x = " << x << endl;

	y2(&x);
	cout << "x = " << x << endl;

	y3(x);
	cout << "x = " << x << endl;

	X xyz;
        cout << "xyz at 27 is " << xyz.getXatIndex(27) << endl;
	xyz.setX(12);
	// xyz.p = nullptr;
        cout << "xyz at 27 is " << xyz.getXatIndex(27) << endl;
	X abc = xyz;;
        // xyz = abc;
}

