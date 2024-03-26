#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int T,n,k,a[N],pri[70],ans,ID[70];
vector<int> vec[1000000],prime;
bool check(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int ksm(int a,int b){
    int ret=1;
    while(b){
        if(b&1) ret=(ll)ret*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ret;
}
void dfs(int now,int K,int id,int step){
    int tmp=id^(1<<now),num=prime[now];
    //printf("!%d %d\n",tmp,num);
    for(auto x:vec[tmp]){
        if(x%num==0) vec[id].pb(x);
    }
    if(step&1){
        ans=((ll)ans-ksm(2,vec[id].size())+1+mod)%mod;
    }
    else{
        ans=((ll)ans+ksm(2,vec[id].size())-1+mod)%mod;
    }
    for(int i=now+1;i<K;i++) dfs(i,K,id^(1<<i),step+1);
}
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(pri[k]==0){
        printf("0\n");
        return;
    }
    //printf("%d\n",1<<k);
    for(int i=0;i<(1<<ID[k]);i++) vec[i].clear();
    for(int i=1;i<=n;i++){
        if(a[i]%k==0) vec[0].pb(a[i]);
    }
    ans=(ksm(2,vec[0].size())-1+mod)%mod;
    for(int i=0;i<ID[k];i++){
        //printf("?%d %d\n",prime[i],1<<i);
        dfs(i,ID[k],1<<i,1);
    }
    printf("%d\n",ans);
}
signed main(){
    for(int i=2;i<=60;i++){
        if(check(i)){
            pri[i]=1;ID[i]=prime.size();
            prime.pb(i);
        }
        else pri[i]=0;
    }
    scanf("%d",&T);
    while(T--) solve();    
    return 0;
}
