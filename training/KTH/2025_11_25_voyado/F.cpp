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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> curr_strs(n);
    vector<bool> usable(n, true);
    string s;
    rep(i, 0, n) cin >> curr_strs[i];

    bool has_answer = false;
    int shortest = 1e9;
    string best_answer;
    function<void(int)> backtracker = [&](int usables) {
        if (usables == 1) {
            rep(i, 0, n) {
                if (usable[i]) {
                    if (!has_answer) {
                        has_answer = true;
                        best_answer = curr_strs[i];
                        shortest = curr_strs[i].size();
                        return;
                    } else {
                        if (curr_strs[i].size() < shortest) {
                            shortest = curr_strs[i].size();
                            best_answer = curr_strs[i];
                        } else if (curr_strs[i].size() == shortest) {
                            best_answer = min(best_answer, curr_strs[i]);
                        }           
                        return;
                    }
                }
            }
        } else {
            rep(l, 0, n) {
                rep(r, l + 1, n) {
                    if (!(usable[l] && usable[r])) {
                        continue;
                    }

                    int len_l = curr_strs[l].size(), len_r = curr_strs[r].size();
                    rep(k, 1, min(len_l, len_r) + 1) {
                        string tmp;
                        if (curr_strs[l].substr(len_l - k) == curr_strs[r].substr(0, k)) {
                            tmp = curr_strs[l];
                            curr_strs[l] = curr_strs[l] + curr_strs[r].substr(k);
                            usable[r] = false;
                            backtracker(usables - 1);
                            usable[r] = true;
                            curr_strs[l] = tmp;
                        }
                        if (curr_strs[r].substr(len_r - k) == curr_strs[l].substr(0, k)) {
                            tmp = curr_strs[r];
                            curr_strs[r] = curr_strs[r] + curr_strs[l].substr(k);
                            usable[l] = false;
                            backtracker(usables - 1);
                            usable[l] = true;
                            curr_strs[r] = tmp;
                        }
                    }
                }
            }
        }
    };

    backtracker(n);

    if (has_answer) {
        cout << best_answer << "\n";
    } else {
        cout << -1 << "\n";
    }
}