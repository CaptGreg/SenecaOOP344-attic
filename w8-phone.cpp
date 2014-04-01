// Workshop 8 - Derived Classes
// w8.cpp

#include <iostream>
using namespace std;
#include "w8-phone.h"

const int MAX_NO = 20;

int main1(int argc, char **argv) {
    int  n = 0, code, local;
    Phone phone[MAX_NO];

    std::cout << "Telephone List\n";
    std::cout << "==============\n";
    do {
        std::cout << "Area Code: ";
        std::cin >> code;
        if (code != 0) {
            std::cout << "Local No.: ";
            std::cin >> local;
            Phone temp(code, local);
            if (temp.isValid())
                phone[n++] = temp;
        }
    } while (code != 0 && n < MAX_NO);
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        phone[i].display();
        std::cout << std::endl;
    }
 return 0;
}

int main2(int argc, char **argv) {
    int  n = 0, country, code, local;
    IntlPhone phone[MAX_NO];

    std::cout << "Telephone List\n";
    std::cout << "==============\n";
    do {
        std::cout << "Country   : ";
        std::cin >> country;
        if (country != 0) {
            std::cout << "Area Code : ";
            std::cin >> code;
            std::cout << "Local No. : ";
            std::cin >> local;
            IntlPhone temp(country, code, local);
            if (temp.isValid())
                phone[n++] = temp;
        }
    } while (country != 0 && n < MAX_NO);
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        phone[i].display();
        std::cout << std::endl;
    }
    return 0;
}


#include <fstream>
int main3(int argc, char**argv) {
    int  n = 0;
    IntlPhone temp, phone[MAX_NO];

    // 1st parameter argv[0] is pgm name
    // 2nd parameter argv[1] is input file name
    // 3rd parameter argv[2] is output file name
    if(argc > 1 && *argv[1] != '-') { // argc is 2 or more
        std::ifstream fin;
        fin.open(argv[1]); // argv[1] is input file name
        if(fin.is_open()) {
            do {
                fin >> temp;
                if (temp.isValid())
                    phone[n++] = temp;
            } while (temp.isValid() && n < MAX_NO);
            fin.close();
        }
    } else {
        std::cout << "enter international phone numbers:\n"
                     "  country areacode number\n"
                     "  0 0 0 when finished\n\n";
        do {
            std::cin >> temp;
            if (temp.isValid())
                phone[n++] = temp;
        } while (temp.isValid() && n < MAX_NO);
    }


    if(argc > 2 && *argv[2] != '-') { // argc is 3 or more
        std::ofstream fout;
        fout.open(argv[2]); // argv[2] is output file name
        if(fout.is_open()) {
            fout << n << " international phone numbers\n";
            fout << "Telephone List\n";
            fout << "==============\n";
            for (int i = 0; i < n; i++)
                fout << i << ". " << phone[i] << "\n";
            fout.close();
        }
    } else {
        std::cout << n << " international phone numbers\n";
        std::cout << "Telephone List\n";
        std::cout << "==============\n";
        for (int i = 0; i < n; i++)
            std::cout << i << ". " << phone[i] << "\n";
    }
    return 0;
}

int main(int argc, char **argv)
{
  main1(argc, argv);
  main2(argc, argv);
  main3(argc, argv);
  return 0;
}
