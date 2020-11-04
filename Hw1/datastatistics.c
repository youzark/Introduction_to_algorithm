#include <stdio.h>
#include <malloc.h>

void sort(int *data,int start,int end)
{
	int i,j;
	int temp;
	for(i = start + 1;i < end + 1;i ++)
	{
		temp = data[i];
		for(j = i-1;(j > start -1)&&(data[j] > temp);j --)
		{
			data[j + 1] = data[j];
		}
		data[j+1] = temp;
	}
}

int statistic(int  data[][1002],int totalnum)
{
	int scan,current= 0;
	for(scan = 1; scan < totalnum; scan ++)
	{
		if(data[0][scan] == data[0][current])
		{
			data[1][current] ++;
			data[1][scan] --;
		}
		else
		{
			current ++;
			data[0][current] = data[0][scan];
			data[1][current] = 1;
			if(current != scan)
			{
				data[1][scan] --;
			}
		}
	}
	return current + 1;
}

void printresult(int data[][1002],int datatype)
{
	int i,j;
	int temp0,temp1;
	for(i = 1;i < datatype;i ++)
	{
		temp1 = data[1][i];
		temp0 = data[0][i];
		for(j = i-1;(j > -1)&&(data[1][j] < temp1);j --)
		{
			data[1][j + 1] = data[1][j];
			data[0][j + 1] = data[0][j];
		}
		data[1][j+1] = temp1;
		data[0][j+1] = temp0;
	}
	for(i = 0;i < datatype;i ++)
	{
		printf("%d %d\n",data[0][i],data[1][i]);
	}
}



void main()
{
	int totalnum,i;
	int data[2][1002];
	int datatype;
	scanf("%d",&totalnum);
	for(i = 0;i < totalnum;i++)
	{
		scanf("%d",&data[0][i]);
		data[1][i] = 1;
	}
	sort(data[0],0,totalnum - 1);
	datatype = statistic(data,totalnum);
	printresult(data,datatype);
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
