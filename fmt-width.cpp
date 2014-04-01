#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char**argv)
{
	// double d = 1.2799910108;
	double d = 1.123456789;

	for(int i = 0; i < 10; i++){
		cout << "precision = " << i << " " << fixed << left << setw(20) << setprecision(i) << '[' << d << ']' << endl;
		cout << "precision = " << i << " " << fixed << right << setw(20) << setprecision(i) << '[' << d << ']' << endl;
	}

	cout << fixed << right << setw(10) << setprecision(3);

#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 123.0
	cout << "RED=" << RED << endl;
#define RED 124.0
	cout << "RED=" << RED << endl;
}

