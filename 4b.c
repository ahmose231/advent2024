#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 140

int m[MAX][MAX];
int total;

void checkfor(int i, int j)
{
	if(m[i-1][j-1]=='M'&&m[i+1][j+1]=='S' || m[i-1][j-1]=='S'&&m[i+1][j+1]=='M')
		if(m[i+1][j-1]=='M'&&m[i-1][j+1]=='S' || m[i+1][j-1]=='S'&&m[i-1][j+1]=='M')
			total++;
}

int main(void) {
	// your code goes here
	
	int rowcount=0;
	int linecount=0;
	int c;
	c=fgetc(stdin);
	while(c!=EOF)
	{
		if(c=='\n')
		{
			rowcount=0;
			linecount++;
			if(linecount==MAX)
				break;
		}
		else
			m[linecount][rowcount++]=c;
		
		c=fgetc(stdin);
	}
	
	for(int i=1;i<MAX-1;i++)
		for(int j=1;j<MAX-1;j++)
			if(m[i][j]=='A')
				checkfor(i, j);

	
	printf("%d\n",total);
	
	return 0;
}
