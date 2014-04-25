#include <iostream>
using namespace std;

int main(int argc, char**argv, char**env)
{
    int num = 0;

    for(int i = 0; i < argc; i++) {
        cout<<"argv["<<i<<"]==>"<<argv[i]<<"<==\n";
        if(*argv[i] == '-')
		switch(*(argv[i] + 1)) {
		case 'n':
		case 'N':
			num = atoi( argv[i] + 2 );
			break;
		}
    }

    cout << "num=" << num << endl;

    // for(int i = 0; env[i]; i++)
        // cout<<"env["<<i<<"]==>"<<env[i]<<"<==\n";
}
