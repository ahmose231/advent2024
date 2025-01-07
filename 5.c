#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINELEN 512
#define RULELEN 2048
#define ARRAYTOTAL 256
#define ARRAYLEN 128

int rule[RULELEN][2];
int array[ARRAYTOTAL][ARRAYLEN];
int arraylen[ARRAYTOTAL];
int ruleindex;
int arrayindex;

int check_for_rule(int a, int b)
{
	for(int i=0;i<ruleindex;i++)
	{
		if(rule[i][0] == a)
			if(rule[i][1] == b)
				return 1;
				
	}
	
	return 0;
}

int check_for_element(int whicharray, int elementplace)
{
	for(int i=elementplace+1;i<arraylen[whicharray];i++)
	{
		if(!check_for_rule(array[whicharray][elementplace], array[whicharray][i]))
			return 0;
	}
	
	return 1;
}

int check_for_array(int whicharray)
{
	for(int i=0;i<arraylen[whicharray]-1;i++)
	{
		if(!check_for_element(whicharray, i))
			return 0;
	}
	
	return 1;
}

int main(void) {
	char line[LINELEN];
	int part=1;
	while(fgets(line,LINELEN,stdin)!=NULL)
	{
		if(strlen(line)<2)
		{
			part--;
			continue;
		}
		
		if(part)
		{
			rule[ruleindex][0] = atoi(strtok(line,"|"));
			rule[ruleindex][1] = atoi(strtok(NULL,"|"));
			ruleindex++;
		
			
		} else {
			char *token;
			token = strtok(line,",");
			while(token!=NULL)
			{
				array[arrayindex][arraylen[arrayindex]++] = atoi(token);
				token = strtok(NULL,",");
				
			}
			
			arrayindex++;
		}
	}
	
	int sum=0;
	
	for(int i=0;i<arrayindex;i++)
	{
		if(check_for_array(i))
		{
			sum += array[i][arraylen[i]/2];
		}
	}
	
	printf("%d\n",sum);
	
	return 0;
}
