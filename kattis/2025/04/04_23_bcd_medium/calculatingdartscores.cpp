#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi parent(181, -1);
    queue<int> q;
    q.emplace(0);
    while(sz(q) > 0) {
        int u = q.front(); q.pop();
        rep(i, 1, 21) {
            rep(j, 1, 4) {
                int newscore = u + i * j;
                if (newscore >= 0 && newscore <= 180 && parent[newscore] == -1) {
                    parent[newscore] = u;
                    q.emplace(newscore);
                }
            }
        }
    }
    int target; cin >> target;
    vi traversal;
    int curr = target;
    while (parent[curr] != -1) {
        curr = parent[curr];
        traversal.emplace_back(curr);
    }
    if (sz(traversal) > 3) {
        cout << "impossible\n";
    } else {
        int prev = target;
        for (int i: traversal) {
            int score = prev - i;
            if (score % 3 == 0) {
                cout << "triple " << score / 3 << "\n"; 
            } else if (score % 2 == 0) {
                cout << "double " << score / 2 << "\n";
            } else {
                cout << "single " << score << "\n";
            }
            prev = i;
        }
    }
}