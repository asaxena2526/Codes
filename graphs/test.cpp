#include <iostream>
#include "DirectedGraph.hpp"
#include "AdjacencyMatrix.hpp"
using namespace std;

int main()
{

    DirectedGraph D(4,'m'); 
    //cout<<"a "<<endl;
    D.add(0, 3);
    //cout<<"a "<<endl; 
    D.add(0, 2); 
    D.add(1, 3); 
    //D.add(2, 0); 
    //D.add(2, 3); 
    //D.add(2, 4);
    //D.add(3, 3);
    //D.add(3, 4);
    //D.add(5, 6);

    cout<<"ans "<<endl;
    D.bfs(0);

    return 0;
}