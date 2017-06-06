#include<iostream>
using namespace std;

void BubbleSort(int *arr,int n)
{
	int i,j,temp;
	bool finish=false;
	for(i=0;i<n-1&&!finish;i++)
	   for(j=0;j<n-i-1;j++)
	   	   if(arr[j]>arr[j+1])
	   	   {
	   	   	    temp=arr[j];
	   	   		arr[j]=arr[j+1];
	   	   		arr[j+1]=temp;
	   	   		finish=false;
		   }
}

int main()
{
	int a[]={46,31,6,19,23,31};
	BubbleSort(a,6);
	for(int i=0;i<6;i++)
	    cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
