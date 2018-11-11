#include <iostream>
#include "DirectedGraph.hpp"

using namespace std;

int main()
{
	char A[5][5];
	DirectedGraph U(25,'m');
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin>>A[i][j];
		}
	}
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if(i==0 && j==0)
			{
				U.add(i+j*5,i+j*5+1);
				U.add(i+j*5,i+(j+1)*5);
			}
			else
			{
				if(i==0 && j!=0  && j!=4)
				{
					U.add(i+j*5,i+j*5+1);
					U.add(i+j*5,i+(j-1)*5);
					U.add(i+j*5,i+(j+1)*5);
				}
				else
				{
					if(i!=0 && j==0 && i!=4 )
					{
						U.add(i+j*5,i+j*5+1);
						U.add(i+j*5,i+j*5-1);
						U.add(i+j*5,i+(j+1)*5);
					}
					else
					{
						if(i!=0 && j!=0 && i!=4 && j!=4)
						{
							U.add(i+j*5,i+j*5+1);
							U.add(i+j*5,i+j*5-1);
							U.add(i+j*5,i+(j+1)*5);
							U.add(i+j*5,i+(j-1)*5);
						}
						else
						{
							if(i==4 && j!=4)
							{
								U.add(i+j*5,i+j*5-1);
								U.add(i+j*5,i+(j+1)*5);
								U.add(i+j*5,i+(j-1)*5);
							}
							else
							{
								if(i!=4 && j==4)
								{
									U.add(i+j*5,i+j*5+1);
									U.add(i+j*5,i+j*5-1);
									U.add(i+j*5,i+(j-1)*5);
								}
								else
								{
									U.add(i+j*5,i+j*5-1);
									U.add(i+j*5,i+(j-1)*5);
								}
							}
						}
					}
				}
			}

		}
	}
	// cout<<"Aman "<<U.edgeExists(3,4)<<endl;
	// cout<<"A"<<endl;
	for(int i=0;i<5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// if(i==0 && j==3)
				//cout<<"a "<<A[i][j]<<endl;
			if(A[i][j]=='O')
			{
				cout<<U.Modifiedbfs(i*5+j,A,5)<<" ";
			}
			if(A[i][j]=='G')
				cout<<"0 ";
			if(A[i][j]=='W')
				cout<<"-1 ";
		}
		cout<<endl;
	}
}