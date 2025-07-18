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
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two integers $x$ and $y$, such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 */
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

void solve() {
    ll n, x, y, vx, vy;
    cin >> n >> x >> y >> vx >> vy;
    // Draw a grid of reflected triangles.then model the plane as going through each triangle
    // and into the reflected triangle (either diagonally, horizontally, or vertically). This maintains
    // angle of incidence = angle of reflection.
    // reach one of the reflected triangle vertices -> escape
    // vertices are modelled as (k1n, k2n) for some integer k1, k2.

    /*
        solve x + t * vx = k1n, y + t * vy = k2n
        equating to t yields (k1n - x) / vx = (k2n - y) / vy
        (k1n - x) * vy = (k2n - y) * vx
        k1 * n * vy - x * vy = k2 * n * vx - y * vx
        k1 * n * vy - k2 * n * vx = x * vy - y * vx
        only k1 and k2 is unknown, so this is the diophantine equation to solve
    */
   ll k1_coefficient = n * vy, k2_coefficient = -n * vx, c = x * vy - y * vx;

    /*
        gcd test - try to simplify LHS by dividing their shared factors. If RHS is no longer an integer, cfm cannot
    */
    ll shared_factor = gcd(k1_coefficient, k2_coefficient);
    if (c % shared_factor != 0) {
        cout << -1 << "\n";
        return;
    }
    k1_coefficient /= shared_factor;
    k2_coefficient /= shared_factor;
    c /= shared_factor;


    ll xsol, ysol;
    if (c == 0) {
        // If c = 0, then k1 (a) + k2 (b) = 0 -> k1 = b, k2 = -a
        xsol = k2_coefficient, ysol = -k1_coefficient;
    } else {
        // kactl to get solns to ax + by = gcd(a, b) = 1
        // mult by c to get actual answer
        euclid(k1_coefficient, k2_coefficient, xsol, ysol);
        xsol *= c, ysol *= c;
    }

    ll verts = max(0ll, abs(ysol) - 1ll);
    ll horzs = max(0ll, abs(xsol) - 1ll);

    // top left - bottom right diagonals: x + y = 1 + 2k
    // easier since (x, y) monotonically increases
    ll d1 = abs(xsol + ysol) % 2;
    ll d2 = abs(xsol - ysol) % 2;
    cout << verts + horzs + d1 + d2 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}