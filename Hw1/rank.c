#include <stdio.h>
void sort(int data[][251],int start,int end,int refer_index)
{
	int mid;
	if(start < end)
	{
		mid = (start + end)/2;
		sort(data,start,mid,refer_index);
		sort(data,mid+1,end,refer_index);
		merge(data,start,mid,end,refer_index);
	}
		
}

void merge(int **data,int start,int mid,int end,int refer_index)
{
	int ldata[4][130],rdata[4][130];
	int n1,n2,i,j,k,l;
	n1 = mid - start + 1;
	n2 = end - mid;
	for(l = 0;l < 4;l ++)
	{
		for(i = 0;i < n1;i++)
		{
			ldata[l][i] = *((int*)data + l*251 + i + start );
		}
		for(i = 0;i < n2;i++)
		{
			rdata[l][i] = *((int*)data + l*251 + n1 + i + start);
		}
	}
	ldata[refer_index][n1] =-1; 	
	rdata[refer_index][n2] =-1; 	
	i=0;
	j=0;
	for(k = start;k <= end ;k ++ )
	{
		if(ldata[refer_index][i] >= rdata[refer_index][j])
		{
			for(l = 0;l < 4;l++)
			{
				*((int*)data + l*251 + k) = ldata[l][i];
			}
			i ++;
		}
		else
		{
			for(l = 0;l < 4;l++)
			{
				*((int*)data + l*251 + k) = rdata[l][j];
			}
			j ++;
		}
	}
}

void main()
{
	int totalnum,i;
	int data[4][251];
	scanf("%d",&totalnum);
	for(i = 0;i < totalnum;i++)
	{
		scanf("%d",&data[0][i]);
		scanf("%d",&data[1][i]);
		scanf("%d",&data[2][i]);
		data[3][i] = data[2][i] + data[1][i];
	}
	sort(data,0,totalnum - 1,0);
	sort(data,0,totalnum - 1,2);
	sort(data,0,totalnum - 1,1);
	sort(data,0,totalnum - 1,3);
	for(i = 0;i < totalnum;i ++)
	{
		printf("%d ",data[0][i]);
	}
}

/*
	for(i = 0;i < totalnum;i++)
	{
		printf("\n num:%d",data[0][i]);
	}
	for(i = 0;i < totalnum;i++)
	{
		printf("\n num:%d times:%d",data[0][i],data[1][i]);
	}
*/
