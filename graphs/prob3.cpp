#include <iostream>
#include <fstream>
#include "UndirectedGraph.hpp"
#include "seqLinearList.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	LinearList<string> s;
	string qs;
	ifstream ptr;
	ptr.open(argv[1]);

	while(getline(ptr,qs))
	{
		s.insert(s.length()-1,qs);
	}
	ptr.close();
	
	UndirectedGraph U(s.length()+1,'m');

	for(int i=0;i<s.length();i++)
	{
		for(int j=i+1;j<s.length();j++)
		{
			if(i==j)
				continue;
			else
			{
				// cout<<"aa "<<i<<" "<<j<<" "<<U.edgeExists(0,4)<<endl;
				int k=0,count=0;;
				while(s[i].length()>k)
				{
					
					if(s[i][k]!=s[j][k])
					{
						
						count++;
					}
					k++;
				}
				if(count<2)
				{
					// if(i==0 && j==4)
						// cout<<"fuck\n";
					U.add(i,j);
				}
				// if(i==0 && j==4)
					// cout<<"aa "<<count<<" "<<U.edgeExists(0,4)<<endl;

			}
		}
	}
	
	string start,end;
	cin>>start>>end;
	for(int i=0;i<s.length();i++)
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
			U.add(s.length(),i);
	}
	// int st,e;
	// cin>>st>>e;
	// cout<<U.edgeExists(st,e)<<endl;
	int x;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==end)
			x=i;

	}
	// cout<<x<<endl;
	int p[s.length()+1];
	int o=U.Dijkstra(s.length(),x,p,0);
	// cout<<o<<endl;
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