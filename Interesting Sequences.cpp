#include <bits/stdc++.h>
using namespace std;
#define rep(s,e,i) for (int i = s; i <= e; i++)

signed main(){int T;cin>>T;while(T--){int n,l,x,ans=0;
cin>>n>>l;pair<int,int>a[n];int dp[n];rep(0,n-1,i){cin>>x;a[i]={x,i};}
sort(a,a+n);rep(0,n-1,i){rep(i,n-1,j){
if(a[i].first==a[j].first){ans=max(ans,abs(a[i].second-a[j].second));}}}

int lo=0,hi=n,mid;
while(lo<=hi){mid=(lo+hi)/2;rep(0,n-1,i){dp[i]=1;}bool tr=0;
rep(1,n-1,i){rep(0,i-1,j){if(abs(a[i].second-a[j].second)>=mid){
dp[i]=max(dp[i],dp[j]+1);}}
if(dp[i]>=l){tr=1;ans=max(ans,mid);lo=mid+1;break;}}
if(tr==0){hi=mid-1;}}cout<<ans<<endl;}}
