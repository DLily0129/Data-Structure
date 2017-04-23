#include "AdjMatrixUndirNetWork.h"

int main()
{
	char vexs[7]="ABCDEF";
	AdjMatrixUndirNetwork network(vexs,6);

	network.InsertArc(0,1,34);
	network.InsertArc(0,2,46);
	network.InsertArc(0,5,19);
	network.InsertArc(2,5,25);
	network.InsertArc(1,4,12);
	network.InsertArc(5,4,26);
	network.InsertArc(5,3,25);
	network.InsertArc(2,3,17);
	network.InsertArc(3,4,38);
	network.Display();
	cout<<network.NextAdjVex(1,4)<<endl;

	return 0;
}