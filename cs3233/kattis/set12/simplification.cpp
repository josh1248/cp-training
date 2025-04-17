#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source: tinyKACTL
 * Description: Returns twice the signed area of a polygon.
 *  Clockwise enumeration gives negative area. Watch out for overflow if using int as T!
 * Status: Stress-tested and tested on kattis:polygonarea
 */

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}


// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    
    vector<pi> pts(N + 1);
    vector<bool> survived(N + 1, true);
    set<int> surviving_pts;
    rep(i, 0, N + 1) {
        int x, y; cin >> x >> y;
        surviving_pts.emplace(i);
        pts[i] = {x, y};
    }


    // store in min-PQ:
    // negated area of triangle (2x) for min-heap property
    // indices of the involed points, also negated for min-heap
    priority_queue<tuple<ll, int, int, int>> pq;

    // population of initial triangles
    rep(i, 0, N - 1) {
        Point<ll> start(pts[i].first, pts[i].second),
                mid(pts[i + 1].first, pts[i + 1].second),
                end(pts[i + 2].first, pts[i + 2].second);
        vector<Point<ll>> triangle({start, mid, end});
        ll area = abs(polygonArea2(triangle));
        pq.emplace(-area, -i, -(i + 1), -(i + 2));
    }

    vi res;
    // now, remove min area triangles slowly
    while (sz(pq) > 0 && sz(res) < (N - M)) {
        auto [neg_area, neg_p1, neg_p2, neg_p3] = pq.top(); pq.pop();
        int p1 = -neg_p1, p2 = -neg_p2, p3 = -neg_p3;
        if (!survived[p1] || !survived[p2] || !survived[p3]) continue;
        res.push_back(p2);

        survived[p2] = false;
        surviving_pts.erase(p2);
        auto nxt = next(surviving_pts.find(p3));
        if (nxt != surviving_pts.end()) {
            // construct new triangle involving start, end, and nxt
            int nxt_idx = *nxt;
            Point<ll> start(pts[p1].first, pts[p1].second),
                      end(pts[p3].first, pts[p3].second),
                      nxt_pt(pts[nxt_idx].first, pts[nxt_idx].second);
            vector<Point<ll>> triangle({start, end, nxt_pt});
            ll area = abs(polygonArea2(triangle));
            pq.emplace(-area, -p1, -p3, -nxt_idx);
        }

        auto preceding = surviving_pts.find(p1);
        if (preceding != surviving_pts.begin()) {
            preceding = prev(preceding);
            int preceding_idx = *preceding;
            Point<ll> preceding_pt(pts[preceding_idx].first, pts[preceding_idx].second),
                      start(pts[p1].first, pts[p1].second),
                      end(pts[p3].first, pts[p3].second);
            vector<Point<ll>> triangle({preceding_pt, start, end});
            ll area = abs(polygonArea2(triangle));
            pq.emplace(-area, -preceding_idx, -p1, -p3);
        }
    }

    for (int idx: res) cout << idx << "\n";
    return 0;
}