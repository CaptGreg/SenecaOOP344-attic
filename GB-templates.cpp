#include <iostream>
using namespace std;

template <typename T>
class Pt2d {
public:
  Pt2d() {}
  Pt2d(T x, T y) { _x = x; _y = y; }
  Pt2d(const Pt2d& p) : _x( p._x ), _y( p._y ) {}
  T getX() { return _x;}
  T getY() { return _y;}
  void setX(T x) { _x = x; }
  void setY(T y) { _y = y; }
private:
  T _x;
  T _y;
};

class Pt2d_f {
public:
  Pt2d_f () {}
  Pt2d_f (float x, float y) { _p.setX(x); _p.setY(y); }
private:
  Pt2d <float>  _p;
};

class Pt2d_d {
public:
  Pt2d_d () {}
  Pt2d_d (double x, double y) { _p.setX(x); _p.setY(y); }
private:
  Pt2d <double>  _p;
};

class Pt2d_i {
public:
  Pt2d_i () {}
  Pt2d_i (int x, int y) { _p.setX(x); _p.setY(y); }
private:
  Pt2d <int>  _p;
};



template <typename T>
class Pt3d {
public:
  Pt3d() {_x = _y = _z = -1;}
  Pt3d(T x, T y, T z) { _x = x; _y = y; _z = z; }
  T getX() { return _x;}
  T getY() { return _y;}
  T getZ() { return _z;}
  void setX(T x) { _x = x; }
  void setY(T y) { _y = y; }
  void setZ(T z) { _z = z; }
private:
  T _x;
  T _y;
  T _z;
};

template <class P>
class Line {
public:
  Line(P p1, P p2) : _p1(p1), _p2(p2)  { }
private:
  P _p1;
  P _p2;
};

class Pt2d_f2 {
public:
  Pt2d_f2 ( Pt2d <float> p ) : _p(p) { }
private:
  Pt2d <float> _p;
};

class Line_f {
public:
  Line_f (Pt2d_f p1, Pt2d_f p2) : _p1(p1), _p2(p2)  { }
private:
  Pt2d_f _p1;
  Pt2d_f _p2;
};

int main(int argc, char **argv)
{
  Pt2d <float>  Pt2d_f1( 1, 33.9);
  Pt2d <float>  Pt2d_f2( 2, 34.9);
  Pt2d <double> Pt2d_d1(13, 3.3);
  Pt2d <double> Pt2d_d2(14, 4.3);


  Pt2d_f Pt2d_f_1(1,2);
  Pt2d_f Pt2d_f_2(3,4);

  Line_f Lf (Pt2d_f_1, Pt2d_f_2);

  Line <Pt2d_f > L_f (Pt2d_f_1, Pt2d_f_2);

  Pt2d_d Pt2d_d_1(1,2);
  Pt2d_d Pt2d_d_2(3,4);

  Line <Pt2d_d > L_d (Pt2d_d_1, Pt2d_d_2);
}

