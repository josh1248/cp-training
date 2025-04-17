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
 * Author: Victor Lecomte, chilli
 * Date: 2019-04-27
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description:\\
\begin{minipage}{75mm}
If a unique intersection point between the line segments going from s1 to e1 and from s2 to e2 exists then it is returned.
If no intersection point exists an empty vector is returned.
If infinitely many exist a vector with 2 elements is returned, containing the endpoints of the common line segment.
The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
Products of three coordinates are used in intermediate steps so watch out for overflow if using int or long long.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{content/geometry/SegmentIntersection}
\end{minipage}
 * Usage:
 * vector<P> inter = segInter(s1,e1,s2,e2);
 * if (sz(inter)==1)
 *   cout << "segments intersect at " << inter[0] << endl;
 * Status: stress-tested, tested on kattis:intersection
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
 
 template<class P> bool onSegment(P s, P e, P p) {
     return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
 }
 
 template<class P> vector<P> segInter(P a, P b, P c, P d) {
     auto oa = c.cross(d, a), ob = c.cross(d, b),
          oc = a.cross(b, c), od = a.cross(b, d);
     // Checks if intersection is single non-endpoint point.
     if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
         return {(a * ob - b * oa) / (ob - oa)};
     set<P> s;
     if (onSegment(c, d, a)) s.insert(a);
     if (onSegment(c, d, b)) s.insert(b);
     if (onSegment(a, b, c)) s.insert(c);
     if (onSegment(a, b, d)) s.insert(d);
     return {all(s)};
 }

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    Point start(0.0, 0.0), end(0.0, 10000.0);
    vector<pair<Point<double>, Point<double>>> barricades(N);
    rep(i, 0, N) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        barricades[i] = {Point(x1, y1), Point(x2, y2)};
    }
    double lowesty = 10000.0;
    rep(i, 0, N) {
        vector<Point<double>> pts = segInter(barricades[i].first, barricades[i].second, start, end);
        if (sz(pts) == 1) {
            lowesty = min(lowesty, pts[0].y);
        }
    }
    
    if (lowesty == 10000.0) {
        cout << "-1.0" << "\n";
    } else {
        cout << setprecision(12) << lowesty << "\n";
    }

}