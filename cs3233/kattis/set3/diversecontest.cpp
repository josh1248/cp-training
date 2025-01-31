#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int top = 0;
    unordered_map<string, int> topics;
    vector<set<int>> questions(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            string s; cin >> s;
            if (topics.count(s) == 0) {
                topics[s] = top;
                top++;
            }
            questions[i].insert(topics[s]);
        }
    }

    vi select(k, 1);
    select.resize(n, 0);
    vi hits;
    int combis = 0;
    do {
        hits.assign(top, 0);
        for (int i = 0; i < n; i++) {
            if (select[i] == 0) continue;
            for (int t: questions[i]) {
                hits[t]++;
            }
        }

        if (all_of(all(hits), [&](int i){ return i <= k / 2;})) {
            combis++;
        }

    } while (prev_permutation(all(select)));
    cout << combis << "\n";

}