#include"Polynomial.h"

int main()
{
	PolyItem items[4]={PolyItem(5,4),PolyItem(3,3),PolyItem(1,1),PolyItem(1,0)};
	PolyItem items2[3]={PolyItem(6,5),PolyItem(2,2),PolyItem(2,1)};

	LinkList<PolyItem> la(items,4);
	LinkList<PolyItem> lb(items2,3);

	Polynomial poly(la);
	Polynomial poly2(lb);
	Polynomial re,re2,re3;

	cout<<poly<<endl;
	cout<<poly2<<endl;

	re=poly+poly2;
	re2=poly-poly2;
	re3=poly*poly2;

	cout<<re<<endl;
	cout<<re2<<endl;
	cout<<re3<<endl;
	return 0;
}