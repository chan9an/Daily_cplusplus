#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
vvi is(2005,vi(2005));
bool cmp(int a,int b)
{
    return is[a][b] == 1;
}
int main()
{
    int n;
    cin>>n;
    vi a(n);
    for (int i = 0;i<n;i++)a[i] = i;
    for (int i = 0;i<n;i++){
        int x;
        cin>>x;
        while (x--){
            int y;
            cin>>y;
            y--;
            is[i][y] = 1;
        }
    }
    sort(a.begin(),a.end(),cmp);
    cout<<"YES"<<endl;for (auto it:a)cout<<it + 1<<" ";
    return 0;
}
