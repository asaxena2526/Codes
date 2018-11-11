#ifndef PRIORITYQ
#define PRIORITYQ 1

typedef struct ${
	int a;
	int b;
}Struct;


class PriorityQ
{
	int length;
	int size;
	Struct* S;
public:
	PriorityQ(int n)
	{
		length=n;
		size=-1;
		S=new Struct[length];
	}
	int value(int b)
	{
		return S[b].a;
	}
	void insert(int i,int x)
	{
		S[i].a=x;
		S[i].b=i;
		size++;
	}
	void Heapify(int  k,int low,int high)
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
           		if(S[r].a<S[smallest].a)
           			smallest=r;
           	}  
           	if(l<length)
           	{
           		if(S[l].a<S[smallest].a)
           			smallest=l;
           	}        			
        }
        if(smallest!=k)
        {
           	Struct temp=S[k];
           	S[k]=S[smallest];
           	S[smallest]=temp;
           	// temp=B[k];
           	// B[k]=B[smallest];
           	// B[smallest]=temp;
           	Heapify(smallest,low,high);
        }
        return;
    }

    void makeHeap(int low,int high)
    {
        for(int i=(high-1+low)/2;i>=low;i--)
           	Heapify(i,low,high);
    }
    void heapSort(int low, int high)
    {
        makeHeap(low,high);
        //int length=A.length();
        for(int i=high;i>low;i--)
       	{
       		Struct temp=S[low];
       		S[low]=S[i];
       		S[i]=temp;
       		// temp=B[low];
       		// B[low]=B[i];
       		// B[i]=temp;
       		length--;
       		Heapify(low,low,high);
       	}
       	return;
    }
    void DecreaseKey(int x,int k)
    {
    	// int i,flag=0;
    	// for( i=0;i<length;i++)
    	// {
    	// 	if(B[i]==x)
    	// 	{
    	// 		flag=1;
    	// 		break;
    	// 	}
    	// }
    	// if(flag==0)
    	// 	return;
    	int z=x;
    	if(k<S[z].a)
    	{
    		S[z].a=k;
    		x=(x-1)/2;
    		while(x>=0 && S[z].a<S[x].a)
    		{
    			Struct temp=S[x];
    			S[x]=S[z];
    			S[z]=temp;
    			// temp=B[x];
    			// B[x]=B[a];
    			// B[a]=temp;
    			// B[i]=a;
    			// B[a]=i;
    			z=x;
    			x=(x-1)/2;
    		}
    	}
    }
    void ExtractMin(int ans[])
    {
    	ans[0]=S[0].a;
    	ans[1]=S[0].b;
    	S[0]=S[length-1];
    	// B[0]=B[length-1];

    	length--;
    	Heapify(0,0,length-1);

    }
    int search(int x)
    {
    	for (int i = 0; i < length; i++)
    	{
    		if(S[i].b==x)
    			return i;
    	}
    	return -1;
    } 
    int get_length()
    {
    	return length;
    }
};
#endif
