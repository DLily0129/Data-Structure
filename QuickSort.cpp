#include<iostream>
using namespace std;

void QuickSort(int *arr,int low,int high)
{
	int i=low,j=high;
	int temp=arr[low];
	while(i<j)
	{
		for(;i<j&&arr[j]>=temp;j--);
		if(i<j)
			arr[i++]=arr[j];
		for(;i<j&&arr[i]<=temp;i++);
		if(i<j)
			arr[j--]=arr[i];
	}
	arr[i]=temp;
	if(i-1>low)
	    QuickSort(arr,low,i-1);
	if(j+1<high)
		QuickSort(arr,j+1,high);
}

int main()
{
	int a[]={23,31,49,31,6,19};
	QuickSort(a,0,5);
	for(int i=0;i<6;i++)
	    cout<<a[i]<<" ";
	cout<<endl;		
	return 0;
}
