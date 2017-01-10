#include"SeqList.h"
#include<iostream>
using std::cout;
using std::endl;

void Print(const int &n)
{
	printf("%d ",n);
}

int main()
{
	int data[10]={1,2,3,4,5,6,7,8},k,m=10;
	
	SeqList<int> SL(data,5),SL2(SL),SL3(data,8);
	
	SL2.Traverse(Print);
	cout<<endl;

	cout<<SL.GetLength()<<endl;
	SL.Traverse(Print);
	cout<<endl;

	SL.GetElem(2,k);
	cout<<k<<endl;

	SL.InsertElem(3,m);
	cout<<SL.GetLength()<<endl;
	SL.Traverse(Print);
	cout<<endl;

	SL.DeleteElem(2,k);
	cout<<SL.GetLength()<<endl;
	SL.Traverse(Print);
	cout<<endl;

	SL2=SL3;
	SL2.Traverse(Print);
	cout<<endl;
	return 0;
}