#include <bits/stdc++.h>
#define pyes printf("YES\n")
#define pno printf("NO\n")
typedef long long int ll;
using namespace std;

void mergeSort2(ll *p,ll n,ll *r);
void merge2(ll *p,ll n1,ll *q,ll n2,ll *r,ll *s);
void arrayOutput(ll* a,ll n);
ll min(ll a,ll b);
ll max(ll a,ll b);
ll mod(ll a);
ll gcd(ll a,ll b);
ll lcm(ll a,ll b);
ll modadd(ll a,ll b);
ll modmul(ll a,ll b);
ll moddiv(ll a,ll b);
ll modexp(ll a,ll b);
ll modinv(ll a);
ll modncr(ll n,ll r);
ll modnpr(ll n,ll r);

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

ll min(ll a,ll b){
    if(a<=b) return a;
    else return b;
}

ll max(ll a,ll b){
    if(a>=b) return a;
    else return b;
}

ll mod(ll a){
    if(a<=0) return -a;
    else return a;
}

void arrayOutput(ll* a,ll n){
    for(ll i=0;i<n;i++) printf("%lld ",a[i]);
    printf("\n");
}

void vectorOuptut(vector<ll>& v){
    for(ll i=0;i<v.size();i++) printf("%lld ",v[i]);
    printf("\n");
}

void vectorOuptut(vector<bool>& v){
    for(ll i=0;i<v.size();i++) printf("%d ",v[i]);
    printf("\n");
}

void mergeSort2(ll *p,ll n,ll *r){
    if(n<=1) return;
    ll mid = n/2;

    mergeSort2(p,mid,r);
    mergeSort2(p+mid,n-mid,r+mid);
    merge2(p,mid,p+mid,n-mid,r,r+mid);
}

void merge2(ll *p,ll n1,ll *q,ll n2,ll *r,ll *s){
    ll i=0,j=0,k=0;
    ll A[n1+n2];
    ll B[n1+n2];
    while(i<n1 && j<n2){
        if((*(p+i)) < (*(q+j))){
            A[k] = (*(p+i));
            B[k] = (*(r+i));
            i++;
        }
        else{
            A[k] = (*(q+j));
            B[k] = (*(s+j));
            j++;
        }
        k++;
    }
    if(k!=n1+n2){
        if(i!=n1){
            while(i<n1){
                A[k] = (*(p+i));
                B[k] = (*(r+i));
                i++;
                k++;
            }
        }
        else{
            while(j<n2){
                A[k] = (*(q+j));
                B[k] = (*(s+j));
                j++;
                k++;
            }
        }
    }
    i=0;
    j=0;
    k=0;
    while(i<n1){
        (*(p+i)) = A[k];
        (*(r+i)) = B[k];
        i++;
        k++;
    }
    while(j<n2){
        (*(q+j)) = A[k];
        (*(s+j)) = B[k];
        j++;
        k++;
    }
}

ll zz=1000000007;

ll modadd(ll a,ll b){
    return ((a%zz)+(b%zz))%zz;
}

ll modmul(ll a,ll b){
    return ((a%zz)*(b%zz))%zz;
}

ll modexp(ll a,ll b){
    if(b==0) return 1%zz;
    if(b%2==0){
        ll u=modexp(a,b/2);
        return modmul(u,u);
    }
    else return modmul(a,modexp(a,b-1));
}

// if zz is prime
ll modinv(ll a){
    return modexp(a,zz-2);
}

ll moddiv(ll a,ll b){
    return modmul(a,modinv(b));
}

ll modncr(ll n,ll r){
    if(n<r) return 0;
    ll fact[n+1];
    if(r==0) return 1;
    fact[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=modmul(fact[i-1],i);
    }
    return modmul(modmul(fact[n],modinv(fact[r])),modinv(fact[n-r]));
}

ll modnpr(ll n,ll r){
    if(n<r) return 0;
    ll fact[n+1];
    if(r==0) return 1;
    fact[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=modmul(fact[i-1],i);
    }
    return modmul(fact[n],modinv(fact[n-r]));
}

const ll N=(1e5)*3;
vector<ll> graph[N+1];
bool vis[N+1];
ll h_leaf[N+1];         // height of nearest leaf in subtree
ll ans[N+1];
ll with_return[N+1];

ll dfs1(ll v,ll height){
    vis[v]=true;
    ll c=0,h=(1e9);
    for(auto child : graph[v]){
        if(vis[child]) continue;
        h=min(h,dfs1(child,height+1));
        c++;
    }
    if(c==0){
        h_leaf[v]=height;
        return height;
    }
    h_leaf[v]=h;
    return h;
}

void dfs(ll v,ll height,ll k){        // returns "with_return"
    vis[v]=true;
    ll m=(-1),sum=0,temp,c=0,mchild=0,mnr=(-1),mnrchild=0;
    ll maxi=0;
    for(auto child : graph[v]){
        if(vis[child]) continue;
        dfs(child,height+1,k);
        c++;
        if(h_leaf[child]-height<=k){
            with_return[v]+=with_return[child];
            sum+=with_return[child];
            if(ans[child]>m){
                m=ans[child];
                mchild=child;
            }
            maxi=max(maxi,ans[child]-with_return[child]);
        }
        else{
            if(ans[child]>mnr){
                mnr=ans[child];
                mnrchild=child;
            }
            maxi=max(maxi,ans[child]);
        }
    }
    if(c==0){
        ans[v]=1;
        with_return[v]=1;
        return;
    }
    ans[v]=with_return[v]+maxi;
    // if(mnr!=(-1)){
    //     ans[v]=sum+mnr;
    // }
    // else{
    //     ans[v]=sum+m-with_return[mchild];
    // }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,k;
        scanf("%lld",&n);
        scanf("%lld",&k);
        for(ll i=0;i<=n;i++){
            graph[i].clear();
            vis[i]=false;
            h_leaf[i]=n;
            ans[i]=with_return[i]=0;
        }
        for(ll i=0;i<n-1;i++){
            ll u,v;
            scanf("%lld",&u);
            scanf("%lld",&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs1(1,0);
        for(ll i=0;i<=n;i++) vis[i]=false;
        dfs(1,0,k);
        // arrayOutput(h_leaf+1,n);
        // arrayOutput(ans+1,n);
        // arrayOutput(with_return+1,n);
        printf("%lld\n",ans[1]);
    }
	return 0;
}
