#include <bits/stdc++.h>
using namespace std;

int fence;
set<pair<int, int>> actual_parameters;
set<pair<int, int>> marked;
set<pair<int, int>> exptrue;

void dfs(int a, int b){
    if(marked.count({a, b}) || !exptrue.count({a, b})) return;
    fence+=4;
    marked.insert({a, b});
    actual_parameters.erase({a, b});
    if(exptrue.count({a, b+1})){
        fence--;
        if(!marked.count({a, b+1})) dfs(a, b+1);
    }
    if(exptrue.count({a, b-1})){
        fence--;
        if(!marked.count({a, b-1})) dfs(a, b-1);
    }
    if(exptrue.count({a+1, b})){
        fence--;
        if(!marked.count({a+1, b})) dfs(a+1, b);
    }
    if(exptrue.count({a-1, b})){
        fence--;
        if(!marked.count({a-1, b})) dfs(a-1, b);
    }
}

void solve(){
    int r, c, n;
    std::cin >> r >> c >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        actual_parameters.insert({x, y});
        exptrue.insert({x, y});
    }
    int a, b;
    int out = 0;
    while(actual_parameters.size()>0){
        tie(a, b) = *actual_parameters.begin();
        fence = 0;
        dfs(a, b);
        out = max(fence, out);
        tie(a, b) = *actual_parameters.begin();
    }
    std::cout << out << std::endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	solve();
	return 0;
}
