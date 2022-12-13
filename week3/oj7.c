#include<stdio.h>
int main()
{
	int i,n;
	char a;
	char str[100]={0};
	 scanf("%s",&str[i]);
	for(i=0;i<100;i++)
	{
	    if(str[i]==0)
	   	break;
    }
    n=i-1;
    if(str[n]=='y')
    {
    	str[n]='i';
    	str[n+1]='e';
    	str[n+2]='s';
	}else if(str[n]=='s'||str[n]=='x'||(str[n-1]=='c'&&str[n]=='h')||(str[n-1]=='s'&&str[n]=='h')){
		str[n+1]='e';
		str[n+2]='s';
	}else if(str[n]=='o'){
		str[n+1]='e';
		str[n+2]='s';
	}else str[n+1]='s';
	
	if(str[n+2]==0)
	{
		for(i=0;i<=n+1;i++)
		{
			printf("%c",str[i]);
		}
	}else {
		for(i=0;i<=n+2;i++)
		{
			printf("%c",str[i]);
		}
	}
    
    return 0;
}
