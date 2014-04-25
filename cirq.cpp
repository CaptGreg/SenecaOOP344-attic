// http://basic-datastructure-faq.blogspot.ca/2011/10/possible-queslinked-list-cont.html
//  Create & Delete node for Circular Linked list
// The Circular LinkedList is Data structure where tail of linked list is connected Head of node.

// GB doesn't compile: many, many sloppy coding problems but algo looks correct
// GB after making it compile, not much original code remains.

#include <iostream>
using namespace std;

class CirQ {

    struct node
    {
        int         data;
        struct node *next;
    } *head, *tail;

    public:
    CirQ() : head(nullptr), tail(nullptr) {}
    void push(int num)
    {
        node *n= new node;
        n->data = num;
        if(head==nullptr) { /*this if wil become true when circular node is empty*/
            head= n;
        } else {
            tail->next= n;
        }
        tail= n;
        tail->next=head;
    }

    // pop tail node from Circular LinkedList
    bool pop(int& item)
    {
        node *n;
        if(head!=nullptr) {
            if(head==tail) { // only 1 node
                 item= head->data;
                 delete head;
                 head=nullptr;
                 tail=nullptr;
             } else {
                 n=head;
                 item=n->data;
                 head=head->next;
                 tail->next=head;
                 delete n;
             }
             return true;
        }
        return false;
    }

    bool peek(bool fromHead,int& item)
    {
        if(head!=nullptr) {
            item = (fromHead? head->data: tail->data);
            return true;
        }

        return false;
    }
    void print(char *msg = nullptr)
    {
        if(msg) cout << msg << endl;
        node *n = head;
        int count = 0;
        while(n) {
            cout << count++ << ": " << n->data << endl;
            if(n == tail) break;
            n = n-> next;
        }
    }
};

int main()
{
    int r;
    CirQ cq;
    cq.print("empty CirQ");

    cout <<"pushing " <<14 <<endl;
    cq.push(14);
    for(int i = 0; i < 3; i++ ) {
        cout <<"pushing " <<i <<endl;
        cq.push(i);
        if(cq.peek(true, r)) { cout <<"head = " <<r <<endl; }
        if(cq.peek(false, r)) { cout <<"tail = " <<r <<endl; }
        cout << endl;
    }

    cq.print("populated");

    while(cq.pop(r)) {
        cout <<"popped " <<r <<endl;
    }




}
