#include <bits/stdc++.h>
using namespace std;

const int N = 100;
pair<int,int> rows[N], cols[N];
int dis[N][N];
int n1,n2;
int cal(int time, int station, int dir, int type, int start, int max)
{
	while(dir == 1)
	{
		if(time <= start) 
		    return start+(station-1)*type;
		if(time <= start + (station-1)*type) 
		    return start + (station-1)*type;
		start += 2*(max-1)*type;
	}
	return cal(time, max-station+1, 1, type, start+(max-1)*type,max);
}

void bfs(int ux, int uy){
	queue<pair<int,int>> q;
	q.push({ux,uy});
	while(q.size())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(x != 1)
		{
			int d = cols[y].first + cal(dis[x][y], x, -1, cols[y].first, cols[y].second, n2);
			if(dis[x-1][y] == -1 || dis[x-1][y] > d) {
				q.push({x-1,y});
				dis[x-1][y] = d;
			}
		}
		if(x != n2)
		{
			int d = cols[y].first + cal(dis[x][y], x, 1, cols[y].first, cols[y].second, n2);
			if(dis[x+1][y] == -1 || dis[x+1][y] > d) {
				q.push({x+1,y});
				dis[x+1][y] = d;
			}
		}
		if(y != 1)
		{
			int d = rows[x].first + cal(dis[x][y], y, -1, rows[x].first, rows[x].second, n2);
			if(dis[x][y-1] == -1 || dis[x][y-1] > d) {
				q.push({x,y-1});
				dis[x][y-1] = d;
			}
		}
		if(y != n1)
		{
			int d = rows[x].first + cal(dis[x][y], y, 1, rows[x].first, rows[x].second, n2);
			if(dis[x][y+1] == -1 || dis[x][y+1] > d) {
				q.push({x,y+1});
				dis[x][y+1] = d;
			}
		}
	}
}

int main(){
    // your code goes here
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n2 >> n1;
	for(int i=1; i<=n2; i++) {
		char b;
		int st;
		cin >> b >> st;
		int speed;
		if(b=='F') speed = 1;
		else if(b=='O') speed = 2;
		else speed = 3;
		rows[i] = {speed, st};
	}
	for(int i=1; i<=n1; i++){
		char b;
		int st;
		cin >> b >> st;
		int speed;
		if(b=='F') speed = 1;
		else if (b=='O') speed = 2;
		else speed = 3;
		cols[i] = {speed, st};
	}
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	memset(dis, -1 ,sizeof(dis));
	dis[a][b] = c;
	bfs(a,b);
	cout << dis[d][e] << '\n';
	return 0;
}
