#ifndef MAX_SUB_SEQ     //最大子列和问题
#define MAX_SUB_SEQ
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void MaxSubSeq_1(int n,int *Seq)   //法一，算出了所有子列的和，找出最大值，好理解，但算法时间复杂度为O(n^2)
{
	int i,j,MaxSum=0,sum=0;
	for(i=0;i<n;i++)     //判断是否为全负
       if(Seq[i]>=0)   
			break;
	if(i==n)   //上个循环正常退出，考虑序列为全负的情况
	{
		MaxSum=Seq[0];
		for(i=1;i<n;i++)
            if(Seq[i]>MaxSum)
				MaxSum=Seq[i];
        cout<<"最大子列和为:"<<MaxSum<<endl;   //最大子列和即为最大的那个负数
	}
	else
	{
	   for(i=0;i<n;i++)     //从第0位到第n-1位，即子列的头元素
	   {
		   for(j=i;j<n;j++)    //j=i，从第i位开始，即子列的尾元素，头固定，尾每次向后移动一位
		   {
			   sum=sum+Seq[j];   //计算子列和
			   if(sum>MaxSum)    //如果大于MaxSum
				   MaxSum=sum;   //更新MaxSum
		   }
		   sum=0;
	    }
	cout<<"最大子列和为:"<<MaxSum<<endl;
	}
}

void MaxSubSeq_2(int n,int *Seq)   //法二(联机算法或在线处理)，不易理解，但算法时间复杂度为O(n)，为最快的算法
{
	int i,j,MaxSum=0,sum=0;   //MaxSum为最大子列和，sum为当前子列和
	
	for(i=0;i<n;i++)     //判断是否为全负
       if(Seq[i]>=0)
			break;
	if(i==n)   //上个循环正常退出，考虑序列为全负的情况
	{
		MaxSum=Seq[0];
		for(i=1;i<n;i++)
            if(Seq[i]>MaxSum)
				MaxSum=Seq[i];
        cout<<"最大子列和为:"<<MaxSum<<endl;   //最大子列和即为最大的那个负数
	}
	
	else   //不为全负的情况
	{
		for(i=0;i<n;i++)
		{
		     sum=sum+Seq[i];   //从头开始扫描，并累加
			 if(sum<=0)   //如果当前子列和为负数，不可能使后面的部分和更大，所以没有存在意义
				 sum=0;    //当前子列和清零，开始下一项
			 else
			 {
				 if(sum>MaxSum)  //如果sum大于MaxSum
					MaxSum=sum;    //更新MaxSum,此时不改变sum,继续累加
			 }
		}
		cout<<"最大子列和为:"<<MaxSum<<endl; 
	}
}
#endif