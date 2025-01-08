#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEN 130

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3


char map[LEN][LEN];
char map2[LEN][LEN];
int steps=0;
int dir=UP;
int firststep=1;

int nextstep(int i, int j);
void walk(int i, int j);


int nextstep(int i, int j)
{
	switch(dir)
	{
		case UP:
		if(i-1<0) return 0;
		if(map[i-1][j]=='#')
			return 1;
		break;
		
		case RIGHT:
		if(j+1>=LEN) return 0;
		if(map[i][j+1]=='#')
			return 1;		
		break;
		
		case DOWN:
		if(i+1>=LEN) return 0;
		if(map[i+1][j]=='#')
			return 1;	
		break;
		
		case LEFT:
		if(j-1<0) return 0;
		if(map[i][j-1]=='#')
			return 1;
		break;
	}
	
	return 2;
}

void walk(int i, int j)
{
	if(!firststep)
	{
		if(map2[i][j]!='X')
			steps++;
		map2[i][j]='X';
	}
	else
		firststep=0;
		
	int next = nextstep(i, j);
	
	if(next==0) return;
	if(next==1)
	{
		dir = (dir+1)%4;
		walk(i, j);
		return;
	}

	switch(dir)
	{
		case UP:
		walk(i-1, j);
		break;
		
		case RIGHT:
		walk(i, j+1);
		break;
		
		case DOWN:
		walk(i+1, j);
		break;
		
		case LEFT:
		walk(i, j-1);
		break;
	}
	
	return;
}

int main(void) {
	char line[LEN+2];
	for(int i=0;i<LEN;i++)
	{
		fgets(line,LEN+2,stdin);
		strncpy(map[i], line, LEN);
		strncpy(map2[i], line, LEN);
	}
	
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
		{
			if(map[i][j] != '.' && map[i][j] != '#')
			{
				walk(i, j);
			}	
		}
	

	printf("%d\n", steps);
	

	return 0;
}
