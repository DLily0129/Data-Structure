#include "AdjMatrixDirNetwork.h"
#include <iostream>
using namespace std;

void ShortestPathDijkstra(AdjMatrixDirNetwork &network,int startVex)
{
	int vexNum=network.GetVexNum(),*dist,*path;
	int	i,j,infinity=network.GetInfinity(),min,minOrder;
	dist=new int[vexNum];
	path=new int[vexNum];
	network.SetTag(startVex,VISIT);
	for(i=0;i<vexNum;i++)    //初始化
	{
		if(i!=startVex)
		{
			dist[i]=network.GetWeight(startVex,i);
		    if(dist[i]==infinity)
				path[i]=-1;
			else
				path[i]=startVex;
		}
		else
		{
			dist[i]=0;
			path[i]=-1;
		}
	}
	for(i=1;i<vexNum;i++)   //循环n-1次，找出以startvex为起点，其他n-1个顶点为终点的最短路径
	{
		 min=infinity;
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&dist[j]<min)
			 {
				 min=dist[j];
				 minOrder=j;
			 }
		 }
		 network.SetTag(minOrder,VISIT);
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&(min+network.GetWeight(minOrder,j)<dist[j]))
			 {
				 dist[j]=min+network.GetWeight(minOrder,j);
				 path[j]=minOrder;
			 }
		 }
	}
	for(i=0;i<vexNum;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	for(i=0;i<vexNum;i++)
		cout<<path[i]<<" ";
	cout<<endl;
	for(i=0;i<vexNum;i++)
	{
		if(i!=startVex)
		{
			cout<<"从起点"<<network.GetElem(startVex)<<"到终点"<<network.GetElem(i)<<"的最短路径长度为:"<<dist[i];
			cout<<"  最短路径为:"<<network.GetElem(i);
			j=i;
			while(path[j]!=-1)
			{
				j=path[j];
				cout<<"<-"<<network.GetElem(j);
			}
			cout<<endl;
		}
	}
	delete[] dist;
	delete[] path;
}