#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 128
#define NUM 10

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
		
		int ascend=0;
		if(n[0]<n[1])
			ascend=1;
		
		int temp=1;
		for(int i=0;i<index-1;i++)
		{
			
			if(ascend)
			{
				if(n[i]>=n[i+1] || n[i+1]-n[i]>3)
					temp=0;
					
			}
			else
			{				
				if(n[i]<=n[i+1] || n[i]-n[i+1]>3)
					temp=0;
				
			}
		}
		
		total += temp;
		
		
	}
	
	printf("%d\n",total);
	return 0;
}
