#include <iostream>
using namespace std;

#include <malloc.h>


int main(int argc, char **)
{
	short *big_buf;

	big_buf = (short *) malloc(10000000);

	cout << sizeof(big_buf) << endl;
	cout << big_buf << endl;

	if(big_buf) free(big_buf);
}

