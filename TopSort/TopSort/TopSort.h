#include "AdjListDirGraph.h"

void TopSort(AdjListDirGraph &graph)  //入度为0的结点用栈来存放，使用静态链栈的方法可以不用再开辟空间
{
	int vexNum=graph.GetVexNum(),top=-1,i,count=0;   //top为栈顶指针，count记录输出的顶点个数
	int *indgree=new int[vexNum];
	graph.GetVexsIndgree(indgree);
	for(i=0;i<vexNum;i++)
		if(indgree[i]==0)    //入度为0的顶点入栈
		{
			indgree[i]=top;
			top=i;
		}
	cout<<"拓扑序列为:";
	while(top!=-1)   //若栈非空
	{
		cout<<graph.GetElem(top);
		count++;
		int v=top;
		top=indgree[top];    //出栈
		for(i=graph.GetFirstAdjVex(v);i!=-1;i=graph.GetNextAdjVex(v,i))
			if(--indgree[i]==0)
			{
				indgree[i]=top;
				top=i;
			}
	}
	cout<<endl;
	if(count<vexNum)
		cout<<"拓扑排序失败，该图有有向环！";
	else
		cout<<"拓扑排序成功！";
	cout<<endl;
	delete[] indgree;
}