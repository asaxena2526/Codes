#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 1
// #include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "queue.hpp"
#include "priorityQ.hpp"
#include <iostream>
#define inf 2147483647
#define weight 1
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
    
  }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j)
  {
      
  }
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
 // virtual void dfs(void (*work)(int&)) = 0;
  virtual int dfs(int start,int a[],int ans[])
  {
    int colour[Vertices],visited[Vertices];
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
    int k=0;
    a[k]=pos;
    k++;
    for(int i=0;i<Vertices;i++)
    {
      if(visited[i]==0)
      {
        colour[i]=0;
        visited[i]=1;
        ans[pos]=i;
        pos++;
        DFS(i,visited,colour,ans,pos);
        a[k]=pos;
        k++;
      }
    }
    return k;
    // for (int i = 0; i < Vertices; i++)
    // {
    //   cout<<ans[i]<<" ";
    // }
    // cout<<endl;
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
    Queue<int> Q;
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
   virtual int Modifiedbfs(int start,char c[][5],int column)
  {
    int colour[Vertices],visited[Vertices],ans[Vertices],level[Vertices];
    for(int i=0;i<Vertices;i++)
    {
      colour[i]=0;
      visited[i]=0;
      level[i]=-1;
    }
    Queue<int> Q;
    visited[start]=1;
    level[start]=0;
    //ans[0]=start;
    int pos=0;
    colour[start]=1;
    Q.enqueue(start);
    A:
    while(Q.queue_length()!=0)
    {
      int t=Q.dequeue();
      // if(start==3)
       // cout<<"sss "<<start<<" "<<t<<" "<<t/column<<" "<<t%column<<endl;
      if(c[t/column][t%column]=='G')
        return level[t];
      if(c[t/column][t%column]=='W')
        continue;
      ans[pos]=t;
      pos++;
      for(int i=0;i<Vertices;i++)
      {
        if(base->edgeExists(t,i)!=0 && visited[i]==0)
        {
            visited[i]=1;
            //colour[i]=0;
            
            Q.enqueue(i);
            level[i]=level[t]+1;
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
  int Dijkstra(int source,int destination,int p[])
  {
    PriorityQ Q(Vertices);
    int sd[Vertices];
    int temp[2];
    for (int i = 0; i < Vertices; i++)
    {
      Q.insert(i,inf);
      sd[i]=inf;
      // indicies[i]=i;
      //visited[i]=0;
    }
    Q.insert(source,0);
    Q.makeHeap(0,Vertices-1);
    // cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
    
    while(Q.get_length()!=0)
    {
      // cout<<"sss"<<endl;
      // cout<<"a "<<indicies[0]<<" "<<distances[0]<<endl;
      Q.ExtractMin(temp);
    //    cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
      sd[temp[1]]=temp[0];
     // visited[temp[1]]=1;
      // cout<<"b "<<temp[1]<<" "<<temp[0]<<endl;
      //cout<<"c "<<base->edgeExists(2,0)<<endl;
      if(temp[1]==destination)
      {
        // cout<<"ss"<<sd[3]<<endl;
        if(sd[destination]==inf || sd[destination]<0)
        {
          // cout<<"ss"<<endl;
          return -1;
        }
        return sd[destination];
      }
      for(int i=0;i<Vertices;i++)
      {
        if(base->edgeExists(temp[1],i))
        {
          int b=Q.search(i);
          if(b==-1)
            continue;
          // cout<<i<<" "<<b<<" "<<distances[b]<<" "<<sd[temp[1]]+weight<<endl;
          if(Q.value(b)>sd[temp[1]]+weight)
          {
            // cout<<"if in\n";
            Q.DecreaseKey(b,sd[temp[1]]+weight);
            p[i]=temp[1];
          }
          // cout<<distances[i]
    //       cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
        }
      }
    }


  }
  void prims(int source,int tree[],int p[])
  {
  PriorityQ Q(Vertices);
    //int sd[Vertices];
    int temp[2];
    for (int i = 0; i < Vertices; i++)
    {
      Q.insert(i,inf);
      //visited[i]=0;
      p[i]=-1;
    }
    Q.insert(source,0);
    Q.makeHeap(0,Vertices-1);
    // cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
    int pos=0;
    //p[0]=-1;
    while(Q.get_length()!=0)
    {
      // cout<<"a "<<indicies[0]<<" "<<distances[0]<<endl;
      Q.ExtractMin(temp);
    //    cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
      tree[pos]=temp[1];

      pos++;
     // visited[temp[1]]=1;
      // cout<<"b "<<temp[1]<<" "<<temp[0]<<endl;
      //cout<<"c "<<base->edgeExists(2,0)<<endl;
      //if(temp[1]==destination)
        //return sd[destination];
      for(int i=0;i<Vertices;i++)
      {
        if(base->edgeExists(temp[1],i))
        {
          int b=Q.search(i);
          if(b==-1)
            continue;
          // cout<<i<<" "<<b<<" "<<distances[b]<<" "<<sd[temp[1]]+weight<<endl;
          if(Q.value(b)>weight)
          {
            // cout<<"if in\n";
            Q.DecreaseKey(b,weight);
            p[i]=temp[1];
            // pos++;
          }
          // cout<<distances[i]
    //       cout<<"start\n";
    // for (int i = 0; i < Q.get_length(); ++i)
    // {
    //   cout<<indicies[i]<<" "<<distances[i]<<endl;
    // }
    // cout<<"endl\n";
        }
      }
    } 
  }


};

#endif /* ifndef ABSTRACT_GRAPH */
