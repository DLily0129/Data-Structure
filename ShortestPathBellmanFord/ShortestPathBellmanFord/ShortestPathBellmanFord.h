#include "AdjMatrixDirNetwork.h"
using namespace std;

void ShortestPathBellmanFord(AdjMatrixDirNetwork &network,int startVex=0)
{
	int *dist,*path,*distTemp,i,j,k;
	int vexNum=network.GetVexNum(),infinity=network.GetInfinity();
	dist=new int[vexNum];
	path=new int[vexNum];
	distTemp=new int[vexNum];
	for(i=0;i<vexNum;i++)     //初始化
	{
		dist[i]=(i!=startVex)?network.GetWeight(startVex,i):0;
		if(dist[i]==0||dist[i]==infinity)
			path[i]=-1;
		else
			path[i]=startVex;
	}
	for(i=2;i<=vexNum-1;i++)   //dist(2)到dist(n-1)
	{
		for(j=0;j<vexNum;j++)
			distTemp[j]=dist[j];
		for(j=0;j<vexNum;j++)
			if(j!=startVex)
				for(k=network.FirstAdjVex(j);k!=-1;k=network.NextAdjVex(j,k))
					if(distTemp[j]+network.GetWeight(j,k)<dist[k])
					{
						dist[k]=distTemp[j]+network.GetWeight(j,k);
						path[k]=j;
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
	delete[] distTemp;
}