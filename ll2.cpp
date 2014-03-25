// http://tnvbalaji.com/2012/04/04/linkedlist/

// g++ -std=c++0x ll2.cpp -o ll2

#include <iostream>
using namespace std;

class LL
{
private:
      struct Node {
        int data;
        Node* link;
      }*p;

public:
  LL();
  ~LL();

  void Print();         // Prints the contents of linkedlist
  void Append(int data); // Adds a new node at the end of the linkedlist
  void Delete(int data); // Deletes the specified node from the linkedlist

  void AddatBeg(int data);// Adds a new node at the beginning of the linkedlist
  void AddAfter(int pos, int data); // Adds a new node after specified number of nodes
  int Count();          // Counts number of nodes present in the linkedlist

};

LL::LL()
{
  p = nullptr;
}

LL::~LL()
{
  while(p != nullptr) {
    Node *n = p->link ;
    delete p;
    p = n;
  }
  p = nullptr;
}

// Prints the contents of linkedlist
void LL::Print()
{
  if (p == nullptr) {
    cout<< "EMPTY" << endl;
    return;
  }

  //Traverse
  for(Node* n = p; n != nullptr;  n = n->link)
    cout<<n->data<<endl;
  cout<<endl;
}

// Adds a new node at the end of the linkedlist
void LL::Append(int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  newNode->link = nullptr;

  if(p == nullptr) { //create first node
    p = newNode;
  } else {
    //Traverse
    Node *n = p;
    while(n->link != nullptr) {
      n = n->link;
    }

    //add node to the end
    n->link = newNode;
  }
}

// Deletes the specified node from the linkedlist
void LL::Delete( int data )
{
  Node *n;

  n = p;
  //If node to be deleted is first node
  if( n->data == data ) {
    p = n->link;
    delete n;
    return;
  }

  // traverse list till the last but one node is reached
  Node *n2 = n;
  while( n!=nullptr ) {
    if( n->data == data ) {
      n2->link = n->link;
      delete n;
      return;
    }

    n2 = n;
    n = n->link;
  }
  cout<< "\nElement "<<data<<" not Found." ;
}

// Adds a new node at the beginning of the linkedlist
void LL::AddatBeg(int data)
{

  //add new node
  Node *n = new Node;
  n->data = data;
  n->link = p;
  p = n;
}

//Adds a new node after specified number of nodes
void LL::AddAfter(int position, int data)
{
  Node *n;
  Node *n2;
  int i;
  //Skip to the desired portion
  for( i = 0, n = p; i<position; i++) {
    n = n->link;

    //if end of linked list is encountered
    if(n == nullptr) {
      cout<<endl<< "There are less than "<<position<<" elements" ;
      return;
    }
  }

  //insert new node
  n2 = new Node;
  n2->data = data;
  n2->link = n->link;
  n->link = n2;
}

// Counts number of nodes present in the linkedlist
int LL::Count()
{
  int c = 0;
  //Traverse the entire Linked List
  for (Node *n = p; n != nullptr; n = n->link)
    c++;
  return c;
}

int main(int argc, char**argv)
{
  LL* ll = new LL();
  ll->Append(11);
  ll->Append(22);
  ll->Append(33);
  ll->Print();

  ll->Delete(33);
  ll->Print();

  ll->AddatBeg(44);
  ll->Print();

  ll->AddAfter(1, 55);
  ll->Print();

  delete ll;
}
