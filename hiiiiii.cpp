#include<stdio.h>
int main()
{
    long long a;
    int N;
    int len[10],i,max;
    scanf("%d",&N);
    for (i=0;i<10;i++)
    len[i]=0;
    while(N--)
    {
    	scanf("%lld",&a);
    	int digit[10]={0};
    	while(a!=0)
    	{
    		digit[a%10]=1;
    		a/=10;
    	}
    	max=1;
    	for(i=0;i<10;i++) 
		if (digit[i]==1&&len[i]>=max)
    		max=len[i]+1;
    		for(i=0;i<10;i++) 
			if(digit[i]==1)
    			len[i]=max;
    }
    max=len[0];
    for(i=1;i<10;i++) 
	if(len[i]>max)
    	max=len[i];
    printf("%d\n",max);
    return 0;
}
