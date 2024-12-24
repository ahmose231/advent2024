#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 128
#define NUM 10

int valid(int n[], int len)
{
	int ascend=0;
	if(n[0]<n[1]) ascend=1;
	
	for(int i=0;i<len-1;i++)
	{
		
		if(ascend)
		{
			if(n[i]>=n[i+1] || n[i+1]-n[i]>3)
				return 0;
				
		}
		else
		{				
			if(n[i]<=n[i+1] || n[i]-n[i+1]>3)
				return 0;
			
		}
	}	
	
	return 1;
}

int check(int list[], int len)
{
	int newlist[len-1];
	int newindex=0;
	
	for(int i=0;i<len;i++)
	{
		newindex=0;
		for(int j=0;j<len;j++)
			if(i!=j)
				newlist[newindex++]=list[j];
		
		if(valid(newlist, newindex)) return 1;
	}
	
	return 0;
}


int main(void) {
	// your code goes here
	
	int total=0;
	
	char line[LEN];
	while(fgets(line,LEN,stdin)!=NULL)
	{
		char *token;
		token=strtok(line," ");
		int n[NUM];
		int index=0;
		while(token!=NULL)
		{
			n[index++]=atoi(token);
			token=strtok(NULL," ");
		}
		
		total += check(n, index);
		
		
	}
	
	printf("%d\n",total);
	return 0;
}
