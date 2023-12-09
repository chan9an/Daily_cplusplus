#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ans=0;
	int visited[n] = {0}, distance[n], neighbor[n], costGrid[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>costGrid[i][j];
		}
	}
	memset(distance, 200000000,sizeof distance);
	memset(neighbor, -1,sizeof neighbor);
	visited[1]=1;
	for(int i=2;i<n;i++){
		distance[i]=costGrid[i][1];
		neighbor[i]=1;
	}
	for(int i=2;i<n;i++){
		int mindist=200000000,minindex;
		for(int j=1;j<n;j++){
			if(visited[j]==0 && mindist>distance[j]){
				mindist=distance[j];
				minindex=j;
			}
		}
		ans+=costGrid[minindex][neighbor[minindex]];
		visited[minindex]=1;
		for(int j=1;j<n;j++){
			if(visited[j]==0 && distance[j]>costGrid[j][minindex]){
				distance[j]=costGrid[j][minindex];
				neighbor[j]=minindex;
			}
		}
}
	cout << ans << endl;
	return 0;
}
