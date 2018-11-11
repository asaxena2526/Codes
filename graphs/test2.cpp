#include <iostream>
 #include "UndirectedGraph.hpp"
// #include "AdjacencyMatrix.hpp"
#include "priorityQ.hpp"
using namespace std;

int main()
{
	UndirectedGraph D(7,'m'); 
    //cout<<"a "<<endl;
    D.add(0, 1);
    // cout<<D.edgeExists(0,1)<<endl;
    //cout<<"a "<<endl; 
    D.add(0, 3); 
    // cout<<D.edgeExists(0,3)<<endl;
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
    cout<<D.Modifiedbfs(4,2)<<endl;
}