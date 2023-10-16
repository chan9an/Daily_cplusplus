//
#include "bits/stdc++.h"
using namespace std;

#define int long long

double intersect(int m1, int c1, int m2, int c2){
	return (double)(c2-c1)/(m1-m2);
}
double intersect(pair<int,int> p1, pair<int,int> p2){
	return intersect(p1.first,p1.second,p2.first,p2.second);
}

bool better(pair<int,int> l1, pair<int,int> l2){
	if(l2.first >= l1.first && l2.second >= l1.second) return 1;
	else return 0;
}

int32_t main(){
	int n,p;
	cin>>n>>p;
	pair<int,int> ab[n+5];
	for(int i=1; i<=n; i++){
		cin>>ab[i].first>>ab[i].second;
	}	
	set<pair<int,int> > ss; //sorted in increasing A :)
	for(int i=1; i<=n; i++) ss.insert(ab[i]);
	
	deque<pair<int,int> > dq;
	dq.push_front({0,0});
	
	for(pair<int,int> ii : ss){
		pair<int,int> line = ii;
		while(dq.size() > 1){
			int s = dq.size();
			if (better(dq[s-1],line) || intersect(dq[s-1], line) < intersect(dq[s-2], line))
				dq.pop_back(); //removes useless line
			else break;
		}
		
		//for(pair<int,int> Tt : dq) cout<<Tt.first<<' '<<Tt.second<<' ';
		//cout<<endl;
		
		dq.push_back(line);
	}
	
	while(dq.size() >= 2){
		if(intersect(dq[0],dq[1]) < 0.0) dq.pop_front();
		else break;
	}
		
	set<pair<int,int> > ans;
	for(pair<int,int> i : dq){
		ans.insert(i);
		//cout<<i.first<<' '<<i.second<<endl;
	}
	
	int mxa=0,mxb=0;
	for(int i=1; i<=n; i++) mxa=max(mxa,ab[i].first);
	for(int i=1; i<=n; i++) mxb=max(mxb,ab[i].second);
	
	vector<int> output;
	for(int i=1; i<=n; i++){
		if(ans.find(ab[i]) != ans.end() || ab[i].first==mxa || ab[i].second==mxb) output.push_back(i);
	}
	
	cout<<output.size()<<endl;
	for(int i : output) cout<<i<<' ';
}
