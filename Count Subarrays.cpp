#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=100000;

int main(){
   ll t;cin>>t;
   while(t--){
    ll n;cin>>n;
    vector<ll>v(n); ll sum=0; vector<ll>p; vector<ll>ans(n,0);
    for(ll i=0;i<n;i++){
      cin>>v[i];
     }
     for(ll i=0;i<n;i++){
      sum=0;
      for(ll j=i;j<n;j++){
         sum+=v[j];
         if(sum>n)break;
           ans[sum-1]++;
      }
     } 
      
      for(ll i=0;i<n;i++)cout<<ans[i]<<" ";
         cout<<endl;
      } 
}
