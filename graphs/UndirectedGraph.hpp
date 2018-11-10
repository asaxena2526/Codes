#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include <iostream>


/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph {		
 	public:

  	/*
   	* Constructor: UndirectedGraph
   	*
   	* Parameters: mode
   	* Used to decide which representation to use
   	* 'm' for AdjacencyMatrix
   	* 'l' for AdjacencyList
   	*/
  	UndirectedGraph(int numVertices, char rep):AbstractGraph(numVertices,rep)
    {

    }
  	/*
  	* Destructor
  	*/
  	~UndirectedGraph();
  virtual int edges()
  {
      return this->base->edges()/2;
  }  
  	
	};
	
#endif /* ifndef UNDIRECTED_GRAPH */
