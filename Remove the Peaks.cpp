#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
 
using namespace std;
 
#define _int64 long long
#define mo 1000000007


#define faclim 310000

_int64 fac[faclim];
_int64 invfac[faclim];

_int64 pow1(int x,int y)
{
	int i;
	_int64 ret;
	ret=1;
	for (i=30;i>=0;i--)
	{
		ret=ret*ret%mo;
		if (((1<<i)&y)!=0) ret=ret*x%mo;
	}
	return ret;
}
_int64 inv(int x)
{
	return pow1(x,mo-2);
}

int a[1100000];
int can[1100000];
int p[1100000];
vector<int> ch[1100000];
_int64 cnt[1100000];
_int64 sum[1100000];
_int64 subtot[1100000];

void predoit(int n)
{
	int i,mi;
	vector<int> d;
	d.clear();
	for (i=0;i<n;i++)
	{
		mi=(1<<30);
		while ((d.size()>0)&&(d.back()>a[i]))
		{
			mi=min(mi,d.back());
			d.pop_back();
		}
		if (d.size()==0) can[a[i]]=0;
		else
		{
			//cerr<<"a[i],mi:"<<a[i]<<" "<<mi<<endl;
			if (mi!=(1<<30)) p[mi]=a[i];
		}
		d.push_back(a[i]);
	}

}

void doit(int x)
{
	int i,y;
	for (i=0;i<ch[x].size();i++)
	{
		y=ch[x][i];
		doit(y);
	}

	cnt[x]=1;
	sum[x]=0;

	for (i=0;i<ch[x].size();i++)
	{
		y=ch[x][i];
		sum[x]=sum[x]*cnt[y]+sum[y]*cnt[x];
		sum[x]%=mo;
		cnt[x]*=cnt[y];
		cnt[x]%=mo;
	}


	/*
	if ((cnt[x]==1)&&(sum[x]==0))
	{
		cnt[x]=0;
	}
	*/

	subtot[x]=x;
	for (i=0;i<ch[x].size();i++)
	{
		y=ch[x][i];
		subtot[x]+=subtot[y];
		subtot[x]%=mo;
	}
	cnt[x]++;
	cnt[x]%=mo;
	sum[x]+=subtot[x];
	sum[x]%=mo;
	//cerr<<"x,cnt,sum:"<<x<<" "<<cnt[x]<<" "<<sum[x]<<endl;
}

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1;
	_int64 ans,anscnt;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
		{
			can[i]=1;
			p[i]=-1;
		}
		predoit(n);
		reverse(a,a+n);
		predoit(n);
		for (i=1;i<=n;i++)
			ch[i].clear();
		for (i=1;i<=n;i++)
		{
			if (can[p[i]]==0) p[i]=-1;
			if (can[i]==0) continue;
			if (p[i]!=-1)
				ch[p[i]].push_back(i);
		}
		ans=0;
		anscnt=1;
		for (i=1;i<=n;i++)
		{
			//cerr<<"i:"<<i<<" "<<can[i]<<" "<<p[i]<<endl;
			if (can[i]==0) continue;
			if (p[i]!=-1) continue;
			doit(i);
			ans=sum[i]*anscnt+cnt[i]*ans;
			ans%=mo;
			anscnt*=cnt[i];
			anscnt%=mo;
		}
		printf("%lld\n",ans);
	}
}
