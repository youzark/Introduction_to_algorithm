#include <stdio.h>
#include <malloc.h>

int main()
{
	int num,i,k,mid;
	int data[1003];
	scanf("%d",&num);
	for(i = 0;i < num; i++)
	{
		scanf("%d",&data[i]);
	}
	for(i = 1 ;i < num; i ++)
	{
		mid = data[i];
		for(k = i - 1 ; k >= 0 ;k -- )
		{
			if(data[k] > data[i])
			{
				data[k + 1] =data[k];
			}
			else
			{
				break;
			}
		}
		if(k != i-1)
		{
			data[k + 1] = mid;
		}
	}
	for(i = 0; i < num;i ++)
	{
		printf("%d * ",data[i]);
	}
}
