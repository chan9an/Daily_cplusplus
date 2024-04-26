#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N=5*1e5+1,M=1e9+7;

typedef pair<int,int> pii;
pii a[N]; int cc[N];

int main() {
	int t; scanf("%d",&t);
	while(t--){
	    int n; scanf("%d",&n);
	    for(int i=0,j=0;i<n;++i){
	        cc[i]=0;
	        for(int k=0;k<2;++k){
	            int v; scanf("%d",&v);
	            a[j++]={v,i};
	        }
	        
	    }
	    sort(a,a+2*n);
	    int ans = 2*1e9,cn=0;
	    for(int i=0;i<2*n;++i){
	        if(++cc[a[i].second]==1) ++cn;
	        if(a[i].second!=a[i-1].second){
	            if(cn>=n){
	                ans=min(ans,a[i].first-a[i-1].first);
	            }
	        }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
