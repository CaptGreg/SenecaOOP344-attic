#if 0
XOR is a very interesting logical operator that can be difficult to understand.  There is a bitwise operator refresher located here.  The basic rules are:

    0 ^ 0 = 0
    A ^ 0 = A
    A ^ A = 0
    A ^ B = B ^ A
    (A ^ B) ^ A = B
    (B ^ A) ^ B = A

When we apply this, instead of having a ‘next’ and ‘prev’ like a normal linked list, we have one ‘NextPrev’ that holds the XOR of both the ‘next’ and ‘prev’.

    NextPrev = Next ^ Prev
    Next = NextPrev ^ Prev
    Prev = NextPrev ^ Next

Based on the rules above, both head ( with Next as 0 ) and tail (with Prev as 0) maintain the actual pointer to the next object because XOR with zero leaves the original bits.  As a side effect the head and tail pointers are the only entry points.  If there is a pointer to an object in the middle of the list, there is no way to traverse from that object without knowing the actual next or previous item.  Another caveat is that debuggers will not be able to recognize the pointers in the list other than ‘head->prev’ and ‘tail->next’.


Keep track of previous node.
next = current.x ^ previous;
To delete current:
prev.x = prev.x ^ current ^ next;
next.x = next.x ^ current ^ prev;
#endif

// algo1
// derived from http://stackoverflow.com/questions/3531972/c-code-for-xor-linked-list
// converted in-line code to class XorLL;

#include <iostream>
#include <stdint.h>  // intptr_t
using namespace std;

class Node {
public:
   int  data;
   Node  *npx; /* npx=XOR of next and previous node */
};

class XorLL {
private:
    Node *head;
    Node *tail;
    int count;
public:
    XorLL() : head(nullptr), tail(nullptr), count(0) {}
    ~XorLL() {
    }

private:
    // traverse the list given either the head or the tail
    void traverse( Node *start )  // point to head or tail
    {
       Node *prev, *curr;

       curr = prev = start;
       while ( curr ) {
          cout <<"data = " <<curr->data <<endl;
          if ( curr->npx == curr ) {
             break; // done
          }
          if ( curr == prev ) {
             curr = curr->npx;   // start of list
          } else {
             Node *save = curr;
             curr = (Node*)((uintptr_t)prev ^ (uintptr_t)curr->npx);
             prev = save;
          }
       }
    }

    // create a new node adding it to the given end and return it
    Node* newnode( Node *prev, Node *curr, int data )
    {
       Node *next = new Node;
       next->data = data;
       next->npx   = curr;  // end node points to previous one

       count++;

        if ( curr == nullptr ) {
            ; // very first node - we'll just return it
        } else if ( prev == nullptr ) {
            // this is the second node (they point at each other)
            curr->npx = next;
            next->npx = curr;
        } else {
            // do the xor magic
            curr->npx = (Node*)((uintptr_t)prev ^ (uintptr_t)next);
        }

       return next;
    }
    void firstNode(int data)
    {
        // the first two nodes point at each other.
        // Weird param calls to get the list started
        head = tail = newnode( nullptr, nullptr, data );
    }
    void secondNode(int data)
    {
        // the first two nodes point at each other.
        // Weird param calls to get the list started
        tail = newnode( nullptr, tail, data );
    }
public:
    void pushHead(int data)
    {
        switch(count) {
            case 0:  firstNode(data);                           break;
            case 1:  secondNode(data);                          break;
            default: head = newnode( head->npx, head, data );    break;
        }
    }
    void pushTail(int data)
    {
        switch(count) {
            case 0:  firstNode(data);                           break;
            case 1:  secondNode(data);                          break;
            default: tail = newnode( tail->npx, tail, data );    break;
        }
    }
    void traverseForwards( )
    {
        traverse( head );
    }
    void traverseBackwards( )
    {
        traverse( tail );
    }
};

int main1( int argc, char* argv[] )
{
    int   data = 1;
    XorLL ll;

    ll.pushHead(data++);
    ll.pushTail(data++);
    ll.pushTail(data++);
    ll.pushTail(data++);
    ll.pushHead(999);

    cout <<"Algo 1: Forwards:\n";
    ll.traverseForwards( );
    cout <<"Algo 1: Backwards:\n";
    ll.traverseBackwards( );

    return 0;
}


// algo2
// XOR LL #2
// http://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
// http://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/

/* C/C++ Implementation of Memory efficient Doubly Linked List */

// Node structure of a memory efficient doubly linked list

/* returns XORed value of the node addresses */
Node* XOR (Node *a, Node *b)
{
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

/* Insert a node at the begining of the XORed linked list and makes the
   newly inserted node as head */
void insert(Node **head_ref, int data)
{
    // Allocate memory for new node
    Node *new_node  = new Node;
    new_node->data = data;

    /* Since new node is being inserted at the begining, npx of new node
       will always be XOR of current head and nullptr */
    new_node->npx = XOR(*head_ref, nullptr);

    /* If linked list is not empty, then npx of current head node will be XOR
       of new node and node next to current head */
    if (*head_ref != nullptr) {
        // *(head_ref)->npx is XOR of nullptr and next. So if we do XOR of
        // it with nullptr, we get next
        Node* next = XOR((*head_ref)->npx,  nullptr);
        (*head_ref)->npx = XOR(new_node, next);
    }

    // Change head
    *head_ref = new_node;
}

void traverse2( Node *start )  // point to head or tail
{
   Node *prev, *curr;

   curr = prev = start;
   while ( curr ) {
      cout <<"traverse = " <<curr->data <<endl;
      if ( curr->npx == curr ) {
         break; // done
      }
      if ( curr == prev ) {
         curr = curr->npx;   // start of list
      } else {
         Node *save = curr;
         curr = (Node*)((uintptr_t)prev ^ (uintptr_t)curr->npx);
         prev = save;
      }
   }
}

// prints contents of doubly linked list in forward direction
void printList (Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    cout <<"Algo 2: Following are the nodes of Linked List: ";

    while (curr != nullptr) {
        // print current node
        cout <<curr->data <<" ";

        // get address of next node: curr->npx is next^prev, so curr->npx^prev
        // will be next^prev^prev which is next
        next = XOR (prev, curr->npx);

        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    cout <<endl;
}

// Driver program to test above functions
int main2( int argc, char* argv[] )
{
    /* Create following Doubly Linked List
       head-->40<-->30<-->20<-->10   */
    Node *head = nullptr;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // print the created list
    printList (head);
    traverse2 (head);
    // traverse2 (tail);
    // Need to figure out how to traverse list in reverse.
    // printList (head);

    return 0;
}


// algo3
// http://blog.wsensors.com/2011/04/the-xor-linked-list-in-c/

// Implementation
// This is the header file for the list.  The behavior of the list is:
//     If there are no entries head and tail are 0
//     If there is one entry, head is the entry and tail is 0
//     If there are 2 or more entries head and tail are both set as are the items npx variable that holds both next and previous

class DoubleLinkedXOR
{
public:
    DoubleLinkedXOR() : head(nullptr), tail(nullptr) { }
    ~DoubleLinkedXOR(){}

    void AddToTail( Node* entry )
    {
        if( !head ) { //no items
            entry->npx = nullptr;
            head = entry;
        } else if( !tail ) { //just head is set, one item in list
            tail      = entry;
            tail->npx = head;
            head->npx = tail;
        } else { //two items or more, insert
            entry->npx = tail;
            tail->npx = (Node*)( (uintptr_t)(tail->npx) ^ (uintptr_t)entry);
            tail = entry;
        }
    }
    Node *RemoveFromHead()
    {
        Node* item = head;

        if( !head ) {
            return nullptr;
        } else if( !tail ) { // just one item
            head      = nullptr;
            return item;
        } else if( head->npx == tail
               &&  tail->npx == head) { // only two items
            head      = tail;
            tail      = nullptr;
            head->npx = nullptr;
            return item;
        } else {
            head      = head->npx;
            head->npx = (Node*)((uintptr_t)(head->npx) ^(uintptr_t) item);
            return item;
        }
    }
   void traverseForwards( )
    {
        traverse( head );
    }
    void traverseBackwards( )
    {
        traverse( tail );
    }
    void push(int data)
    {
        Node *newItem = new Node;
        // cout <<"Algo3: inserting " <<data <<" @" <<newItem <<endl;
        newItem->data = data;
        AddToTail(newItem);
        // cout <<"Added item: " <<newItem->data <<endl;
    }
    int pop()
    {
        int ret;
        // cout <<"Algo3: retrieving " <<endl;
        Node *retrievedItem = RemoveFromHead();
        // cout <<"Retrieved item: " << retrievedItem->data <<" @" <<retrievedItem <<endl;
        ret = retrievedItem->data;
        delete retrievedItem;

        return ret;
    }
private:
    void traverse( Node *start )  // point to head or tail (cloned from algo1)
    {
        Node *prev, *curr;

        curr = prev = start;
        while ( curr ) {
            cout <<"traverse = " <<curr->data <<endl;
            if ( curr->npx == curr ) {
                break; // done
            }
            if ( curr == prev ) {
                curr = curr->npx;   // start of list
            } else {
                Node *save = curr;
                curr = (Node*)((uintptr_t)prev ^ (uintptr_t)curr->npx);
                prev = save;
            }
        }
    }
private:
    Node *tail;
    Node *head;
};

int main3( int argc, char *argv[] )
{
    DoubleLinkedXOR  *list = new DoubleLinkedXOR;

    int x, count = 10;

    cout << "Algo3:\n";
    for( x = 0;  x < count; x++ ) { //add all items to list
        list->push(x);
    }
    cout << "forward:\n";
    list->traverseForwards( );
    cout << "Backwards:\n";
    list->traverseBackwards( );

    cout <<"Algo 3 popped: ";
    for( x = 0; x < count; x++ ) {
        int data = list->pop();
        cout << data <<" ";
    }
    cout << endl;

    delete list;

    return 0;
}

int main( int argc, char* argv[] )
{
    main1( argc, argv );
    main2( argc, argv );
    main3( argc, argv );
}
