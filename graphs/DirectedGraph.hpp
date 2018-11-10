#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include <iostream>

/*
* A class to represent a directed graph.
*/
class DirectedGraph : public AbstractGraph {
	
	// 
		
	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep): AbstractGraph(numVertices,rep)
	{
		
	}
	/*
	 * Destructor
	 */
	~DirectedGraph() {};
  virtual int edges()
  {
  		return this->base->edges();
  }		
};

#endif /* ifndef DIRECTED_GRAPH */
