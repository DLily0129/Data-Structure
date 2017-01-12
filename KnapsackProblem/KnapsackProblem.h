#ifndef KNAPSPACK_PROBLEM_H
#define KNAPSPACK_PROBLEM_H
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void KnapspackProblem(int n,int *weight,int *value,int capacity)  //输入共几件物品，它们的重量，价值，以及背包的容量
{
	int **p=new int*[n],i,j;
	for(i=0;i<n;i++)
        p[i]=new int[capacity+1];
	for(i=0;i<weight[0];i++)   //先填表格第一行
		p[0][i]=0;
	for(i=weight[0];i<capacity+1;i++)   //先填表格第一行
		p[0][i]=value[0];
	for(i=1;i<n;i++)              //再处理后面几行
		for(j=0;j<capacity+1;j++)
		{
			if(j<weight[i])
				p[i][j]=p[i-1][j];
			else
			{
				if((p[i-1][j-weight[i]]+value[i])>p[i-1][j])
					p[i][j]=p[i-1][j-weight[i]]+value[i];
				else
					p[i][j]=p[i-1][j];
			}
		}
		cout<<"放入的最大价值为:"<<p[n-1][capacity]<<endl;   //该算法的时间复杂度为O(n*capacity)
		for(i=0;i<n;i++)
			delete[] p[i];
		delete[] p;
}

#endif