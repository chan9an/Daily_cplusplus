
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cmp(vector<int>&a,vector<int>&b){
	int k=min(a.size(),b.size());
	for(int i=0;i<k;i++){
		if(a[i]==b[i]) continue;
		return a[i]<b[i];
	}
	return a.size()<b.size();
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int i=0;
    vector<vector<int>> v;
    while(i<n){
		bool stop=0;
		vector<int> tmp;
		while(!stop){
			int x;
			cin>>x;
			if(x==-1) stop=1;
			else tmp.push_back(x);
		}
		v.push_back(tmp);
		i++;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout << endl;
    }
    return 0;
}
