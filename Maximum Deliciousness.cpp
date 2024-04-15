/*  ____ _  __
 * |  _ \ |/ /
 * | |_)| ' /   Praneet Kumar
 * |  __/ . \   https://www.gitlab.com/praneetk96
 * |_|  |_|\_\
 *
 * Codechef's problem code: KDELI
 * Date: 09-04-2024
*/

#include<bits/stdc++.h>
using namespace std;
#define floop(i,a,b) for(i=a;i<b;i++)
#define floop1(i,a,b) for(i=a;i<=b;i++)
#define floop2(i,a,b) for(i=a;i>=b;i--)
typedef long long ll;
template <typename T> bool chmin(T& a, const T& b) { return (b < a) ? (a = b, true) : false; }
template <typename T> bool chmax(T& a, const T& b) { return (a < b) ? (a = b, true) : false; }
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;

int solve() {
    ll totalPastries,peoples,initPos,i,totalRatings=0; std::cin >> totalPastries >> peoples >> initPos;
    ll ratings[totalPastries],tmpArr[totalPastries]; floop(i,0,totalPastries) { std::cin >> ratings[i]; }
    sort(ratings,ratings+totalPastries);
    
    floop(i,0,totalPastries) {
        tmpArr[i] = ratings[totalPastries-1-i];
    }

    i=0;
    while(i*peoples+initPos < totalPastries+1) {
        totalRatings = totalRatings+tmpArr[i*peoples+initPos-1];
        i++;
    }

    std::cout << totalRatings << std::endl;
    return 0;
}

int main() {
    ll testCases;
    std::cin >> testCases;
    while(testCases--) {
        solve();
    }
    return 0;
}
