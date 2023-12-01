#include<stdio.h>

int main(void)

{
    int rows,columns;
    scanf("%d%d",&rows,&columns);
    long int a[1000+1][1000+1]={0};
    for(int i=1;i<=rows;i++)
    {
        long int s=0,x;
        for(int j=1;j<=columns;j++)
        {
            scanf("%ld",&x);
            s+=x;
            a[i][j]=a[i-1][j]+s;
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%ld\n",a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]);
    }
}
