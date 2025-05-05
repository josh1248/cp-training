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

    int t; string s;
    getline(cin, s);
    t = stoi(s);
    while (t--) {
        string record; getline(cin, record);
        unordered_set<string> m;
        string check;
        while (getline(cin, check)) {
            if (check == "what does the fox say?") {
                stringstream ss(record);
                string x;
                while (ss >> x) {
                    if (m.count(x) == 0) cout << x << " ";
                }
                cout << "\n";
                break;
            } else {
                stringstream ss(check);
                string x, y, z;
                ss >> x >> y >> z;
                m.insert(z);
            }
        }
    }
}