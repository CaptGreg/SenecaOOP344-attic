#include <cstring>
#include <iostream>
using namespace std;

// int main(int argc, char ** argv, char ** env)
int main(int argc, char * argv [],  char *env[])
{
	cout << "argc = " << argc << endl;

	cout << "argv=" << argv << "\n";
	for(int row = 0; row < argc; row++) {
		cout << "argv[" << row << "]=" << argv+row << endl;
	}

	for(int row = 0; row < argc; row++) {
		cout << "argv[" << row << "] " << argv+row << " ==>" << argv[row] << "<==\n";
		char *p = argv[row];
		for(int column = 0; column < strlen(p); column++) {
			// cout << "argv[" << row << "][" << column << "] =" << argv[row][column] << endl;

			cout << "p for row " << row << " [" << column << "] =" << p[column] << endl;
		}
        }

	for(int row = 0; env[row]; row++) {
		cout << "env[" << row << "] " << env+row << " ==>" << env[row] << "<==\n";
		char *p = env[row];
		for(int column = 0; column < strlen(p); column++) {
			// cout << "env[" << row << "][" << column << "] =" << env[row][column] << endl;

			cout << "p for row " << row << " [" << column << "] =" << p[column] << endl;
		}
        }

}
