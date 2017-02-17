#ifndef TRI_SPARSE_MATRIX_H
#define TRI_SPARSE_MATRIX_H
#include<iostream>
#include<iomanip>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::left;

template <typename ElemType>
struct Triple
{
	int row,col;
	ElemType value;

	Triple() 
	{
	}
	Triple(int r,int c,const ElemType &e):row(r),col(c),value(e) {}
};

template <typename ElemType>
class TriSparseMatrix
{
protected:
	Triple<ElemType> *triElems;
	int rows,cols,num;

public:
	TriSparseMatrix();   //默认构造一个空矩阵
	TriSparseMatrix(int _rows,int _cols,int _num);
	TriSparseMatrix(int _rows,int _cols,int _num,const Triple<ElemType> *t);
	TriSparseMatrix(const TriSparseMatrix &copy);  //深拷贝
	TriSparseMatrix & operator=(const TriSparseMatrix &other);  //深赋值
	~TriSparseMatrix();
	void SimpleTranspose(TriSparseMatrix &dest);   //转置的普通算法
	void FastTranspose(TriSparseMatrix &dest);    //转置的快速算法
	template <typename ElemType>
	friend ostream & operator<<(ostream &out,const TriSparseMatrix<ElemType> &mat);
	
};

template <typename ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix()
{
	rows=0;
	cols=0;
	num=0;
	triElems=NULL;
}

template <typename ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int _rows,int _cols,int _num)
{
	rows=_rows;
	cols=_cols;
	num=_num;
	triElems=new Triple<ElemType>[num];
	for(int i=0;i<num;i++)
	{
		cout<<"请输入row，col，value:";
		cin>>triElems[i].row>>triElems[i].col>>triElems[i].value;
	}
}

template <typename ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int _rows,int _cols,int _num,const Triple<ElemType> *t)
{
	rows=_rows;
	cols=_cols;
	num=_num;
	triElems=new Triple<ElemType>[num];
	for(int i=0;i<num;i++)
		triElems[i]=t[i];
}

template <typename ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix()
{
	if(triElems!=NULL)
		delete[] triElems;
}

template <typename ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix &copy)
{
	rows=copy.rows;
	cols=copy.cols;
	num=copy.num;
	triElems=new Triple<ElemType>[num];
	for(int i=0;i<num;i++)
		triElems[i]=copy.triElems[i];
}

template <typename ElemType>
TriSparseMatrix<ElemType> & TriSparseMatrix<ElemType>::operator=(const TriSparseMatrix<ElemType> &other)
{
	if(&other==this)
		return *this;
	if(triElems!=NULL)
		delete[] triElems;
	rows=other.rows;
	cols=other.cols;
	num=other.num;
	triElems=new Triple<ElemType>[num];
	for(int i=0;i<num;i++)
		triElems[i]=other.triElems[i];
	return *this;
}

template <typename ElemType>
void TriSparseMatrix<ElemType>::SimpleTranspose(TriSparseMatrix &dest)
{
	if(dest.triElems!=NULL)
		delete[] dest.triElems;
	dest.rows=cols;
	dest.cols=rows;
	dest.num=num;
	dest.triElems=new Triple<ElemType>[num];
	int c=0;
	for(int i=0;i<cols;i++)
		for(int j=0;j<num;j++)
			if(triElems[j].col==i)
			{
				dest.triElems[c].row=triElems[j].col;
				dest.triElems[c].col=triElems[j].row;
				dest.triElems[c].value=triElems[j].value;
				c++;
			}
}

template <typename ElemType>
void TriSparseMatrix<ElemType>::FastTranspose(TriSparseMatrix &dest)
{
	if(dest.triElems!=NULL)
		delete[] dest.triElems;
	dest.rows=cols;
	dest.cols=rows;
	dest.num=num;
	dest.triElems=new Triple<ElemType>[num];
	int *cNum,*cPos,i,j;
	cNum=new int[cols];
	cPos=new int[cols];
	for(i=0;i<cols;i++)
		cNum[i]=0;
	for(i=0;i<num;i++)
		cNum[triElems[i].col]++;
	cPos[0]=0;
	for(i=1;i<cols;i++)
		cPos[i]=cPos[i-1]+cNum[i-1];
	for(i=0;i<num;i++)
	{
		j=cPos[triElems[i].col];
		dest.triElems[j].row=triElems[i].col;
		dest.triElems[j].col=triElems[i].row;
		dest.triElems[j].value=triElems[i].value;
		cPos[triElems[i].col]++;
	} 
	delete[] cNum;
	delete[] cPos;
}

template <typename ElemType>
ostream & operator<<(ostream &out,const TriSparseMatrix<ElemType> &mat)
{
	int c=0;
	for(int i=0;i<mat.rows;i++)
	{
		cout<<"[  ";
		for(int j=0;j<mat.cols;j++)
		{
			if(mat.triElems[c].row==i&&mat.triElems[c].col==j)
					cout<<left<<setw(3)<<mat.triElems[c++].value;
			else 
				cout<<left<<setw(3)<<"0";
		}
		cout<<"]"<<endl;
	}
	return out;
}
#endif