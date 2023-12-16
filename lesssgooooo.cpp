
#include "bits/stdc++.h"
#include <complex>
#include <fstream>
#define int long long
#define pb push_back

using namespace std;
int mod =  998244353;
int pow1(int n,int k){
    if(k<=0)return 1;
    int c=n;
    int ans=1;
    while(k){
        if(k%2)ans*=c;
        ans%=mod;
        c*=c;
        c%=mod;
        k>>=1;
    }
    return ans;
}

int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    int k=gcd(a,b);
    int c=b/k;
    return (a*c)%mod;
}
int fact[100010]={};
int ncr(int a,int b){
    if(b<0)return 1;
    if(a<b)return 1;
    if(b==0)return 1;
    int ans=1;
    ans*=fact[a];
    ans%=mod;
    ans*=pow1(fact[b],mod-2);
    ans%=mod;
    ans*=pow1(fact[a-b],mod-2);
    ans%=mod;
    return ans;
}
vector<vector<pair<int,int>>>v(2010,vector<pair<int,int>>());
void solve(){
    int m,x,y;
    cin>>m>>x>>y;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    int w[2010]={};
    memset(w,0x3f,sizeof(w));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>c>>b;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    q.emplace(0,x);
    w[x]=0;
    while(q.size()){
        auto t=q.top();
        
        q.pop();
        for(auto [a,b]:v[t.second]){
            
            if(w[a]<=t.first+b){
                continue;
            }
            else{
                w[a]=t.first+b;
                q.emplace(w[a],a);
            }
        }
    }
    
    if(w[y]>1e9){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<w[y]<<"\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    int T=1;
    //cin>>T;
    for(int _=0;_<T;_++){
        //cout<<"Case #"<<_+1<<": ";
        cout.precision(15);
        solve();
    }
    return 0;
}

