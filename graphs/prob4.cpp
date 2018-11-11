#include <iostream>
#include "DirectedGraph.hpp"

using namespace std;

int main()
{
	int v,e;
	cin>>v>>e;
	DirectedGraph D(v,'m');
	for (int i = 0; i < e; i++)
	{
		int t1,t2,w;
		cin>>t1>>t2>>w;
		D.add(t1-1,t2-1,w);
	}
	int x=v-1;
	int p[v];

	int o=D.Dijkstra(0,x,p,1);
	//cout<<"a "<<o<<endl;
	int q[o];
	cout<<"ANS"<<endl;
	q[o-1]=x;
	for(int i=2;i<=o;i++)
	{
		q[o-i]=p[x];
		x=p[x];
	}
	//cout<<start<<endl;
	for (int i = 0; i <o-1; ++i)
	{
		cout<<q[i]+1<<" -> ";
	}
	cout<<q[o-1]+1<<endl;
	cout<<D.Dijkstra(0,v-1,p,0)<<endl;
	

}