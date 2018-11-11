#include <iostream>
 #include "UndirectedGraph.hpp"
#include <fstream>
// #include "AdjacencyMatrix.hpp"
#include "priorityQ.hpp"
using namespace std;

int main()
{
	int i=0;
	int c=0;
	string qs;
	ifstream ptr;
	ptr.open("in.txt");

	while(getline(ptr,qs))
	{
		cout<<qs<<endl;
		i++;
		for (int j = 0; j < qs.length(); j++)
		{
			if(qs[j]==' ')
				c++;
		}
		cout<<"word "<<c+1<<endl;
		c=0;

	}


	ptr.close();
	cout<<"lines "<<i<<endl;
}