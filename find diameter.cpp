#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

int dijkstra(int i, int n, vector<iPair> * adj)
{
    vector<int> dist(n, INF);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(0, i));
    dist[i] = 0;
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        for (auto y : adj[x]) {
            if(y.second + dist[x] < dist[y.first])
            {
                dist[y.first] = y.second + dist[x];
                pq.push(make_pair(dist[y.first], y.first));
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main() {
    int t, n, x;
    vector<iPair> adj[2005];
    vector<iPair> a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.clear();
        for (int i = 0; i < n; i++) {
            cin>>x;
            a.push_back(make_pair(x, i));
            adj[i].clear();
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            adj[i].push_back(make_pair(i - 1, 1));
            adj[i - 1].push_back(make_pair(i, 1));
            int w = a[i].first - a[i - 1].first;
            int u = a[i - 1].second;
            int v = a[i].second;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            int ans = dijkstra(i, n, adj);
            if(ans > max)
            {
                max = ans;
            }
        }
        cout<<max<<endl;
    }
	return 0;
}
