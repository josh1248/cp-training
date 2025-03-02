#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/136455
#define int long long

// https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)size(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, m, i = 0, j = 0; cin >> n >> m;
	string a, b; cin >> a >> b;
	char prev = '2';
	for (; i < n && j < m; ++i) {
		if (a[i] == b[j]) {
			++j;
			prev = a[i];
			continue;
		}
		if (a[i] == '1' && b[j] == '0') {
		} else if (prev == '0') {
		} else {
			prev = '0';
			while (b[j] == '1' && j >= 0)
			{
				--j;
			}
			if (j < 0) {cout << "no\n"; return;}
			++j;
		}
	}
	if (i != n || j != m) {
		cout << "no\n";
		return;
	}
	cout << "yes\n";
}

// https://codeforces.com/blog/entry/136455
// https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
