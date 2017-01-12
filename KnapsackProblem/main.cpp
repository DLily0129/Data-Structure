#include"KnapsackProblem.h"

int main()
{
	int n,*w,*v,c,i;
	cout<<"请输入物品数量:";
	cin>>n;
	w=new int[n];
	v=new int[n];
	cout<<"请输入各个物品的重量:";
	for(i=0;i<n;i++)
		cin>>w[i];
	cout<<"请输入对应物品的价值:";
	for(i=0;i<n;i++)
		cin>>v[i];
	cout<<"请输入背包的最大容量:";
	    cin>>c;
	KnapspackProblem(n,w,v,c);
	delete[] w;
	delete[] v;
	return 0;
}