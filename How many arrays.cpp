#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define superSLOW ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=998244353;
const int inf=1e18;
void TxtIO(string name){
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int power(int a,int b){
    if(b==0)return 1;
    int temp=power(a,b/2);
    temp=(temp*temp)%mod;
    if(b%2==1){
        temp=(temp*a)%mod;
    }
    return temp;
}

int32_t main() {
	// your code goes hereTxtIO("");
	superSLOW;
	int t;cin>>t;
	while(t--){
	    int n,x;cin>>n>>x;
	    unordered_map<int,int>cnt;
	    for(int i=2;i<=sqrt(x);i++){
	        if(x%i==0){
	            while(x%i==0){
	                x/=i;
	                cnt[i]++;
	            }
	        }
	    }
	    if(x>1)cnt[x]=1;
	    int ans=0;
	    for(int l=1;l<=n;l++){
	        int res=1;
	        for(auto i:cnt){
	            int p=(power(1+i.ss,l)-power(i.ss,l))%mod;
	            while(p<0)p+=mod;
	            res=(res*p)%mod;
	        }
	        ans=(ans+res)%mod;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
