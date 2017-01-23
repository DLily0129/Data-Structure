#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include"linklist.h"
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

struct PolyItem
{
	int coef;
	int expn;

	PolyItem():coef(0),expn(0) {}

	PolyItem(int _coef,int _expn):coef(_coef),expn(_expn) {}
};


class Polynomial
{
protected:
	LinkList<PolyItem> polyList;

public:
	Polynomial();
	Polynomial(const LinkList<PolyItem> &p);
	~Polynomial();
	void Display() const;
	friend ostream & operator<<(ostream &out,Polynomial &p);
	Polynomial operator+ (const Polynomial &other) const;
	Polynomial operator- (const Polynomial &other) const;
	Polynomial operator* (const Polynomial &other) const;
};
#endif