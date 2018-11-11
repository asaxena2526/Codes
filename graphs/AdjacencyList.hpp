#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include <iostream>

/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
typedef struct S
{
	int value;
	int weight;
	struct S *next;
}Node;
class AdjacencyList : public GraphAdjacencyBase {

	int size;
	Node **List;

	public:
	AdjacencyList(int vertices)
	{
		size=vertices;
		List=new Node*[size]; 
		for (int i = 0; i < size; i++)
		{
			List[i]=NULL;
		}
	}
	~AdjacencyList()
	{
		delete List;
	}
	bool edgeExists(int i,int j)
	{
		Node *temp=List[i];
		while(temp!=NULL)
		{
			if(temp->value==j)
				return 1;
			temp=temp->next;
		}
		return 0;
	}
	int vertices()
	{
		return size;
	}
	int edges()
	{
		int e=0;
		for (int i = 0; i < size; i++)
		{
			Node *temp=List[i];
			while(temp!=NULL)
			{
				e++;
				temp=temp->next;
			}
		}
		return e;
	}
	void add(int i, int j,int w=1)
	{
		if(List[i]==NULL)
		{
			List[i]=new Node;
			List[i]->value=j;
			List[i]->weight=w;
			List[i]->next=NULL;
		}
		else
		{
			Node* temp=List[i];
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new Node;
			temp=temp->next;
			temp->value=j;
			temp->weight=w;
			temp->next=NULL;
		}
	}
	void remove(int i, int j)
	{
		Node *temp=List[i];
		if(List[i]->value==j)
		{
			List[i]=List[i]->next;
			delete temp;
		}
		else
		{
			while(temp->next!=NULL)
			{
				Node *tmp=temp->next;
				if(temp->next->value==j)
				{
					temp->next=tmp->next;
					delete tmp;
				}
				temp=temp->next;
			}
		}
	}
	int degree(int i)
	{
		int d=0;
		Node *temp=List[i];
		while(temp!=NULL)
		{
			d++;
			temp=temp->next;
		}
		return d;
	}
	int Weight(int i,int j)
	{
		Node *temp=List[i];
		while(temp!=NULL)
		{
			if(temp->value==j)
				return temp->weight;
			temp=temp->next;
		}
		return 0;
	}
		  	
};  	
#endif /* ifndef ADJACENCY_LIST */
