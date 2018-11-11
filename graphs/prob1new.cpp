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
			cout<<"aa\n";
			if(A[i][j]=='G')
			{
				Q.enqueue(i*5+j);
				cout<<"A "<<i*5+j<<endl;
				while(Q.queue_length()!=0)
				{
					// cout<<"aaaaa "<<t;
					int t=Q.dequeue();
					// cout<<"aaaaa "<<t<<endl;
					int r=t/5;
					int c=t%5;
					if(A[r][c]=='W')
					{
						D[r][c]=-1;
						continue;
					}
					
				if(r==0 && c==0)
				{
					cout<<"in\n";
					Q.enqueue((r+1)*5+c);
					Q.enqueue(r*5+c+1);
					add(r,c,r+1,c,D);
					add(r,c,r,c+1,D);
				}
				else
				{
					if(r==0 && c!=0  && c!=4)
					{
						cout<<"in\n";
						Q.enqueue((r+1)*5+c);
						Q.enqueue(r*5+c+1);
						Q.enqueue(r*5+c-1);
						add(r,c,r+1,c,D);
						add(r,c,r,c+1,D);
						add(r,c,r,c-1,D);
					}
					else
					{
						if(r!=0 && c==0 && r!=4 )
						{
							cout<<"in\n";
							Q.enqueue(r*5+c+1);
							Q.enqueue((r+1)*5+c);
							Q.enqueue((r-1)*5+c);
							add(r,c,r,c+1,D);
							add(r,c,r+1,c,D);
							add(r,c,r-1,c,D);
						}
						else
						{
							if(r!=0 && c!=0 && r!=4 && c!=4)
							{
								cout<<"in\n";
								Q.enqueue(r*5+c+1);
								Q.enqueue((r+1)*5+c);
								Q.enqueue((r-1)*5+c);
								Q.enqueue(r*5+c-1);
								add(r,c,r,c+1,D);
								add(r,c,r+1,c,D);
								add(r,c,r,c-1,D);
								add(r,c,r-1,c,D);
							}
							else
							{
								if(r==4 && c!=4 && c!=0)
								{
									cout<<"in\n";
									Q.enqueue(r*5+c+1);
									Q.enqueue((r-1)*5+c);
									Q.enqueue(r*5+c-1);
									add(r,c,r,c+1,D);
									add(r,c,r-1,c,D);
									add(r,c,r,c-1,D);
								}
								else
								{
									if(r!=4 && c==4 && r!=0)
									{
										cout<<"in\n";
										Q.enqueue((r+1)*5+c);
										Q.enqueue((r-1)*5+c);
										Q.enqueue(r*5+c-1);
										add(r,c,r+1,c,D);
										add(r,c,r-1,c,D);
										add(r,c,r,c-1,D);
									}
									else
									{
										if(r==4 && c==4)
										{
											cout<<"in\n";
											Q.enqueue((r-1)*5+c);
											Q.enqueue(r*5+c-1);
											add(r,c,r-1,c,D);
											add(r,c,r,c-1,D);
										}
										else
										{
											if(r==4 && c==0)
											{
												cout<<"in\n";
												//Q.enqueue((i)*5+j);
												Q.enqueue((r-1)*5+c);
												Q.enqueue(r*5+c+1);
												add(r,c,r-1,c,D);
												add(r,c,r,c+1,D);
												// add(r,c,i,j-1,D);
											}
											else
											{
												if(r==0 && c==4)
												{
													//cout<<"in\n";
													Q.enqueue((r+1)*5+c);
													Q.enqueue(r*5+c-1);
													add(r,c,r+1,c,D);
													add(r,c,r,c-1,D);
												}
												// cout<<"ot\n";
											}
										}

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
	cout<<"aman\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
}