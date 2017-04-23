#include "AdjMatrixDirNetwork.h"

int main()
{
	char vexs[]="ABCDE";
	AdjMatrixDirNetwork network(vexs,5,5);

	network.InsertArc(0,1,10);
	network.InsertArc(0,4,100);
	network.InsertArc(0,3,30);
	network.InsertArc(1,2,50);
	network.InsertArc(2,4,10);
	network.InsertArc(3,2,20);
	network.InsertArc(3,4,60);

	network.Display();
	return 0;
}