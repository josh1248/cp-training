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

    int missinglu = 0, missingld = 0, missingru = 0, missingrd = 0;
    bool bluel = false, bluer = false;
    int x; cin >> x;
    string s; char cond;
    rep(i, 0, x) {
        cin >> s >> cond;
        if (s[0] == '-' || s[0] == '+') {
            if (cond == 'b') bluel = true;
            else if (s[0] == '-') missingld++;
            else missinglu++;
        } else {
            if (cond == 'b') bluer = true;
            else if (s[1] == '-') missingrd++;
            else missingru++;
        }
    }
    if (!bluel && missingld != 8 && missinglu != 8) {
        cout << 0;
    } else if (!bluer && missingrd != 8 && missingru != 8) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << "\n";
}