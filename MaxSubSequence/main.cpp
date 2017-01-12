#include"MaxSubSeq.h"

int main()
{
	int n,*a,i;
	cout<<"请输入数的个数n:";
	cin>>n;
	a=new int[n];
	cout<<"请输入序列:";
	for(i=0;i<n;i++)
		cin>>a[i];
	MaxSubSeq_1(n,a);
	MaxSubSeq_2(n,a);
	delete[] a;
	return 0;
}