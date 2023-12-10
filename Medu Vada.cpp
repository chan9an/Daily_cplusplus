#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

char graph[1007][1007];
bool vis[1007][1007];
pair<int, int> parent[1007][1007];
int r, c;
vector<pair<int, int> > ans;

void bfs(pair<int, int> start)
{
    int i = start.first, j = start.second;
    vis[i][j] = 1;
    parent[i][j] = make_pair(-1, -1);
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    while(!q.empty())
    {
        pair<int, int> k = q.front();
        int x = k.first, y = k.second;
        q.pop();
        if(x > 1 && graph[x-1][y] != '#' && vis[x-1][y] == 0)
        {
            vis[x-1][y] = 1;
            parent[x-1][y] = make_pair(x, y);
            q.push(make_pair(x-1, y));
        }
        if(x < r && graph[x+1][y] != '#' && vis[x+1][y] == 0)
        {
            vis[x+1][y] = 1;
            parent[x+1][y] = make_pair(x, y);
            q.push(make_pair(x+1, y));
        }
        if(y > 1 && graph[x][y-1] != '#' && vis[x][y-1] == 0)
        {
            vis[x][y-1] = 1;
            parent[x][y-1] = make_pair(x, y);
            q.push(make_pair(x, y-1));
        }
        if(y < c && graph[x][y+1] != '#' && vis[x][y+1] == 0)
        {
            vis[x][y+1] = 1;
            parent[x][y+1] = make_pair(x, y);
            q.push(make_pair(x, y+1));
        }
        if(x == 1 && graph[r][y] != '#' && vis[r][y] == 0)
        {
            vis[r][y] = 1;
            parent[r][y] = make_pair(x, y);
            q.push(make_pair(r, y));
        }
        if(x == r && graph[1][y] != '#' && vis[1][y] == 0)
        {
            vis[1][y] = 1;
            parent[1][y] = make_pair(x, y);
            q.push(make_pair(1, y));
        }
        if(y == 1 && graph[x][c] != '#' && vis[x][c] == 0)
        {
            vis[x][c] = 1;
            parent[x][c] = make_pair(x, y);
            q.push(make_pair(x, c));
        }
        if(y == c && graph[x][1] != '#' && vis[x][1] == 0)
        {
            vis[x][1] = 1;
            parent[x][1] = make_pair(x, y);
            q.push(make_pair(x, 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    int i, j, x, y;
    pair<int, int> start, fin;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 'M')
                start = make_pair(i, j);
            if(graph[i][j] == 'D')
                fin = make_pair(i, j);
        }
    }
    bfs(start);
    i = fin.first;
    j = fin.second;
    if(!vis[i][j])
        cout << "NO" << endl;
    else
    {
        while(i != -1 && j != -1)
        {
            ans.push_back(parent[i][j]);
            x = parent[i][j].first;
            y = parent[i][j].second;
            i = x;
            j = y;
        }
        ans.pop_back();
        for(i = 0; i < ans.size(); i++)
            graph[ans[i].first][ans[i].second] = 'x';
        graph[start.first][start.second] = 'M';
        cout << "YES" << endl;
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
                cout << graph[i][j];
            cout << endl;
        }
    }

    return 0;
}
