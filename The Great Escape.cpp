#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    speedup
    int n, m;
    cin >> n >> m;
    vector<int> dist(n, INT_MAX);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    int s, e;
    cin >> s >> e;
    s--, e--;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u: graph[v]){
            if (dist[u] == INT_MAX){
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }
    if (dist[e] == INT_MAX){
        cout << 0 << endl;
    }else{
        cout << dist[e] << endl;
    }
    return 0;
}
