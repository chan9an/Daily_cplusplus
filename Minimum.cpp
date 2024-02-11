#include<bits/stdc++.h>
using namespace std;

#define endl                "\n"
#define read(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define int                 long long
#define ld                  long double
#define printv(v)           for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl; 
void google(int t) {cout << "Case #" << t << ": ";}
int bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}


const int mod = 998244353;

vector<int> func1(vector<int>&v){
    int n = v.size();
    
    vector<int>ans(n,n);
    stack<int>st;

    for(int i=0;i<n;i++){
       while((!st.empty()) and (v[st.top()]<v[i])){
          ans[st.top()] = i;
          st.pop();
       }
       st.push(i);
    }   
    return ans;
}

vector<int> func2(vector<int>&v){
    int n = v.size();

    vector<int>ans(n,-1);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        while((!st.empty()) and (v[st.top()]<v[i])){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}



void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    read(v);

    vector<int>psum1(n+1,0);
    vector<int>psum2(n+1,0);

    for(int i=0;i<n;i++){
        psum1[i+1] = (v[i]+psum1[i])%mod;
        psum2[i+1] = (psum2[i]+psum1[i+1])%mod;
    }  

    int sum1 = 0;
    

    if(k>0){
        int l = k-1;
        for(int i=0;i<n;i++){
            int mx = min((n-1),i+l-1);
            int num1 = (psum2[mx+1]-psum2[i]+mod)%mod;
            int num2 = (psum1[i]*((mx-i+1)))%mod;
            sum1 = (sum1+(num1-num2+mod)%mod)%mod;
        }
    }

  

    vector<int>vp;
    int curr_sum = 0;
    for(int i=0;i<n;i++){
        curr_sum += v[i];
        if(i<k){
           if(i==(k-1))vp.push_back(curr_sum); 
        }else{
           curr_sum -= v[i-k];
           vp.push_back(curr_sum);
        }
    }


    vector<int>vp1 = func1(vp);
    vector<int>vp2 = func2(vp);


    // printv(vp1);

    int sum2 = 0;
    for(int i=0;i<vp.size();i++){
        int left = i-vp2[i];
        int right = vp1[i]-i;
        int p = (left*right)%mod;
        int num = ((vp[i]%mod)*p)%mod;
        sum2 = (sum2+num)%mod;
    }

    int ans = (sum1+sum2)%mod;

    cout<<ans<<endl;






   







}







int32_t main(){
    fast_io;
    
    int q = 1;
    cin>>q;
    while(q--){
        solve();
    
    }

    return 0;
}
