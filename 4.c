#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 140

int m[MAX][MAX];
int total;

void checkfor(int i, int j)
{
	if(j+3<MAX)
		if(m[i][j+1]=='M'&&m[i][j+2]=='A'&&m[i][j+3]=='S')
			total++;
	if(i+3<MAX)
		if(m[i+1][j]=='M'&&m[i+2][j]=='A'&&m[i+3][j]=='S')
			total++;
	if(j-3>=0)
		if(m[i][j-1]=='M'&&m[i][j-2]=='A'&&m[i][j-3]=='S')
			total++;
	if(i-3>=0)
		if(m[i-1][j]=='M'&&m[i-2][j]=='A'&&m[i-3][j]=='S')
			total++;
	if(j+3<MAX && i+3<MAX)
		if(m[i+1][j+1]=='M'&&m[i+2][j+2]=='A'&&m[i+3][j+3]=='S')
			total++;
	if(j-3>=0 && i+3<MAX)
		if(m[i+1][j-1]=='M'&&m[i+2][j-2]=='A'&&m[i+3][j-3]=='S')
			total++;
	if(j-3>=0 && i-3>=0)
		if(m[i-1][j-1]=='M'&&m[i-2][j-2]=='A'&&m[i-3][j-3]=='S')
			total++;
	if(j+3<MAX && i-3>=0)
		if(m[i-1][j+1]=='M'&&m[i-2][j+2]=='A'&&m[i-3][j+3]=='S')
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
	
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(m[i][j]=='X')
				checkfor(i, j);

	
	printf("%d\n",total);
	
	return 0;
}
