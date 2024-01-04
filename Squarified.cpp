#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N=1e7+100,M=1e9+7;
int a[N], d[N]={0,1};


int main() {
    for(int i =2;i<N;++i){
        if(d[i]) continue;
        for(int j = i;j<N; j+=i) d[j]=i;
    }
	int t; scanf("%d",&t);
	while(t--){
    	int n; scanf("%d",&n);
	    for(int i=0;i<n;++i) {
	        scanf("%d",&a[i]);
	    }
	    
	    for(int i=0;i<n;++i){
	        int v=a[i],x=1;
	        while(d[v]!=v){
	            int cn = 0, j =d[v];
	            while((v%j)==0) {v/=j; ++cn;}
	            if(cn&1) x*=j;
	        }
	        if(v>1) x*=v;
	        a[i]=x;
	    }


        sort(a,a+n);
	    int cn = 1,ans=0;
	    for(int j=1;j<=n;++j){
	        if(j==n||a[j]>a[j-1]){
	            if(a[j-1]>1)  ans=max(ans,cn); 
	            cn=1;
	        }
	        else{
	            ++cn;
	        }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
