#include <bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define printy cout<<"YES"<<endl;
#define printn cout<<"NO"<<endl;
using namespace std;

ll dfs2(ll u,ll par, vector <ll>adj[],ll up,vector < vector < ll > >&dp,vector <ll>&a){
        
       dp[u][0]=a[u]-up;
       
       for(auto v:adj[u]){
           if(v!=par){
               dp[u][0]+=max(0ll,dfs2(v,u,adj,up+1,dp,a));
           }
       }
       
       return dp[u][0];
}
ll dfs3(ll u,ll par, vector <ll>adj[],ll up,vector < vector < ll > >&dp,vector <ll>&a){
        
       dp[u][1]=a[u]-up+1;
       
       for(auto v:adj[u]){
           if(v!=par){
               dp[u][1]+=max(0ll,dfs3(v,u,adj,up+1,dp,a));
           }
       }
       
       return dp[u][1];
}


void dfs1(ll u,ll par,ll ex,ll sum, vector <ll>adj[],ll up,vector < vector < ll > >&dp,vector <ll>&a,vector <ll>&ans){
      
         ll t_mp=0;
       //  cout<<u<<" "<<dp[u][1]<<" "<<sum<<" "<<ex<<" "<<endl;
          ans[u]= dp[u][1]+sum+ex;
       
       for(auto v:adj[u]){
           if(v!=par){
               t_mp+=max(0ll,dp[v][0]);
           }
       }
       for(auto v:adj[u]){
           if(v!=par){
               dfs1(v,u,t_mp-max(0ll,dp[v][0]),sum+a[u]-up+ex,adj,up+1,dp,a,ans);
           }
       }
       
}
int main() {
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            vector< ll >a(n);
            for(auto &e:a){
                cin>>e;
            }
            vector <ll> adj[n];
            for(ll i=0;i<n-1;i++){
                ll u,v;
                cin>>u>>v;
                u--;
                v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector <ll >ans(n,0);
            vector < vector <ll > >dp(n, vector <ll >( 2,-1) );
            dfs2(0,-1,adj,0,dp,a);
            dfs3(0,-1,adj,0,dp,a);
            
            dfs1(0,-1,0,0,adj,0,dp,a,ans);
            for(int i=1;i<n;i++){  cout<<max(ans[i],dp[0][0])<<" ";  }    cout<<"\n";           
        }
}
