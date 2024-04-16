#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
int t;
cin>>t;
while(t--){
   ll a,b;
   cin>>a>>b;
   if(a%b==0){
    cout<<"0\n";
    continue;
   }
   else{
    ll ans=0;
    ll ans2=0;
  for(int i=1;i<=max(a,b);i++){
    if(b-i>=1){
    if((a+i)%(b-i)==0){
        ans=i;
        break;
    }
    }
  }
   for(int i=1;i<=max(a,b);i++){
    if(a-i>=1){
    if((a-i)%(b+i)==0){
        ans2=i;
        break;
    }
    }
  }

if(ans&&ans2){
cout<<min(ans,ans2)<<endl;
}
else if(ans)
  cout<<ans<<endl;
  else if(ans2)
  cout<<ans<<endl;
   }
  
}



return 0;
}
