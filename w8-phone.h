#include <iostream>

class Phone {
public:
  Phone (int _areaCode=-1, int _number=-1);
  void display(std::ostream& s = std::cout) const;
  bool isValid();
  void set(int  _areaCode,int  _number);
  void get(int& _areaCode,int& _number) const ;
private:
  int areaCode;
  int number;
protected:
  bool rangeValid(int x, int lo, int hi);
};

Phone::Phone(int _areaCode, int _number) 
      : areaCode(_areaCode), number(_number)
{ 
}
void Phone::set(int _areaCode,int _number) 
{ 
    areaCode = _areaCode; 
    number = _number; 
}
void Phone::get(int& _areaCode,int& _number)const  
{ 
    _areaCode = areaCode; 
    _number = number; 
}
void Phone::display(std::ostream& s) const 
{ 
    s << areaCode << '-' << number/10000 << '-' << number % 10000; 
}
bool Phone::rangeValid(int x, int lo, int hi) 
{ 
    return lo <= x && x <= hi; 
}
bool Phone::isValid() 
{ 
    return rangeValid(areaCode, 100, 999) && rangeValid(number, 1000000, 9999999); 
}
std::istream& operator>>(std::istream& stream, Phone& p)           // reads p from stream
{
    int ac, n;
    stream >> ac >> n;
    p.set(ac,n);
    return stream;
}
std::ostream& operator<<(std::ostream& stream, const Phone& p)     // writes p to stream
{
    p.display(stream);
    return stream;
}

//////////////////////////////////////////////////

class IntlPhone :public Phone {
public:
  IntlPhone(int _country=-1, int _areaCode=-1, int _number=-1);
  void display(std::ostream& s = std::cout) const;
  bool isValid();
  void set(int  _country,int  _areaCode,int  _number);
  void get(int& _country,int& _areaCode,int& _number) const ;
private:
  int country;
};

IntlPhone::IntlPhone(int _country, int _areaCode, int _number) 
   :Phone(_areaCode,_number), country(_country) 
{ 
}
void IntlPhone::set(int  _country,int  _areaCode,int  _number) 
{ 
    country = _country; 
    Phone::set(_areaCode, _number); 
}
void IntlPhone::get(int& _country,int& _areaCode,int& _number) const 
{ 
    _country = country;  
    Phone::get(_areaCode, _number); 
}
bool IntlPhone::isValid() 
{ 
    return rangeValid(country, 1,999) && Phone::isValid(); 
}
void IntlPhone::display(std::ostream& s) const 
{ 
    s.width(2); 
    s << country << '-'; Phone::display(s); 
}


std::istream& operator>>(std::istream& stream, IntlPhone& p)       // reads p from stream
{
    int c, ac, n;
    stream >> c >> ac >> n;
    p.set(c,ac,n);
    return stream;
}


std::ostream& operator<<(std::ostream& stream, const IntlPhone& p) // writes p to stream
{
    p.display(stream);
    return stream;
}
