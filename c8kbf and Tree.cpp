

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define hashmap unordered_map<int,int> hash
#define hashset unordered_set<int> hash
#define createFrequencyTable for(int i=0;i<n;i++) hash[arr[i]]++;
#define setArray for(int i=0;i<n;i++) hash.insert(arr[i])
#define presentInSet (hash.find(a)!=hash.end())
#define pb push_back
#define min_heap priority_queue <int, vector<int>, greater<int>>
#define max_heap priority_queue<int>
#define arrayInput for(int i=0;i<n;i++) cin>>arr[i]
#define nahi cout<<"NO"<<endl
#define haan cout<<"YES"<<endl
#define sortArray sort(arr,arr+n)

void helper(vector<vector<int>>adjacensyMatrix[],int node,vector<int>&vis,vector<int>&dis)
{ 
    vis[node]=1; 
    for(auto x:adjacensyMatrix[node])
    { 
        if(!vis[x[0]])
        { 
            dis[x[0]]=dis[node]^x[1]; 
            helper(adjacensyMatrix,x[0],vis,dis); 
        } 
    } 
} 
 
 
void solve() 
{ 
  int n; 
  cin>>n; 
  vector<vector<int>>adjacensyMatrix[n]; 
  for(int i=0;i<n-1;i++)
  { 
    int u,v,w; 
    cin>>u>>v>>w; 
    u--; v--; 
    adjacensyMatrix[u].push_back({v,w}); 
    adjacensyMatrix[v].push_back({u,w}); 
  } 
  vector<int>tempor(n),vis(n,0); 
  tempor[0]=0; 
  helper(adjacensyMatrix,0,vis,tempor); 
  map<int,vector<int>>mp; 
  for(int i=0;i<n;i++)  mp[tempor[i]].push_back(i); 
  for(auto x:mp)
  { 
    if(x.second.size()>1)
    { 
      int f=x.second[0]; 
        int s=x.second[1]; 
        if(f==0 and s==n-1)  cout<<1<<" "<<2<<" "<<2<<" "<<n-1<<endl; 
        else if(f==0)  cout<<1<<" "<<n-1<<" "<<s+1<<" "<<n-1<<endl; 
        else if(s==n-1) cout<<1<<" "<<f+1<<" "<<1<<" "<<s+1<<endl; 
        else cout<<1<<" "<<f+1<<" "<<1<<" "<<s+1<<endl; 
        return; 
    } 
} 
map<int,vector<vector<int>>>hash2; 
for(int i=0;i<n;i++) 
{ 
    for(int j=i+1;j<n;j++)
    { 
        hash2[tempor[i]^tempor[j]].push_back({i,j}); 
        if(hash2[tempor[i]^tempor[j]].size()>1)
        { 
            cout<<hash2[tempor[i]^tempor[j]][0][0]+1<<" "<<hash2[tempor[i]^tempor[j]][0][1]+1<<" "<<hash2[tempor[i]^tempor[j]][1][0]+1<<" "<<hash2[tempor[i]^tempor[j]][1][1]+1<<endl; 
            return; 
        } 
    } 
} 
cout<<-1<<endl; 
} 
int32_t main()
{ 
    int t=1;  cin>>t; 
    while(t--) solve();  
    return 0; 
}
