#include"TriSparseMatrix.h"

int main()
{
    int rows,cols,num;
	cout<<"请输入矩阵的行数，列数以及非零元个数:";
	cin>>rows>>cols>>num;
	TriSparseMatrix<int> Mat(rows,cols,num),mat2;
	Mat.FastTranspose(mat2);
	cout<<Mat<<endl;
	cout<<mat2;
	return 0;
}