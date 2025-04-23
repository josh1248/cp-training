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

    int start; cin >> start;
    string flush; getline(cin, flush);
    vi down(100, -1);
    string x;
    while (getline(cin, x)) {
        if (x == "-1") break;
        stringstream ss(x);
        int p; ss >> p;
        int z;
        while (ss >> z) {
            down[z] = p;
        }
    }
    int curr = start;
    while (curr != -1) {
        cout << curr << " ";
        curr = down[curr];
    }
    cout << "\n";
}