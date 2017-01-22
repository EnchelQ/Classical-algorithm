#include<iostream>
#include<random>
#include<ctime>
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
int random_select(int *a,int first,int last,int i)
{
	if(i==first)
		return a[first];
	int mid=random_partition(a,first,last);
	int k=mid-first+1;
	if(i==k)
		return *(a+mid);
	else if(i<k)
		return random_select(a,first,mid-1,i);
	else
		return random_select(a,mid+1,last,i-k);
}
int main()
{
	int a[6]={3,5,4,1,6,2};
	std::cout<<random_select(a,0,5,5)<<std::endl;
}
