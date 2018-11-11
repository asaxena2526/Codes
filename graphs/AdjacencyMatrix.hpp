#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include <iostream>
using namespace std;
/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {
	
	int size;
	int **Mat;

	public:
		AdjacencyMatrix(int vertices)
		{
			size=vertices;
			Mat=new int*[size];
			for (int i = 0; i < size; i++)
			{
				Mat[i]=new int[size];
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					Mat[i][j]=0;
				}
			}
		}
		~AdjacencyMatrix()
		{
			delete Mat;
		}

		bool edgeExists(int i,int j)
		{
			// cout<<"am"<<Mat[i][j]<<endl;
			return Mat[i][j];
		}
		int vertices()
		{
			return size;
		}
		int edges()
		{
			int e=0;
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					if(Mat[i][j]!=0)
						e++;
				}
			}
			return e;
		}
		int Weight(int i, int j)
		{
			return Mat[i][j];
		}
		virtual void add(int i, int j,int w=1)
		{
			// cout<<"a2 "<<endl;
			Mat[i][j]=w;
		}
		void remove(int i, int j)
		{
			Mat[i][j]=0;
		}
		int degree(int i)
		{
			int d=0;
			for(int j=0;j<size;j++)
			{
				if(Mat[i][j]!=0)
					d++;
			}
			return d;
		}
};

#endif /* ifndef ADJACENCY_MATRIX */
