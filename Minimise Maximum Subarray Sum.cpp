#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x==1){
        cout<<1<<endl;
        return;
    }
    if(x<= (y+1) ) {
        cout<<1<<endl;
        return;
    }
    
    int ans = (x+y)/(y+1);
    int ans2 = x-2*y;
    cout<<max(ans,ans2)<<endl;
    
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--) solve();
}
