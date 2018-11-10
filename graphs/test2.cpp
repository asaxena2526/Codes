#include <iostream>
// #include "DirectedGraph.hpp"
// #include "AdjacencyMatrix.hpp"
#include "priorityQ.hpp"
using namespace std;

int main()
{
	// Queue Q;
	// Q.enqueue(1);
	// Q.enqueue(2);
	// cout<<"l "<<Q.queue_length()<<endl;
	// Q.enqueue(4);
	// Q.enqueue(3);
	// cout<<"l "<<Q.queue_length()<<endl;
	// cout<<Q.dequeue()<<endl;
	// Q.enqueue(5);
	// cout<<"l "<<Q.queue_length()<<endl;
	// Q.enqueue(6);
	// cout<<Q.dequeue()<<endl;
	// cout<<"l "<<Q.queue_length()<<endl;
	// cout<<Q.dequeue()<<endl;
	// cout<<Q.dequeue()<<endl;
	// cout<<Q.dequeue()<<endl;
	// cout<<Q.dequeue()<<endl;
	int n=10;
	int A[n],B[n];
	A[0]=100;
	A[1]=12;
	A[2]=115;
	A[3]=133;
	A[4]=10;
	A[5]=90;
	A[6]=8;
	A[7]=14;
	A[8]=13;
	A[9]=26;
	//A[0]=100;
	for (int i = 0; i < n; i++)
	{
		B[i]=i;
	}
	PriorityQ Q(n);
	Q.makeHeap(A,B,0,n-1);
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}
	int C[2],D[2];
	Q.ExtractMin(A,B,C);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}
	Q.DecreaseKey(A,B,7,6);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}
	Q.ExtractMin(A,B,D);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}
	cout<<"ANS"<<endl;
	cout<<C[0]<<" "<<C[1]<<endl;
	cout<<D[0]<<" "<<D[1]<<endl;
	Q.ExtractMin(A,B,D);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}Q.ExtractMin(A,B,D);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}Q.ExtractMin(A,B,D);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}Q.ExtractMin(A,B,D);
	cout<<"change"<<endl;
	for (int i = 0; i < Q.get_length(); i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}


}