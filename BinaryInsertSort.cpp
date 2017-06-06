#include<iostream>
using namespace std;

void BinaryInsertSort(int *arr,int n)
{
	int i,j,temp,low,high,mid;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		low=0;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(arr[mid]==temp)
			    break;
			else if(arr[mid]<temp)
				low=mid+1;
			else
				high=mid-1;
		}
		if(low<=high)
		{
			for(j=i-1;j>=mid+1;j--)
				arr[j+1]=arr[j];
			arr[mid+1]=temp;		
		}
		else
		{
			for(j=i-1;j>=low;j--)
				arr[j+1]=arr[j];
			arr[low]=temp;			
		}
	}
}

int main()
{
	int a[]={23,31,49,31,6,19};
	BinaryInsertSort(a,6);
	for(int i=0;i<6;i++)
	    cout<<a[i]<<" ";
	cout<<endl;			
	return 0;
}
