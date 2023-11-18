
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
    
    int n; 
    cin >> n;
    
    vector<string> s;
    
    string tmp;
    while(getline(cin,tmp)){
        s.push_back(tmp);
    }
    // for(int i=0; i<n; i++){
    //     string tmp;
    //     getline(cin, tmp);
    //     s[i] = tmp;
    // }
    
    unordered_set<char> punct;
    punct.insert('\'');
    punct.insert('.');
    punct.insert(',');
    punct.insert(';');
    punct.insert(':');
    punct.insert(' ');
    punct.insert('\n');
    
    set<string> words;
    for(auto str : s){
        string consec="";
        for(auto ch : str){
            if(punct.find(ch)!=punct.end()){
                if(consec.length()>0) words.insert(consec);
                consec = "";
            }
            else{
                consec+= (char) tolower(ch);
            }
        }
    }
    cout << words.size() << endl;

    for(auto word: words){
        cout << word << endl;
    }
    return 0;
}
