#include<iostream>
void adjust_heap(int *a,int heap_size,int i)
{
	if(i>(heap_size/2-1))
		return;
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;

	if(l<heap_size && *(a+l)>*(a+largest))
		largest=l;
	if(r<heap_size && *(a+r)>*(a+largest))
		largest=r;

	if(largest!=i)
	{
		int temp=*(a+i);
		*(a+i)=*(a+largest);
		*(a+largest)=temp;
		adjust_heap(a,heap_size,largest);
	}
}
void make_heap(int *a,int len)
{
	if(len==1)
		return;
	//error:int i=(len-1)/2;
	int i=len/2-1;
	while(i>=0)
	{
		adjust_heap(a,len,i);
		i--;
	}
}

//the follow operations are based on a build heap.
void heap_sort(int *a,int len)
{
	make_heap(a,len);
	for(int i=len-1;i>0;i--)
	{
		int temp=*a;
		*a=*(a+i);
		*(a+i)=temp;
		adjust_heap(a,i,0);
	}
}
int pop_heap(int *a,int heap_size)
{
	int max=*a;
	*a=*(a+heap_size-1);
	adjust_heap(a+1,heap_size-1,0);
	return max;
}
void increase_key(int *a,int heap_size,int i,int k)
{
	if(i>=heap_size)
	{
		std::cout<<"invalid position"<<std::endl;
		return ;
	}
	while(i>0)
	{
		int parent=(i-1)/2;
		if(*(a+parent)<k)
		{
			*(a+i)=*(a+parent);
			*(a+parent)=k;
			i=parent;
		}
		else
			break;
	}
}
int main()
{
	int a[6]={1,3,6,4,9,8};
	make_heap(a,6);
	std::cout<<pop_heap(a,6);
	std::cout<<std::endl;
	increase_key(a,6,2,10);
	std::cout<<pop_heap(a,6)<<std::endl;
}
