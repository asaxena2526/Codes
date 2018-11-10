#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 1
// #include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

/*
 * An interface to represent any type of Graph
 */
class AbstractGraph {

protected:
  char mode;
  int Vertices;
  GraphAdjacencyBase *base;

 public:

  AbstractGraph(int numVertices,char rep)
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
  /* Destructor:
   * releases all resources acquired by the class
   */

  virtual ~AbstractGraph() 
  {
    delete base;
  }
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExists(int i, int j)
  {
    return base->edgeExists(i,j);
  }
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges() = 0;
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  virtual int vertices()
  {
    return Vertices;
  }
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  virtual void add(int i, int j)
  {
    base->add(i,j);
  }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j)
  {
      base->remove(i,j);
  }
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
 // virtual void dfs(void (*work)(int&)) = 0;
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
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
 // virtual void bfs(void (*work)(int&)) = 0;
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

#endif /* ifndef ABSTRACT_GRAPH */
