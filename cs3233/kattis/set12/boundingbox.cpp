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
 * Date: 2009-04-11
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Circumcircle
 * Description:\\
\begin{minipage}{75mm}
The circumcirle of a triangle is the circle intersecting all three vertices. ccRadius returns the radius of the circle going through points A, B and C and ccCenter returns the center of the same circle.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-2mm}
\includegraphics[width=\textwidth]{content/geometry/circumcircle}
\end{minipage}
 * Status: tested
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
 
typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
            abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

double DEG_to_RAD(double d) { return d*M_PI / 180.0; }
double RAD_to_DEG(double r) { return r*180.0 / M_PI; }
// rotate p by theta degrees CCW w.r.t. origin (0, 0)
P rotate(const P &p, double theta) {     // theta in degrees
    double rad = DEG_to_RAD(theta);                // convert to radians
    return P(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cout << setprecision(12) << "\n";
    while (cin >> N) {
        if (N == 0) {
            return 0;
        }

        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point<double> p1(x1, y1), p2(x2, y2), p3(x3, y3);
        // find the unique circumcircle that inscribes all 3 points with radius and center
        Point<double> center = ccCenter(p1, p2, p3);

        // transform pt based on center
        Point<double> start(x1 - center.x, y1 - center.y);
        
        double minx = start.x, maxx = start.x, miny = start.y, maxy = start.y;
        // rotate to recover all points
        Point<double> curr(start);
        rep(i, 0, N - 1) {
            curr = rotate(curr, 360.0 / N);
            minx = min(minx, curr.x), maxx = max(maxx, curr.x);
            miny = min(miny, curr.y), maxy = max(maxy, curr.y);
        }
        cout << (maxx - minx) * (maxy - miny) << "\n";
    }
}