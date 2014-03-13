// My top 5 C++11 language features #1 - uniform initialization syntax

// Now, that I am at my #1 favorite feature, I am having a tough time deciding between these two - uniform initialization syntax or rvalue references, but I am going to have to go with initialization syntax this time.

// Uniform initialization syntax, at first, doesn’t seem like a big deal, but it solves something that has irritated me personally forever in C++, initializing STL containers.  So, this new feature accomplishes two things, makes all initialization syntax uniform with a new standardized brace notation and provides a clean mechanism for initializing STL containers. One other nice part of this feature is the capability to now initialize class member variables in the definition.

// Regarding, STL containers, prior to C++11, a developer would need to load data into a container by iterating through the container and using push_back or other equivalent functions to insert data. But now, I just initialize a std::vector using the uniform brace syntax, such as:

#include <vector>
#include <map>
#include <string>
#include <exception>
#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
  try {
    vector<string> strings = { "first_string", "second_string", "third_string"};

    cout << strings[0] << endl;
    cout << strings[1] << endl;
    cout << strings[2] << endl;
    // cout << strings[3] << endl; // segfaults, as expected

    // Or for instance, a std::map:

    std::map<std::string, int> states_and_electoral_votes = { {"California", 55}, {"New York", 29}};

  } catch (exception& e) {
    cout << "standard exception " << e.what() << '\n';
  }

}
