#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double
using namespace std;
struct Matrix
{
    int arr[105][105]={};
    void iden()
    {
        for(int i=0;i<105;i++)
            arr[i][i]=1;
    }
    void clear()
    {
        memset(arr,0,sizeof(arr));
    }
};

int n;
int mod=42373;
Matrix mat;
Matrix multiply(Matrix res1,Matrix res2)
{
    Matrix final;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                final.arr[i][j]+=res1.arr[i][k]*res2.arr[k][j];
                final.arr[i][j]%=mod;
            }
    return final;
}
Matrix power(int y)
{
    Matrix res;
    res.iden();
    while (y > 0)
    {
        if((y & 1)==1)
            res=multiply(res,mat);
        y = y >> 1;
        mat=multiply(mat,mat);
    }
    return res;
}
int32_t main()
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat.arr[i][j];
            mat.arr[i][j]%=mod;
        }
    }
    int a,b,c;
    cin>>a>>b>>c;
    Matrix mul=power(c);
    cout<<mul.arr[a-1][b-1]%mod;
}
