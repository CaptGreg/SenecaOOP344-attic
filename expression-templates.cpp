// http://en.wikipedia.org/wiki/Expression_templates


// The 2011 standard of C++ includes rvalue references,
// which remove the need for expression templates in the
// most common cases. In the above example, if Vec has an
// rvalue-compatible constructor (known as a move constructor)
// and an rvalue-compatible operator* then these will not
// allocate any memory, so a new Vec is allocated only once
// (in the expression u - v). Expression templates may be
// considered a workaround for the lack of move semantics
// in the previous C++ standard. An alternative technique
// is to directly emulate move semantics, for example using
// the Boost move library.

#include <iostream>
using namespace std;

#include <vector>
#include <cassert>
 
template <typename E>
// CRTP:  http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern

// A CRTP base class for Vecs with a size and indexing:
class VecExpression {
public:
  typedef std::vector<double>         container_type;
  typedef container_type::size_type   size_type;
  typedef container_type::value_type  value_type;
  typedef container_type::reference   reference;
 
  size_type  size()                  const { return static_cast<E const&>(*this).size(); }
  value_type operator[](size_type i) const { return static_cast<E const&>(*this)[i];     }
 
  operator E&()             { return static_cast<      E&>(*this); }
  operator E const&() const { return static_cast<const E&>(*this); }
};
 
// The actual Vec class:
class Vec : public VecExpression<Vec> {
   container_type _data;
public:
   reference  operator[](size_type i)       { return _data[i]; }
   value_type operator[](size_type i) const { return _data[i]; }
   size_type  size()                  const { return _data.size(); }
 
   Vec(size_type n) : _data(n) {} // Construct a given size:
 
   // Construct from any VecExpression:
   template <typename E>
   Vec(VecExpression<E> const& vec) {
     E const& v = vec;
     _data.resize(v.size());
     for (size_type i = 0; i != v.size(); ++i) {
       _data[i] = v[i];
     }
   }
};
 
template <typename E1, typename E2>
class VecDifference : public VecExpression<VecDifference<E1, E2> > {
  E1 const& _u;
  E2 const& _v;
public:
  typedef Vec::size_type size_type;
  typedef Vec::value_type value_type;
  VecDifference(VecExpression<E1> const& u, VecExpression<E2> const& v) : _u(u), _v(v) {
    assert(u.size() == v.size());
  }
  size_type size() const { return _v.size(); }
  value_type operator[](Vec::size_type i) const { return _u[i] - _v[i]; }
};
 
template <typename E1, typename E2> // GB
class VecSum : public VecExpression<VecSum<E1, E2> > {
  E1 const& _u;
  E2 const& _v;
public:
  typedef Vec::size_type size_type;
  typedef Vec::value_type value_type;
  VecSum(VecExpression<E1> const& u, VecExpression<E2> const& v) : _u(u), _v(v) {
    assert(u.size() == v.size());
  }
  size_type size() const { return _v.size(); }
  value_type operator[](Vec::size_type i) const { return _u[i] + _v[i]; }
};

template <typename E>
class VecScaled : public VecExpression<VecScaled<E> > {
  double _alpha; 
  E const& _v;
public:
  VecScaled(double alpha, VecExpression<E> const& v) : _alpha(alpha), _v(v) {}
  Vec::size_type size() const { return _v.size(); }
  Vec::value_type operator[](Vec::size_type i) const { return _alpha * _v[i]; }
};
 
// Now we can overload operators:
 
template <typename E1, typename E2>
VecDifference<E1,E2> const
operator-(VecExpression<E1> const& u, VecExpression<E2> const& v) {
   return VecDifference<E1,E2>(u,v);
}
 

template <typename E1, typename E2> // GB
VecSum<E1,E2> const
operator+(VecExpression<E1> const& u, VecExpression<E2> const& v) {
   return VecSum<E1,E2>(u,v);
}


template <typename E>
VecScaled<E> const
operator*(double alpha, VecExpression<E> const& v) {
   return VecScaled<E>(alpha,v);
}


int main(int argc, char**argv)
{
    double alpha = 3.;

    Vec u(3), v(3);
    u[0] = 1;
    u[1] = 1;
    u[2] = 1;

    v[0] = 2;
    v[1] = 2;
    v[2] = 2;

    Vec x = alpha *(u - v);

    cout << x[0]<< endl;
    cout << x[1]<< endl;
    cout << x[2]<< endl;

    Vec y = alpha *(u + v);
    // Vec y = x;

    cout << y[0]<< endl;
    cout << y[1]<< endl;
    cout << y[2]<< endl;
}
