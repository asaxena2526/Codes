#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include <iostream>
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "queue.hpp"
//#include "GraphAdjacencyBase.hpp"
using namespace std;

/*
* A class to represent a directed graph.
*/
class DirectedGraph : public AbstractGraph {
	
	char mode;
	int Vertices;
	GraphAdjacencyBase *base;
		
	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep)
	{
		mode=rep;
		Vertices=numVertices;
		if(mode=='m')
		{
			// AdjacencyMatrix M(Vertices);
			base=new AdjacencyMatrix(Vertices);
		}
  		else
  		{
  			// AdjacencyList M(Vertices);	
  			base=new AdjacencyList(Vertices);
  		}

	}
	/*
	 * Destructor
	 */
	//~DirectedGraph();


  virtual bool edgeExists(int i, int j)
  {
  		return base->edgeExists(i,j);
  }
  
  virtual int edges()
  {
  		return base->edges();
  }
 
  virtual int vertices()
  {
  	return Vertices;
  }
 
  virtual void add(int i, int j)
  {
  	//cout<<"a1 "<<endl;
  		base->addi(i,j);
  }
  
  virtual void remove(int i, int j)
  {
  		base->remove(i,j);
  }
  
  virtual void dfs(int start)
  {
  	int colour[Vertices],visited[Vertices],ans[Vertices];
  	for(int i=0;i<Vertices;i++)
  	{
  		colour[i]=-1;
  		visited[i]=0;
  	}
  	visited[start]=1;
  	ans[0]=start;
  	colour[start]=0;
  	int pos=1;
  	DFS(start,visited,colour,ans,pos);
  	colour[start]=1;
  	for(int i=0;i<Vertices;i++)
  	{
  		if(visited[i]==0)
  		{
  			colour[i]=0;
  			visited[i]=1;
  			ans[pos]=i;
  			pos++;
  			DFS(i,visited,colour,ans,pos);
  		}
  	}
  	for (int i = 0; i < Vertices; i++)
  	{
  		cout<<ans[i]<<" ";
  	}
  	cout<<endl;
  }
  void DFS(int start,int visited[],int colour[],int ans[],int& pos)
		{
				for(int i=0;i<Vertices;i++)
				{
					if(base->edgeExists(start,i)!=0 && visited[i]==0)
					{
						visited[i]=1;
						colour[i]=0;
						ans[pos]=i;
						pos++;
						DFS(i,visited,colour,ans,pos);
						colour[i]=1;
					}
				}
		}
  
  virtual void bfs(int start)
  {
    int colour[Vertices],visited[Vertices],ans[Vertices],level[Vertices];
    for(int i=0;i<Vertices;i++)
    {
      colour[i]=0;
      visited[i]=0;
      level[i]=0;
    }
    Queue Q;
    visited[start]=1;
    //ans[0]=start;
    int pos=0;
    colour[start]=1;
    Q.enqueue(start);
    A:
    while(Q.queue_length()!=0)
    {
      int t=Q.dequeue();
      ans[pos]=t;
      pos++;
      for(int i=0;i<Vertices;i++)
      {
        if(base->edgeExists(t,i)!=0 && visited[i]==0)
        {
            visited[i]=1;
            //colour[i]=0;
            
            Q.enqueue(i);
            colour[i]=1;
        }
      }
    }
    for (int i = 0; i < Vertices; i++)
    {
      if(visited[i]==0)
      { 
        visited[i]=1;
        Q.enqueue(i);
        colour[i]=1; 
        goto A;

      }
    }
    for (int i = 0; i < Vertices; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<endl;

  }
		
};

#endif /* ifndef DIRECTED_GRAPH */
