#include<iostream>
#include<random>
#include<ctime>
//using namespace std;
int partition(int *a,int first,int last)
{
	int refer=a[last];
	int k=first-1;
	for(int i=first;i<last;i++)
	{
		if(*(a+i)<=refer)
		{
			k++;
			if(k!=i)
			{
				int temp=*(a+k);
				*(a+k)=*(a+i);
				*(a+i)=temp;
			}
		}
	}
	*(a+last)=*(a+k+1);
	*(a+k+1)=refer;
	return k+1;
}
int random_partition(int *a,int first,int last)
{
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(first,last);
	int i=u(e);
	int temp=*(a+last);
	*(a+last)=*(a+i);
	*(a+i)=temp;
	return partition(a,first,last);
}
int partition2(int *a,int first,int last)
{
	int refer=*(a+first);
	int i=first,j=last;
	while(i!=j)
	{
		while(i<j && *(a+j)>=refer)
			j--;
		while(i<j && *(a+i)<=refer)
			i++;
		if(i<j)
		{
			int temp=*(a+i);
			*(a+i)=*(a+j);
			*(a+j)=temp;
		}
	}
	*(a+first)=*(a+i);
	*(a+i)=refer;
	return i;
}
int partition3(int *a,int first,int last)
{
	int refer=a[first];
	while(true)
	{
		while(*(a+first)<refer)
			first++;
		while(refer<*(a+last))
			last--;
		if(!(first<last))return first;
		int temp=*(a+first);
		*(a+first)=*(a+last);
		*(a+last)=temp;
		++first;
	}
}
void quick_sort3(int *a,int first,int last)
{
	if(first<last)
	{
		int mid=partition3(a,first,last);
		if(mid==first)
			quick_sort3(a,first+1,last);
		else
		{
			quick_sort3(a,first,mid-1);
			quick_sort3(a,mid,last);
		}
	}
}
void quick_sort(int *a ,int first,int last)
{
	if(first<last)
	{
	int mid=random_partition(a,first,last);
	quick_sort(a,first,mid-1);
	quick_sort(a,mid+1,last);
	}
}

int main()
{
	int a[6]={5,3,7,8,2,4};
	quick_sort3(a,0,5);
//	partition(a,0,5);
//	partition(a,0,1);
//	partition(a,3,5);
//	random_partition(a,0,5);
	for(int i=0;i<6;i++)
		std::cout<<*(a+i);
		std::cout<<std::endl;

}
