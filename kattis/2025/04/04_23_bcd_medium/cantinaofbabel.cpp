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

    string s; getline(cin, s);
    unordered_map<string, int> language_mapping;
    int idx = 0;
    int V = stoi(s);
    vvi speak, understand;
    rep(i, 0, V) {
        getline(cin, s);
        stringstream ss(s);
        string x;
        ss >> x; // ignore name
        ss >> x; // spoken
        if (language_mapping.count(x) == 0) {
            language_mapping[x] = idx++;
            speak.push_back(vi());
            understand.push_back(vi());
        }
        speak[language_mapping[x]].push_back(i);

        while (ss >> x) {
            if (language_mapping.count(x) == 0) {
                language_mapping[x] = idx++;
                speak.push_back(vi());
                understand.push_back(vi());
            }
            understand[language_mapping[x]].push_back(i);
        }
    }

    vvi AL(V);
    rep(i, 0, idx) {
        // edge: can understand
        for (int u: speak[i]) {
            for (int v: speak[i]) {
                if (u == v) continue;
                AL[u].push_back(v);
                AL[v].push_back(u);
            }
            for (int v: understand[i]) {
                AL[u].push_back(v);
            }
        }
    }

    int best = 0;

    // find largest SCC with directed Tarjan
    // https://www.topcoder.com/thrive/articles/tarjans-algorithm-for-strongly-connected-components
    vi lo(V, -1), visittime(V, -1);
    int timer = 0;
    vi stack;
    vector<bool> visiting(V, false);
    function<void(int)> tarjan = [&](int u) {
        lo[u] = visittime[u] = timer++;
        stack.push_back(u); visiting[u] = true;
        for (int v: AL[u]) {
            if (visittime[v] == -1) {
                tarjan(v);
                lo[u] = min(lo[u], lo[v]);
            } else if (visiting[v]) {
                lo[u] = min(lo[u], visittime[v]);
            }
        }

        if (lo[u] == visittime[u]) {
            int SCCsize = 0;
            while (true) {
                int v = stack.back(); stack.pop_back();
                visiting[v] = false;
                SCCsize++;
                if (v == u) break;
            }
            best = max(best, SCCsize);
        }
    };
    rep(i, 0, V) {
        if (visittime[i] == -1) tarjan(i);
    }

    cout << V - best << "\n";
}