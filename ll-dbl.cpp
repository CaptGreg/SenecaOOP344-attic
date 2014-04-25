// http://codereview.stackexchange.com/questions/40922/creating-linked-list-data-with-iterator-pattern

// GB this code has syntax errors.

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdlib.h>
#include <algorithm>

template <typename Object>
class Linkedlist
{
  private:
    // The basic doubly linked Linkedlist node.
    // Nested inside of Linkedlist, can be public
    // because the Node is itself private
    struct Node
    {
        Object  _data;
        Node   *_prev;
        Node   *_next;

        Node( const Object & d = Object( ), Node * p = NULL, Node * n = NULL )
          : _data( d ), _prev( p ), _next( n ) { }
    };

  public:
    Linkedlist( )
      { init( ); }

    ~Linkedlist( )
    {
        clear( );
        delete _head;
        delete _tail;
    }

    Linkedlist( const Linkedlist & rhs )  // copy ctor
    {
        init( );
        *this = rhs;
    }

    const Linkedlist & operator= ( const Linkedlist & rhs ) // asignment operator
    {
        if( this == &rhs )
            return *this;
        clear( );
        for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
            push_back( *itr );
        return *this;
    }


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    comments from posting:
    You define the copy constructor in terms of the assignment operator

    Linkedlist( const Linkedlist & rhs )
    {
        init( );
        *this = rhs;
    }

    It is more traditional to do it the other way around.
    Normally you define the assignment in terms of the copy constructor.
    The idiom is called "Copy and Swap"

    Linkedlist(Linkedlist const& rhs)
    {
        // Create a copy
    }

    Linkedlist& operator=(Linkedlist rhs) // pass by value to get copy
    {
        rhs.swap(*this);   // swap the copy with this.
        return *this;      // As rhs leaves scope with the old values
    }                      // it is automatically deleted.

    There are a couple of problems with doing it the other way around.
    You define the copy constructor in terms of the assignment operator

    Linkedlist( const Linkedlist & rhs )
    {
        init( );
        *this = rhs;
    }

    It is more traditional to do it the other way around. Normally you define the assignment in terms of the copy constructor. The idiom is called "Copy and Swap"
    http://en.cppreference.com/w/cpp/language/as_operator

    Linkedlist(Linkedlist const& rhs)
    {
        // Create a copy
    }

    Linkedlist& operator=(Linkedlist rhs) // pass by value to get copy
    {
        rhs.swap(*this);   // swap the copy with this.
        return *this;      // As rhs leaves scope with the old values
    }                      // it is automatically deleted.

    There are a couple of problems with doing it the other way around.
    You do not provide the strong exception guarantee. On an assignment you destroy the content of you list. Then start to populate it with new values. If at any point copying fails you are left with a half complete object and no way to roll back to the original object.

    Assignment should fall into three distinct phases.

    A = B;

        Create a copy of the object being assigned from B into a temporary object. This will be the new value that A holds once everything works. If this copy fails then the value of A should not be changed.

        Swap the internal state of A with the temporary object. Since a swap should never fail this has no danger. A will now hold a copy of B and the temporary object will hold the old value of A.

        Destroy the old object. If this fails it does not matter. As the state of A is now consistent.

        const Linkedlist & operator= ( const Linkedlist & rhs ) {
            if( this == &rhs ) return *this; clear( );

            // At this point A has been cleared. Thus if the folloping loop fails you have no way to recover the original value of A. This will leave your program in a funny state. You have provided The Basic Exception Guarantee in that the object is not invalid. But this is not usually acceptable.

            for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
                push_back( *itr );


            return *this;
        }

    This seems a bit over-elaborate!

    Object & front( )
      { return *begin( ); }

    You are creating an iterator just to de-reference it! Why not just

    Object & front( )
      { return head->next.data; }

    You should also put a comment that it is undefined behavior when the list is empty. Best to document these things up front.x

    Not to sure you need to define two different classes for iterator and const_iterator. Seems like a lot of duplicated code.

    Also you iterator does not meet even the requirements to trivial iterator as you are missing operator ->. See http://www.sgi.com/tech/stl/table_of_contents.html specifically look at the iterator section. I presume you are actually trying to implement the concept of Bi-Directional iterator the definition can be found here http://www.sgi.com/tech/stl/BidirectionalIterator.html

    In addition your container object is supposed to provide some specific types that allow the user of your class to obtain information about the content type. Requirements can be found here: http://www.sgi.com/tech/stl/Container.html

    See here for an example of an iterator: http://codereview.stackexchange.com/a/9399/507 (though I did not make the container as well as I could because I did not specify the types I should have).

    See here for an example of a linked list using a single sentinel.
    http://codereview.stackexchange.com/a/28393/507


    There is small possibility to have memory leak here:

        _head = new Node;
        _tail = new Node;

    consider if after successfull allocaiton of first Node you get std::bad_alloc on second Node

    Class invariant is not preserved here:

        _size++;
        return iterator( p->_prev = p->_prev->_next = new Node( x, p->_prev, p ) );

    Again there is small posibility of std::bad_alloc when you create new Node but you have already increased _size

    By the way - I remember leading underscores are discouraged from usage in application code

  +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



    // Return iterator representing beginning of Linkedlist
    // Mutator version is first, then accessor version
    iterator begin( )
      { return iterator( _head->_next ); }

    const_iterator begin( ) const
      { return const_iterator( _head->_next ); }

    // Return iterator representing endmarker of Linkedlist.
    // Mutator version is first, then accessor version.
    iterator end( )
      { return iterator( _tail ); }

    const_iterator end( ) const
      { return const_iterator( _tail ); }

    // Return number of elements currently in the Linkedlist.
    int size( ) const
      { return _size; }

    // Return true if the Linkedlist is empty, false otherwise.
    bool empty( ) const
      { return size( ) == 0; }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( )
      { return *begin( ); }

    const Object & front( ) const
      { return *begin( ); }

    Object & back( )
      { return *--end( ); }

    const Object & back( ) const
      { return *--end( ); }

    void push_front( const Object & x )
      { insert( begin( ), x ); }

    void push_back( const Object & x )
      { insert( end( ), x ); }

    void pop_front( )
      { erase( begin( ) ); }

    void pop_back( )
      { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        _size++;
        return iterator( p->_prev = p->_prev->_next = new Node( x, p->_prev, p ) );
    }

    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->_next );
        p->_prev->_next = p->_next;
        p->_next->_prev = p->_prev;
        delete p;
        _size--;

        return retVal;
    }

    iterator erase( iterator start, iterator end )
    {
        for( iterator itr = start; itr != end; )
            itr = erase( itr );

        return end;
    }

  private:
    int   _size;
    Node *_head;
    Node *_tail;

    void init( )
    {
        _size = 0;
        _head = new Node;
        _tail = new Node;
        _head->_next = _tail;
        _tail->_prev = _head;
    }
};

#endif


#include <iostream>
#include <string>
using namespace std;

int main(int argc, char**argv)
{
    Linkedlist<string> ll;
    return 0;
}
