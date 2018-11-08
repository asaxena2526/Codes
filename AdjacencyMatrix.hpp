#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

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
			Mat=new int*[size]
			for (int i = 0; i < size; i++)
			{
				Mat[i]=new int[size];
			}
		}
		~AdjacencyMatrix();

};

#endif /* ifndef ADJACENCY_MATRIX */
