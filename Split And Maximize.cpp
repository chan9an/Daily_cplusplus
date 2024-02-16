#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(auto &i:arr)cin>>i;
	    
	    vector<int>count(60,0);
	    for(auto i:arr){
	        for(int j=0;j<60;j++){
	            count[j] += i&1;
	            i/=2;
	        }
	    }
	    
	    int ans = 0;
	    int flag = 0;
	    for(int i=59;i>0;i--){
	        if(count[i]>1 && count[i]%2==0)flag = 1;
	        if(flag||(count[i]&1))ans = ans|(1ll<<i);
	    }
	    ans = ans | (count[0]&1);
	    cout<<ans<<endl;
	}
	return 0;
}
