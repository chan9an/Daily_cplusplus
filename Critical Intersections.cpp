#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent;
vector<int> start;
vector<int> endTime;
vector<int> low;
vector<int> child;
vector<bool> isArticulationPoint;
int myTime = 0;

void dfs(int node)
{
    start[node] = myTime++;
    for(auto i : adj[node])
    {
        if(start[i]==-1)
        {
            child[node]++;
            myTime++;
            parent[i] = node;
            dfs(i);
            if(parent[node]!=-1 && low[i]>=start[node])
            {
                // cout<<node<<" ART "<<i<<"\n";
                isArticulationPoint[node] = true;
            }
            low[node] = min(low[node], low[i]);
        }
        else
            low[node] = min(low[node], start[i]);
    }
    myTime++;
    endTime[node] = myTime++;
    if(parent[node]==-1 && child[node]>1)
    {
        // cout<<node<<" is Root\n";
        isArticulationPoint[node] = true;
    }
}

int32_t main() 
{
    cin>>n>>m;
    adj = vector<vector<int>> (n);
    parent = start = endTime = vector<int> (n, -1);
    child = vector<int> (n, 0);
    low = vector<int> (n, INT_MAX);
    isArticulationPoint = vector<bool> (n, false);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++)
    {
        if(start[i]==-1)
        {
            myTime++;
            dfs(i);
        }
    }
    
    // for(int i=0; i<n; i++)
    // {
    //     cout<<i+1<<": "<<start[i]<<" "<<endTime[i]<<" "<<low[i]<<"\n";
    // }
    
    int ans = 0;
    for(auto i : isArticulationPoint)
        if(i) ans++;
    cout<<ans<<"\n";
    for(int i=0; i<n; i++)
        if(isArticulationPoint[i]) cout<<i+1<<"\n";
	return 0;
}
