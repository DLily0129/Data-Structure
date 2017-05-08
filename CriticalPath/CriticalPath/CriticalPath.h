#include "AdjListDirNetwork.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void CriticalPath(AdjListDirNetwork &network)
{
     int vexNum=network.GetVexNum();
	 int *indegree=new int[vexNum];
	 int *ve=new int[vexNum];
	 int *vl=new int[vexNum];
	 int i,j;
	 queue<int> q;
	 stack<int> s;
	 network.GetVexsIndgree(indegree);
	 for(i=0;i<vexNum;i++)
		 ve[i]=0;
	 for(i=0;i<vexNum;i++)
		 if(indegree[i]==0)
			q.push(i);
	 while(!q.empty())
	 {
		 i=q.front();
		 s.push(i);
		 q.pop();
		 for(j=network.GetFirstAdjVex(i);j!=-1;j=network.GetNextAdjVex(i,j))
		 {
			 if(--indegree[j]==0)
				 q.push(j);
			 if(ve[i]+network.GetWeight(i,j)>ve[j])
				 ve[j]=ve[i]+network.GetWeight(i,j);
		 }
	 }
	 i=s.top();
	 s.pop();
	 for(j=0;j<vexNum;j++)
		 vl[j]=ve[i];
	 while(!s.empty())
	 {
		 i=s.top();
		 s.pop();
		 for(j=network.GetFirstAdjVex(i);j!=-1;j=network.GetNextAdjVex(i,j))
			 if(vl[j]-network.GetWeight(i,j)<vl[i])
				 vl[i]=vl[j]-network.GetWeight(i,j);
	 }
	 for(i=0;i<vexNum;i++)
		 cout<<ve[i]<<" ";
	 cout<<endl;
	 for(i=0;i<vexNum;i++)
		 cout<<vl[i]<<" ";
	 cout<<endl<<"关键活动有:";
	 for(i=0;i<vexNum;i++)
	 {
		 int ee,el;
		 ee=ve[i];
		 for(j=network.GetFirstAdjVex(i);j!=-1;j=network.GetNextAdjVex(i,j))
		 {
			 el=vl[j]-network.GetWeight(i,j);
			 if(ee==el)
			 {
				 char v1=network.GetElem(i),v2=network.GetElem(j);
				 cout<<"("<<v1<<","<<v2<<") ";        //输出关键活动
			 }
		 }
	 }
	 cout<<endl;
	 delete[] indegree;
	 delete[] ve;
	 delete[] vl;
}
