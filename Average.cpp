/*
||  //                  O O O
|| //                 O 
||//                O       
|||                  O 
||\\                   O 
|| \\                O
||  \\         O O O  
                        
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fill(a,val) memset(a,val,sizeof(a))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(x.begin(), x.end())
#define arrSort(x,n) sort(x,x+n)
#define rarrSort(x,n) sort(x,x+n,greater<ll>())
#define rsortall(x) sort(x.begin(), x.end(),greater<ll>())
#define seq(i,a,b) for(int i=0; i<a; i+=b)
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define vout(v) for (ll i = 0; i < v.size(); i++) cout << v[i] << " ";cout << endl;
#define aout(v) for (ll i = 0; i < v.length(); i++) cout << v[i] << " ";cout << endl;
#define all(x) x.begin(), x.end()
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b,a%b);}
 
bool isSquare(ll n)
{
    ll temp=sqrt(n);
    return temp*temp==n;
}
 
string dectoBinary(ll n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
 
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    ll base = 1; 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    } 
    return dec_value;
}


void solve (ll testcase)
{
    
    
    
    
}
int main()
{
    fio();
 
    // ll t =1;
    // // cin >> t;
    // ll t_t= 1ll;
 
    // while(t_t <=t)
    // {
    //     solve(t_t);
    //     t_t++;
    // }
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    unordered_map<int,int> dupli;
    for(int i=0; i<n; i++){
        cin >> a[i];
        dupli[a[i]]++;
    }
    int ans = 0;
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++){
        
        if(dupli.find(a[i])!=dupli.end() && dupli[a[i]]!=1){
            ans+= dupli[a[i]];
            dupli[a[i]]=0;
        }
        else{
            bool found = false;
            int l=0, r=n-1; 
            int expected = 2*a[i];
            while(l<r){
                
                if((a[l]+a[r])>expected){
                    r--;
                }
                else if((a[l]+a[r])<expected){
                    l++;
                }
                else{
                    // cout << l << " " << r << " " << expected<< endl;
                    found=true;
                    break;
                }
            }
            if((l<r) && ((a[l]+a[r])==expected)){
                found = true;
                // cout << l << " " << r << " " << expected<< endl;
            }
            
            if(found) ans++;
        }
    }
    cout << ans;
    return 0;
    
    
    
    
}
