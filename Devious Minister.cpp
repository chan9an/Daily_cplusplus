#include <bits/stdc++.h>

using namespace std;

void cal(vector<long>& vec) {
    int n = vec.size();
    vector<long> sum(n+1, 0);
    vector<int> idx(n+1, 0);
    for(int i=0;i<n;i++) {
        idx[i+1] = i+1;
        sum[i+1]=sum[i]+vec[i];
    }
    sort(idx.begin(), idx.end(), [&sum](int i, int j){
        return sum[i] < sum[j];
    });
    long res = vec[0], l=0, r=0;
    for(int i=0;i<=n;i++) {
        int j = i;
        while(j<n && (i==j || sum[idx[j]]==sum[idx[j+1]])) {
            j++;
            long ans = sum[idx[j]]-sum[idx[i]];
            if(abs(res)>abs(ans)) {
                res = ans, l=idx[i], r=idx[j];
            } else if(abs(res)==abs(ans) && abs(r-l)<abs(idx[i]-idx[j])) {
                res = ans, l=idx[i], r=idx[j];
            }
        }
    }
    if(r>l) {
        cout<<res<<endl;
        cout<<(l+1)<<" "<<r<<endl;
    } else {
        cout<<(-res)<<endl;
        cout<<(r+1)<<" "<<l<<endl;
    }
}
 
int main() {
    
    int n;
    cin>>n;
    vector<long> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cal(arr);
	return 0;
}
