#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> sieve(1000001, true);
    vector<int> primes; primes.reserve(1000000);
    for(int i = 2; i<1000000; i++){
        if(sieve[i] == true){
            primes.push_back(i);
            for(int j = 2*i; j<1000000; j+=i){
                sieve[j] = false;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        if(n%2 == 1){
            cout << "1 ";
            n--;
        }
        int i = 0;
        while(true){
            if(n){
                cout << primes[i] << " ";
                n--;
            }
            if(n){
                cout << primes[i] << " ";
                n--;
            }
            i++;
            if(n==0){
                break;
            }
            // cout << primes[i] << " " << primes[i] << " ";
        }
        
        cout << endl;
    }
}
