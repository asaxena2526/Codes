#include <iostream>
#include <fstream>
#include "DirectedGraph.hpp"

using namespace std;

int main()
{
	int ir=0;
	int cr=0;
	int word;
	string qs;
	ifstream ptr;
	ptr.open("in.txt");

	while(getline(ptr,qs))
	{
		//cout<<qs<<endl;
		ir++;
		for (int j = 0; j < qs.length(); j++)
		{
			if(qs[j]==' ')
				cr++;
		}
		word=cr+1;
		cr=0;

	}
	ptr.close();
	ptr.open("in.txt");

	char** A=new char*[ir];;

	for (int i = 0; i < ir; i++)
	{
		A[i]=new char[word];	
	}

	DirectedGraph U(ir*word,'m');
	// for (int i = 0; i < ir; i++)
	// {
	int i=0,j=0;
		while(ptr >> A[i][j])
		{
			j++;
			if(j==5)
			{
				j=0;
				i++;
			}
		}
		ptr.close();
		// for (int j = 0; j < word; j++)
		// {
		// 	cin>>A[i][j]
		// }
	// }
	for (int j = 0; j < ir; j++)
	{
		for (int i = 0; i < word; i++)
		{
			if(i==0 && j==0)
			{
				U.add(i+j*word,i+j*word+1);
				U.add(i+j*word,i+(j+1)*word);
			}
			else
			{
				if(i==0 && j!=0  && j!=ir-1)
				{
					U.add(i+j*word,i+j*word+1);
					U.add(i+j*word,i+(j-1)*word);
					U.add(i+j*word,i+(j+1)*word);
				}
				else
				{
					if(i!=0 && j==0 && i!=ir-1 )
					{
						U.add(i+j*word,i+j*word+1);
						U.add(i+j*word,i+j*word-1);
						U.add(i+j*word,i+(j+1)*word);
					}
					else
					{
						if(i!=0 && j!=0 && i!=word-1 && j!=ir-1)
						{
							U.add(i+j*word,i+j*word+1);
							U.add(i+j*word,i+j*word-1);
							U.add(i+j*word,i+(j+1)*word);
							U.add(i+j*word,i+(j-1)*word);
						}
						else
						{
							if(i==word-1 && j!=ir-1 && j!=0)
							{
								U.add(i+j*word,i+j*word-1);
								U.add(i+j*word,i+(j+1)*word);
								U.add(i+j*word,i+(j-1)*word);
							}
							else
							{
								if(i!=word-1 && j==ir-1 && i!=0)
								{
									U.add(i+j*word,i+j*word+1);
									U.add(i+j*word,i+j*word-1);
									U.add(i+j*word,i+(j-1)*word);
								}
								else
								{
									if(i==word-1 && j==ir-1)
									{
										U.add(i+j*word,i+j*word-1);
										U.add(i+j*word,i+(j-1)*word);
									}
									else
									{
										if(i==0 && j==ir-1)
										{
											U.add(i+j*word,i+j*word+1);
											U.add(i+j*word,i+(j-1)*word);
										}
										else
										{
											if(i==word-1 && j==0)
											{
												U.add(i+j*word,i+j*word-1);
												U.add(i+j*word,i+(j+1)*word);	
											}
										}
									}
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
	for(int i=0;i<ir;i++)
	{
		for (int j = 0; j < word; j++)
		{
			// if(i==0 && j==3)
				//cout<<"a "<<A[i][j]<<endl;
			if(A[i][j]=='O')
			{
				cout<<U.Modifiedbfs(i*word+j,A,word)<<" ";
			}
			if(A[i][j]=='G')
				cout<<"0 ";
			if(A[i][j]=='W')
				cout<<"-1 ";
		}
		cout<<endl;
	}
}