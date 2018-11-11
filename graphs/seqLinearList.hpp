#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList()
		{
            element = NULL;
            len = 0;
			MaxSize = 0;
		}
		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			MaxSize=MaxListSize;
			element = (Item*)malloc(MaxSize*sizeof(Item));
			//cout<<MaxSize<<endl;
			len = 0;
		}

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
			delete element;
		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)//return i'th element of list
		{
			if(i > MaxSize) exit(0);

			return *(element + i);
		}
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if(len) return 0;
			else return 1;
		}
		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
			return len;		
		}

		/* Returns the maximum size of the list.
     		 * */
		int  Maxsize()
		{
			return MaxSize;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			return *(element + k);
		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
			if(k > len) return 0;
			else return x=*(element + k); 
				
		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			for(int i=0;i<len;i++)
			{
				if(*(element+i)==x) return i;
			}
			return 0;
		}

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x)
		{
				if(k>len)
					return ;
				else
				{
					x=*(element+k);
					for(int i=k;i<len;i++)
						*(element+i)=*(element+i+1);
					len--;
				}
		}

		/* Insert x after k-th element.
		 * */
		void  insert(const int k ,const Item& x)
		{
			if(k>len-1)
			{
				exit(0);
			}
			else
			{
				if(len==MaxSize)
				{
					element=(Item*)realloc(element,(len+1)*sizeof(Item));
					MaxSize++;
				}
				len++;
				for(int i=len-1;i>k+1;i--)
					*(element+i)=*(element+i-1);
				*(element+k+1)=x;
			}
		}
};


#endif