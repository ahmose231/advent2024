#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 64

int main(void) {
	// your code goes here
	
	int c;
	char word[LEN];
	int index=0;
	int doing=1;
	
	long long int total=0;
	
	c=fgetc(stdin);
	while(c!=EOF)
	{
		int borked=0;
		if(c=='m')
		{
			index=0;
			int part=1;
			word[index++]=c;
			
			c=fgetc(stdin);
			if(c=='u')
			{
				word[index++]=c;
				c=fgetc(stdin);
				if(c=='l')
				{
					word[index++]=c;
					c=fgetc(stdin);
					if(c=='(')
					{
						word[index++]=c;
						do
						{
							c=fgetc(stdin);
							
							if(!(c<='9'&&c>='0'))
							{
								if(!((c==',' && part==1) || (c==')' && part==2)))
								{
									borked=1;
									break;
								}
									
								else
									part++;
							}
							word[index++]=c;
						} while(c!=')');
						word[index++]=c;
						if(word[index-2]==',') borked=1;
						if(part==1) borked=1;
						
						word[index]=0;
						
						int a,b;
						if(doing && !borked && sscanf(word, "mul(%d,%d)", &a, &b)==2)
						{
							total += a*b;
						}
						
					}
				}
			}
		}
		if(c=='d')
		{
			c=fgetc(stdin);
			if(c=='o')
			{
				c=fgetc(stdin);
				if(c=='(')
				{
					c=fgetc(stdin);
					if(c==')')
						doing=1;
				}
				if(c=='n')
				{
					c=fgetc(stdin);
					if(c=='\'')
					{
						c=fgetc(stdin);
						if(c=='t')
						{
							c=fgetc(stdin);
							if(c=='(')
							{
								c=fgetc(stdin);
								if(c==')')
									doing=0;
							}
						}
					}
				}
			}
		}
		c=fgetc(stdin);
	}
	
	printf("%lld\n",total);
	return 0;
}
