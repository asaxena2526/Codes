#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG 1

#include <iostream>
using namespace std;
/*
 * A base class which can denote any Graph Adjacency representation.
 * Subclassed by AdjacencyMatrix and AdjacencyList
 * Use this class in your graphs to be able to select any representation as desired by the user.
 */
class GraphAdjacencyBase {

	public:	
	
	/* Destructor:
	 * releases all resources acquired by the class
	 */
 // virtual ~GraphAdjacencyBase() {};
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */

		virtual int Weight(int i,int j)=0;
  virtual bool edgeExists(int i, int j) = 0;
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  virtual int vertices() = 0;
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  virtual int edges() = 0;
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  virtual void add(int i, int j,int w=1)
  {
  //	cout<<"a5 "<<endl;
  }
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  virtual void remove(int i, int j) = 0;
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  virtual int degree(int i) = 0;
};

#endif /* ifndef GRAPH_ADJACENCY_BAG */
