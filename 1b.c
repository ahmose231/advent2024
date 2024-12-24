#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 1000


int col[2][COL];
int check[2][COL];
int distance[COL];

int init()
{
	for(int i=0;i<COL;i++)
		check[0][i]=check[1][i]=1;
		
	return 0;
}

int smallest(int list)
{
	int small=99999;
	int smallindex;
	for(int i=0;i<COL;i++)
	{
		if(check[list][i])
			if(col[list][i]<small)
			{
				small=col[list][i];
				smallindex=i;
			}
				
	}
	
	check[list][smallindex]=0;
	return small;
}

int main(void) {
	// your code goes here
	init();
	char *token;
	char line[64];
	int index=0;
	for(int i=0;i<COL;i++)
	{
		fgets(line,64,stdin);
		
		token=strtok(line,"   ");
		col[0][index]=atoi(token);
		
		token=strtok(NULL,"   ");
		col[1][index]=atoi(token);
		
		index++;
	}
	
	
	for(int i=0;i<COL;i++)
	{
		distance[i] = smallest(0) - smallest(1);
		if(distance[i]<0)
			distance[i] *= -1;
		
	}
	
	
	int m[COL];
	for(int i=0;i<COL;i++)
		m[i]=0;
		
	for(int i=0;i<COL;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(col[0][i]==col[1][j])
				m[i]++;
		}
		m[i] *= col[0][i];
	}
	
	int sum;
	sum=0;
	for(int i=0;i<COL;i++)
		sum+=m[i];
	
	
	printf("%d\n",sum);
	
	return 0;
}


