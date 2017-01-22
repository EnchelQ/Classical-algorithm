#include<iostream>
void insertSort(int *array,int len)
{
	for(int i=1;i<len;i++)
	{
		int cur=*(array+i);
		int j=i-1;
		for(;j>=0;j--)
		{
			if(*(array+j)>cur)
				*(array+j+1)=*(array+j);
			else
				break;
      		}
		*(array+j+1)=cur;
	}
}

int main()
{
	int a[10]={2,4,10,5,3,7,11,18,14,13};
	insertSort(a,10);
	for(int i=0;i<10;i++)
	{
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
}
