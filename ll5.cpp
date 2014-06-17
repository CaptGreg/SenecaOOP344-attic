#include <string>
#include <iostream>
using namespace std;

class Node {
public:
  Node *link;
  // int   data;
  string   data;
};


class List {
  Node *head;
public:

  List() : head(nullptr) {}
  // void push(int d)
  void push(string d)
  {
    Node *n = new Node;
    n->data = d;
    n->link = head;
    head = n;
  }
  // int pop()
  string pop()
  {
    if(head) {
      // int ret = head->data;
      string ret = head->data;
      Node *n = head->link;
      delete head;
      head = n;
      return ret;
    } else
      throw string("list is empty --- cannot pop");
  }

  void print()
  {
    for(Node *n=head; n; n=n->link) {
      cout << n->data << endl;
   }
  }
  void printAddresses()
  {
    cout << "head=" << head << endl;

    for(Node *n=head; n; n=n->link) {
      cout << "NODE:" << n << endl;
      cout << "  link=" << &n->link << "H " << n->link << endl;
      cout << "  data=" << &n->data << "H " << n->data << endl;
   }
  }
};



int main(int argc, char **argv)
{
   cout <<"argc=" << argc << endl;
   for(int i = 0; i < argc; i++)
      cout << "argv[" << i << "]==>" << argv[i] << "<==\n";

   try {
     List ll;

     ll.printAddresses();

     for(int i = 1; i < argc; i++) {
        // ll.push( atoi(argv[i]) );
        ll.push( argv[i] );
        ll.printAddresses();
     }

     ll.print();

     while(1) {
       cout << "popped: " << ll.pop() << endl;
     }
   } catch(string& msg) {
      cout << msg << endl;
   }
}

