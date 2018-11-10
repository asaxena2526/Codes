#ifndef PRIORITYQ
#define PRIORITYQ 1


class PriorityQ
{
	int length;
public:
	PriorityQ(int n)
	{
		length=n;
	}

	void Heapify(int A[],int B[],int  k,int low,int high)
    {
        int l=2*k+1-low;
        int r=2*k+2-low;
        int smallest=k;
        if(l>=length && r>=length)
           	return;
        else
        {
           	if(r<length)
           	{
           		if(A[r]<=A[smallest])
           			smallest=r;
           	}  
           	if(l<length)
           	{
           		if(A[l]<=A[smallest])
           			smallest=l;
           	}        			
        }
        if(smallest!=k)
        {
           	int temp=A[k];
           	A[k]=A[smallest];
           	A[smallest]=temp;
           	temp=B[k];
           	B[k]=B[smallest];
           	B[smallest]=temp;
           	Heapify(A,B,smallest,low,high);
        }
        return;
    }

    void makeHeap(int A[],int B[],int low,int high)
    {
        for(int i=(high-1+low)/2;i>=low;i--)
           	Heapify(A,B,i,low,high);
    }
    void heapSort(int A[],int B[],int low, int high)
    {
        makeHeap(A,B,low,high);
        //int length=A.length();
        for(int i=high;i>low;i--)
       	{
       		int temp=A[low];
       		A[low]=A[i];
       		A[i]=temp;
       		temp=B[low];
       		B[low]=B[i];
       		B[i]=temp;
       		length--;
       		Heapify(A,B,low,low,high);
       	}
       	return;
    }
    void DecreaseKey(int A[],int B[],int x,int k)
    {
    	int i;
    	for( i=0;i<length;i++)
    	{
    		if(B[i]==x)
    			break;
    	}
    	int a=i;
    	if(k<A[a])
    	{
    		A[a]=k;
    		i=(i-1)/2;
    		while(i>=0 && A[a]<A[i])
    		{
    			int temp=A[i];
    			A[i]=A[a];
    			A[a]=temp;
    			temp=B[i];
    			B[i]=B[a];
    			B[a]=temp;
    			a=i;
    			i=(i-1)/2;
    		}
    	}
    }
    void ExtractMin(int A[],int B[],int ans[])
    {
    	ans[0]=A[0];
    	ans[1]=B[0];
    	A[0]=A[length-1];
    	B[0]=B[length-1];

    	length--;
    	Heapify(A,B,0,0,length-1);

    } 
    int get_length()
    {
    	return length;
    }
};
#endif
