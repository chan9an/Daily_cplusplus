/*https://www.codechef.com/ZCOPRAC/problems/ZCO23002?tab=submissions*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct point {
    long long x, y;
    point(){};
    point(long long x, long long y) : x(x), y(y){}
    point operator- (point p){
        return point(x-p.x,y-p.y);
    }
    static long long cross_product(point p1, point p2){
        return p1.x * p2.y - p2.x * p1.y;
    }
    static long long direction(point p1, point p2, point p3){
        return cross_product(p3-p1,p2-p1);
    }    
};
struct line {
    point a, b;
    line(point a, point b) : a(a), b(b){}
};

vector<point>points;
vector<line> convex_hull;
bool turn_left(){
    int sz = convex_hull.size();
    line line1 = convex_hull[sz-2];
    line line2 = convex_hull[sz-1];
    point p1 = line1.a;
    point p2 = line1.b;
    point p3 = line2.b;
    return point::direction(p1,p2,p3) < 0;
}
int n, p;
bool sort_points(point const &a, point const &b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}
int main(){
    cin >> n >> p;
    long long xmax = 0;
    vector<pair<long long, long long>> scores(n);
    set<pair<long long, long long>> unq_scores;
    for(int i = 0; i < n; i++){
        cin >> scores[i].first >> scores[i].second;
        xmax = max(xmax,scores[i].first);
        unq_scores.insert({scores[i].first,scores[i].second});
    }    
    for(auto it = unq_scores.begin(); it != unq_scores.end(); it++)
        points.push_back(point(it->first, it->second));
    if(n == 1){
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }else if(n == 2){
        if(points.size() == 1){
            cout << 2 << '\n';
            cout << 1 << ' ' << 2 << '\n';
        }else{
            if(scores[0].first > scores[1].first &&
               scores[0].second > scores[1].second){
                cout << 1 << '\n';
                cout << 1 << '\n';
            }else if(scores[0].first < scores[1].first &&
               scores[0].second < scores[1].second){
                cout << 1 << '\n';
                cout << 2 << '\n';
            }else{
                cout << 2 << '\n';
                cout << 1 << ' ' << 2 << '\n';
            }
        }
        return 0;
    }
    sort(points.begin(), points.end(), sort_points);
    convex_hull.push_back(line(points[0], points[1]));

    for(int i = 2; i < points.size(); i++){
        convex_hull.push_back(line(points[i-1],points[i]));
        while(convex_hull.size() > 1 && turn_left()){
            convex_hull.pop_back();
            convex_hull.pop_back();
            if(convex_hull.size() == 0)
                convex_hull.push_back(line(points[0], points[i]));
            else
                convex_hull.push_back(line(convex_hull.back().b, points[i]));
        }
    }    
    while(convex_hull.size() > 0 && convex_hull.back().b.x < xmax)
        convex_hull.pop_back();
    set<pair<int, int>>winning_scores;
    for(int i = 0; i < convex_hull.size(); i++){
        winning_scores.insert({convex_hull[i].a.x,convex_hull[i].a.y});
        winning_scores.insert({convex_hull[i].b.x,convex_hull[i].b.y});
    }
    if(winning_scores.size() == 0)
        winning_scores.insert({points[0].x,points[0].y});
    vector<int> winners;
    for(int i = 0; i < n; i++){
        pair<int, int> score = scores[i];
        if(winning_scores.find(score) != winning_scores.end())
            winners.push_back(i+1);
    }
    cout << winners.size() << '\n';
    for(auto winner: winners)
        cout << winner <<' ';
    cout << '\n';
    return 0;
}
