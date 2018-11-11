#include <iostream>
#include "queue.hpp"
#define inf 2147483647
using namespace std;

void add(int r,int c,int i,int j,int D[][5])
{
	if(D[r][c]+1<D[i][j])
	{
		D[i][j]=D[r][c]+1;
	}
}
int main()
{
	char A[5][5];
	int D[5][5];
	for (int i = 0; i < 5; i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>A[i][j];

			D[i][j]=inf;
			if(A[i][j]=='W')
				D[i][j]=-1;
			if(A[i][j]=='G')
				D[i][j]=0;
		}
	}
	cout<<"aa\n";
	Queue<int> Q;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(A[i][j]=='G')
			{
				Q.enqueue(i*5+j);
				while(Q.queue_length()!=0)
				{
					int t=Q.dequeue();
					int r=t/5;
					int c=t%5;
					if(A[r][c]=='W')
					{
						D[r][c]=-1;
						continue;
					}
					
				if(i==0 && j==0)
				{
					Q.enqueue((i+1)*5+j);
					Q.enqueue(i*5+j+1);
					add(r,c,i+1,j,D);
					add(r,c,i,j+1,D);
				}
				else
				{
					if(i==0 && j!=0  && j!=4)
					{
						Q.enqueue((i+1)*5+j);
						Q.enqueue(i*5+j+1);
						Q.enqueue(i*5+j-1);
						add(r,c,i+1,j,D);
						add(r,c,i,j+1,D);
						add(r,c,i,j-1,D);
					}
					else
					{
						if(i!=0 && j==0 && i!=4 )
						{
							Q.enqueue(i*5+j+1);
							Q.enqueue((i+1)*5+j);
							Q.enqueue((i-1)*5+j);
							add(r,c,i,j+1,D);
							add(r,c,i+1,j,D);
							add(r,c,i-1,j,D);
						}
						else
						{
							if(i!=0 && j!=0 && i!=4 && j!=4)
							{
								Q.enqueue(i*5+j+1);
								Q.enqueue((i+1)*5+j);
								Q.enqueue((i-1)*5+j);
								Q.enqueue(i*5+j-1);
								add(r,c,i,j+1,D);
								add(r,c,i+1,j,D);
								add(r,c,i,j-1,D);
								add(r,c,i-1,j,D);
							}
							else
							{
								if(i==4 && j!=4)
								{
									Q.enqueue(i*5+j+1);
									Q.enqueue((i-1)*5+j);
									Q.enqueue(i*5+j-1);
									add(r,c,i,j+1,D);
									add(r,c,i-1,j,D);
									add(r,c,i,j-1,D);
								}
								else
								{
									if(i!=4 && j==4)
									{
										Q.enqueue((i+1)*5+j);
										Q.enqueue((i-1)*5+j);
										Q.enqueue(i*5+j-1);
										add(r,c,i+1,j,D);
										add(r,c,i-1,j,D);
										add(r,c,i,j-1,D);
									}
									else
									{
										Q.enqueue((i-1)*5+j);
										Q.enqueue(i*5+j-1);
										add(r,c,i-1,j,D);
										add(r,c,i,j-1,D);

									}
								}
							}
						}
					}
				}
				// if(A[r][c]='G')
				// 	{
				// 		D[r][c]=0;
				// 		continue;
				// 	}
			}

			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
}