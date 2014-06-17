template <class T>
class X
{
	T t1;
public:
	T t();
	void t(T t);
};

template<class T>
T X<T>::t() {return t1;}

template<class T>
void X<T>::t(T t) { this->t1 = t;}
