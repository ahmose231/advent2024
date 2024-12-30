#include <stdio.h>
#include <string.h>

#define LEN 57

int m[LEN][LEN];
int count;
int nines[LEN*LEN][2];
int ninecount;

int markcheck[LEN*LEN];

int clear_markcheck()
{
	for(int i=0;i<ninecount;i++)
		markcheck[i]=0;
	return 0;
}

int available(int i, int j)
{
	if((i>=0 || i<LEN) && (j>=0 && j<LEN))
		return 1;
	return 0;
}

void marknine(int i, int j)
{
	for(int a=0;a<ninecount;a++)
		if(nines[a][0]==i && nines[a][1]==j)
			markcheck[a]=1;
	return;
}

int scan_markcheck(int i, int j)
{
	for(int a=0;a<ninecount;a++)
		if(markcheck[a])
			if(nines[a][0]==i && nines[a][1]==j)
				return 1;
	return 0;
}


int travel(int i, int j)
{
	if(m[i][j]=='9') 
	{
		if(scan_markcheck(i,j))
			return 1;
		count++;
		marknine(i,j);
		return 1;
	}
	
	if(available(i-1,j))
		if(m[i-1][j]==m[i][j]+1)
			travel(i-1,j);
			
	if(available(i,j-1))
		if(m[i][j-1]==m[i][j]+1)
			travel(i,j-1);
			
	if(available(i+1,j))
		if(m[i+1][j]==m[i][j]+1)
			travel(i+1,j);
			
	if(available(i,j+1))
		if(m[i][j+1]==m[i][j]+1)
			travel(i,j+1);
	
	return 0;
	
}


int newtrail(int i, int j)
{
	clear_markcheck();
	count=0;
	travel(i,j);
	
	return count;
}

int main(void) {


	char line[LEN+2];
	int k=0;
	while(fgets(line,LEN+2,stdin)!=NULL)
	{
		for(int i=0;i<LEN;i++)
			m[k][i]=line[i];
	
		k++;
	}
	
	for(int i=0;i<LEN;i++)
	{
		for(int j=0;j<LEN;j++)
		{
			if(m[i][j]=='9')
			{
				nines[ninecount][0]=i;
				nines[ninecount][1]=j;
				ninecount++;
			}
		}
	}
	
	int sum=0;
	for(int i=0;i<LEN;i++)
	{
		for(int j=0;j<LEN;j++)
		{
			if(m[i][j]=='0')
			{
				sum += newtrail(i,j);
			}
			
		}

		
	}
	
	printf("%d\n",sum);
	return 0;
}
