#include <iostream>
#include "DirectedGraph.hpp"
#include "AdjacencyMatrix.hpp"
using namespace std;

int main()
{

    DirectedGraph D(7,'m'); 
    //cout<<"a "<<endl;
    D.add(0, 1);
    //cout<<"a "<<endl; 
    D.add(0, 3); 
    D.add(1, 4); 
    D.add(1, 3); 
    D.add(2,0); 
    D.add(2, 5);
    D.add(3, 2);
    D.add(3, 4);
    D.add(3, 6);
    D.add(3, 5);
    D.add(4, 6);
    D.add(6, 5);

    cout<<"ans "<<endl;
   // int d[5];
    // int s,d;
    // cin>>s>>d;
    
    // cout<<D.Dijkstra(s,d)<<endl;
    int tree[7],p[7];
    D.prims(0,tree,p);
    for (int i = 0; i < 7; ++i)
    {
        cout<<i<<" "<<tree[i]<<" "<<p[i]<<endl;
    }
    return 0;
}