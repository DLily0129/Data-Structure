#include"TriSparseMatrix.h"

int main()
{
	Triple<int> tri[9]={Triple<int>(0,0,15),Triple<int>(0,3,22),Triple<int>(0,5,-5),
	Triple<int>(1,1,11),Triple<int>(1,2,3),Triple<int>(2,3,6),Triple<int>(4,0,91),
	Triple<int>(5,1,7),Triple<int>(6,2,28)};
	TriSparseMatrix<int> Mat(7,6,9,tri),mat2;
	Mat.FastTranspose(mat2);
	cout<<Mat<<endl;
	cout<<mat2;

	return 0;
}