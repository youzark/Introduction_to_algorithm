#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int partition(int* a, int l, int r) 
{
	int x = a[r], i = l - 1;
	int mid;
	int j = l;
	for(;j < r ; j ++ )
	{
		if(a[j] <= x)
		{
			mid = a[++i];
			a[i] = a[j];
			a[j] = mid;
		}
	}
	mid = a [i + 1];
	a[i + 1] = a[r];
	a[r] = mid;
	return i + 1;
}

int randomPartition(int* a, int l, int r) 
{
	int i = rand()%(r - l+ 1) + l;
	int t = a[i];
	a[i] = a[r];
	a[r] =t;
	return partition(a ,l ,r);
}

int quickSelect(int* a, int l, int r, int index) 
{
	int q = randomPartition(a,l,r);
	if (q == index)
	{
		return a[q];
	}
	else 
	{
		return q < index ? quickSelect(a,q + 1,r,index) : quickSelect(a,l,q-1,index);
	}
}

int main()
{
	int numsSize,k,i;
	int * nums;
	scanf("%d%d",&numsSize,&k);
	nums = (int*)malloc(numsSize * sizeof(int));
	for(i = 0; i < numsSize; i++)
	{
		scanf("%d",&nums[i]);
	}
	srand(time(0));
	printf("%d\n",quickSelect(nums,0,numsSize - 1,k-1));
}

