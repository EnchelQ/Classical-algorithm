#include<iostream>
void merge(int *a,int *b,int *c,int len1,int len2)
{
	int i=0,j=0;
	while(i<len1 && j<len2)
	{
		if(*a>*b)
		{
			*c=*b;
			b++;
			j++;
		}
		else
		{
			*c=*a;
			a++;
			i++;
		}
		c++;
	}
	while(i<len1)
	{
		*c=*a;
		a++;
		c++;
		i++;
	}
	while(j<len2)
	{
		*c=*b;
		c++;
		b++;
		j++;
	}
}
void implace_merge(int *a,int mid,int len)
{
	int temp[mid];
	for(int i=0;i<mid;i++)
	{
		temp[i]=*(a+i);
	}
	merge(temp, a+mid,a,mid,len-mid);
}
void merge_sort(int *a,int len)
{
	if(len==0 || len==1)
		return ;
	int mid=len/2;
	merge_sort(a,mid);
	merge_sort(a+mid,len-mid);
	implace_merge(a,mid,len);
}
int main()
{
	//int a[3]={2,3,8};
	//int b[3]={4,5,9};
	int c[1]={2};
	merge_sort(c,1);
	for(int i=0;i<1;i++)
	{
		std::cout<<*(c+i)<<std::endl;
	}
}
