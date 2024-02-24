#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("error.txt","w",stdout);
   #endif
      
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1),k(n+1);
        for(int i=0;i<n;i++) cin >> a[i+1];
        for(int i=0;i<n;i++) cin >> k[i+1];
        vector<int> dp1(n+1);
        dp1[n]=a[n];
        int suma=a[n];
        int sumk=0;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>=dp1[i+1]) dp1[i]=a[i]; 
            else dp1[i]=max(dp1[i+1]+k[i]-a[i],a[i]);            
        }
        vector<int> suff(n+1);
        suma=a[n];
        sumk=0;
        suff[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            suma+=a[i];
            sumk+=k[i+1];
            suff[i]=suma-sumk;
            suff[i]=max(suff[i],suff[i+1]);
        }
        vector<int> pref(n+1);
        pref[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            pref[i]=max(a[i],pref[i-1]+a[i]-k[i]);
        }
        // pref[i] denotes this force will surely be applied if 1 to i falls
        vector<int> dp2(n+1);
        dp2[1]=a[1];
        suma=a[1];
        sumk=k[1];
        for(int i=2;i<=n;i++)
        {
            if(pref[i-1]>=a[i]){dp2[i]=dp2[i-1];}
            else
            {
                dp2[i]=max(dp2[i-1],a[i]-suma+sumk);
            }
            suma+=a[i]; // a[i] has fallen
            sumk+=k[i]; 
        }
        int ans=1e18;
        suma=0;
        sumk=0;
        for(int i=1;i<=n;i++){suma+=a[i];sumk+=k[i];}
        for(int i=1;i<=n;i++)
        {
            int force=1e18;
            if(suff[i]>=dp2[i-1])   
            {
                force=dp1[i];
            }
            else
            {
                force=dp2[i-1]-suma+sumk;
                force=max(force,dp1[i]);
            }
            suma-=a[i];
            sumk-=k[i];
            ans=min(ans,force);
            // cout << force << ' ';
        }
        // cout << endl;
        cout << ans <<endl;
    }
}
