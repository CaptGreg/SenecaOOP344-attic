// http://www.dreamincode.net/forums/topic/234775-creating-a-recursive-descent-parser-oop-style/

#pragma once

#include <istream>
#include <deque>
#include <exception>

//pre-declare are classes so they can be used in a non-discriminate order
class Production;
class Expr;
class Term;
class Unary;
class Number;
class Factor;
class ParseError;

/**
* the base class for all of our productions
*/
class Production {
public:
	virtual ~Production(); //does nothing, if we don't need to override it we don't want to
	virtual double getValue()=0; //pure virtual, all children MUST implmnet this function
};

/**
* a simple class to handle parsing errors
*/
class ParseError : public std::exception {
	const char* what() const throw();
};

/**
* a class to parse a number from the input stream
*/
class Number : public Production {
private:
	double value;
public:
	Number(std::istream& in);
	///Override
	double getValue();
};
/**
* a class to parse a factor from the input stream
*/
class Factor : public Production {
private:
	Production* expr; //we need to use a Production pointer in order handle the dual behavoir of factors
public:
	Factor(std::istream& in);
	///Override
	~Factor();
	///Override
	double getValue();
};
/**
* a class to parse unary operators and operands from an input stream
*/
class Unary : public Production {
private:
	int sign;
	Factor* value;
public:
	Unary(std::istream& in);
	///Override
	~Unary();
	///Override
	double getValue();
};
/**
* a class to parse binary operators(* and /) and operands from the input stream
*/
class Term : public Production {
private:
	std::deque<Unary*> values;
	std::deque<char> ops;
public:
	Term(std::istream& in);
	///Override
	~Term();
	///Override
	double getValue();
};

/**
* a class to parse binary operators(+ and -) and operands from the input stream, acts as the full expreison parser becuase + and - have the lowest precdence.
* this code works just like Term only it uses the + and - operators instead.
*/
class Expr : public Production {
private:
	std::deque<Term*> values;
	std::deque<char> ops;
public:
	Expr(std::istream& in);
	///Override
	~Expr();
	///Override
	double getValue();
};
