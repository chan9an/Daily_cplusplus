
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long int

int n;
vector<pair<int,int>> vp;

int memo[151][90000];

int dp(int index,int diff){
        
        if(index==n){
                return abs(diff-45000);
        }
        
        int x=vp[index].first;
        int y=vp[index].second;
        
        int &ans=memo[index][diff];
        if(ans!=-1)return ans;
        
        ans=90000;
        
        ans=min(dp(index+1,diff+x-y),dp(index+1,diff+y-x));
        
        return ans;
}

void solve(){
    
    cin>>n;
    for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            vp.push_back({x,y});
    }
    
    memset(memo,-1,sizeof(memo));
    
    int ans=dp(0,45000);
    
    cout<<ans<<endl;
    return ;
}

int main() {
	// your code goes here
    int t=1;
//     cin>>t;
    for(int tc=1;tc<=t;tc++){
        //cout<<"Case #"<<t<<": ";
        solve();
    }
    
    
	return 0;
}
