#include <iostream>
#include "UndirectedGraph.hpp"

using namespace std;

int main()
{
	int v,e;
	cin>>v>>e;
	UndirectedGraph U(v,'m');

	for (int i = 0; i < e; i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		U.add(t1,t2);
	}
	int a[v],ans[v],in=0;
	int k=U.dfs(0,a,ans);
	for(int i=0;i<k;i++)
	{
		cout<<"Connected Component "<<i+1<<": ";
		for(int j=in;j<a[i];j++)
		{
			cout<<ans[j]<<" ";			
		}
		cout<<endl;
		in=a[i];
	}
}
