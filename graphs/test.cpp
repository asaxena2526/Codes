#include <iostream>
#include "DirectedGraph.hpp"
#include "AdjacencyMatrix.hpp"
using namespace std;

int main()
{

    DirectedGraph D(6,'m'); 
    //cout<<"a "<<endl;
    D.add(0, 3);
    //cout<<"a "<<endl; 
    D.add(0, 1); 
    D.add(0, 2); 
    D.add(1, 2); 
    D.add(1, 3); 
    D.add(2, 3);
   // D.add(3, 4);
    D.add(4, 0);
    D.add(4, 1);
    D.add(4, 5);
    // D.add(, 0);

    cout<<"ans "<<endl;
    D.bfs(0);

    return 0;
}