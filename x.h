#ifndef X_H
#define X_H

class X {
private:
  int *p;
public:
  X();

  ~X();

  X (const X& other);

  X& operator= (const X& other);

  void setX(int val);

  int getXatIndex(int index);

};

#endif
