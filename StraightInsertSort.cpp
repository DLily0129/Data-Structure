#include<iostream>
using namespace std;

void StraightInsertSort(int *arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0&&temp<arr[j];j--)
		    arr[j+1]=arr[j];
		arr[j+1]=temp;
	}
}

int main()
{
	int a[]={23,31,49,31,6,19};
	StraightInsertSort(a,6);
	for(int i=0;i<6;i++)
	    cout<<a[i]<<" ";
	cout<<endl;		
	return 0;
}
