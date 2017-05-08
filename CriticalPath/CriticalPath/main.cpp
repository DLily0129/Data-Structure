#include "CriticalPath.h"

int main()
{
	char vexs[]="ABCDEFG";
	AdjListDirNetwork network(vexs,7,7);

	network.InsertArc(0,3,6);
	network.InsertArc(0,2,2);
	network.InsertArc(0,1,3);
	network.InsertArc(1,4,4);
	network.InsertArc(1,3,2);
	network.InsertArc(2,5,3);
	network.InsertArc(2,3,1);
	network.InsertArc(3,4,1);
	network.InsertArc(4,6,3);
	network.InsertArc(5,6,4);

	network.Show();
	CriticalPath(network);
}