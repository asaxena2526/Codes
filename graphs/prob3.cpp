#include <iostream>
#include "UndirectedGraph.hpp"
using namespace std;

int main()
{

	string s[7];
	UndirectedGraph U(8,'m');
	for (int i = 0; i < 7; i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<7;i++)
	{
		for(int j=i+1;j<7;j++)
		{
			if(i==j)
				continue;
			else
			{
				int k=0,count=0;;
				while(s[i].length()>k)
				{
					if(s[i][k]!=s[j][k])
						count++;
					k++;
				}
				if(count<2)
					U.add(i,j);

			}
		}
	}
	
	string start,end;
	cin>>start>>end;
	for(int i=0;i<7;i++)
	{
		int k=0,count=0;
		while(s[i].length()>k)
		{
			if(s[i][k]!=start[k])
			{
				// cout<<"ss"<<endl;
				count++;
			}

			k++;
		}
		// cout<<endl;
		if(count<2)
			U.add(7,i);
	}
	// int st,e;
	// cin>>st>>e;
	// cout<<U.edgeExists(st,e)<<endl;
	int x;
	for(int i=0;i<7;i++)
	{
		if(s[i]==end)
			x=i;

	}
	int p[8];
	int o=U.Dijkstra(7,x,p);
	int q[o+1];
	cout<<"ANS"<<endl;
	q[o]=x;
	for(int i=1;i<=o;i++)
	{
		q[o-i]=p[x];
		x=p[x];
	}
	cout<<start<<endl;
	for (int i = 1; i <=o; ++i)
	{
		cout<<s[q[i]]<<endl;
	}
	cout<<o+1<<endl;

}