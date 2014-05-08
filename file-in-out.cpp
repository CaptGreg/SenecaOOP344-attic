#include <fstream>
#include <iostream>
#include <exception>
using namespace std;
 
int main (int argc, char**argv)
{
   const char *iName = "in";
   const char *oName = "out";

   try {
		// open "in" and read count
		ifstream ifile;
		ifile.open(iName);
		if(!ifile.is_open()) {
			throw "cannot open iName\n";
		}

		int count;
		ifile >> count;

		ifile.close();
	 
		// open "out" and write numbers from 0,...,count-1 to "out"
		ofstream ofile;
		ofile.open(oName);
		if(!ofile.is_open()) {
			throw "cannot create oName\n";
		}
	 
		for(int i = 0; i < count; i++) {
			ofile << i << endl;
		}
		ofile.close();

		return 0;
	}
   catch(const char* e) {
      cerr << "Problem: " << e;
   }
   catch(const exception& e) {
      cerr << "caught standard exception: " << e.what() << endl;
   }
}
