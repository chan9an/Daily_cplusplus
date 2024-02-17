#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m; cin>>n>>m;

    set<pair<int,int>> cells;
    map<pair<int,int>,int> vis;

    queue<pair<int,int>> q;
    for(int i=0; i<m; i++)
    {
        int u,v; cin>>u>>v;
        cells.insert({u,v});
        if(u==1 || v==n)
        {
            q.push({u,v});
            vis[{u,v}]=1;
        }
    }

    int dx[]= {-1,-1,-1,0,0,1,1,1};
    int dy[]= {0,1,-1,1,-1,0,1,-1};
    while(!q.empty())
    {
        auto curr= q.front();
        q.pop();

        int cx=curr.first,cy=curr.second;
        for(int i=0; i<8; i++)
        {
            int nx= cx+dx[i],ny= cy+dy[i];
            if(nx<1 || ny<1 || nx>n || ny>n) continue;
            else if(cells.find({nx,ny})==cells.end()) continue;
            else if(vis.find({nx,ny})!=vis.end()) continue;
            vis[{nx,ny}]=1;
            q.push({nx,ny});
        }
    }

    bool ok=true;
    for(auto &pr: cells)
    {
        if(pr.first==n || pr.second==1)
        {
            if(vis.find(pr)!=vis.end())
            {
                ok=false;
                break;
            }
        }
    }


    cout<<(ok?"YES":"NO")<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases=1;
    cin>>cases;
    while(cases--)
    {
        solve();
    }
    return 0;
}
