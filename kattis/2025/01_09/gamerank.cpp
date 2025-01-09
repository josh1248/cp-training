#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

struct Rank {
    int r = 25;
    int stars = 0;
    int winstreak = 0;

    int req_stars(int rank) {
        return (rank >= 21 ? 2 : rank >= 16 ? 3 : rank >= 11 ? 4 : 5);
    }

    void win() {
        if (r == 0) {
            return;
        }

        winstreak++;
        stars++;
        if (winstreak >= 3 && r >= 6) {
            stars++;
        }

        int req = req_stars(r);
        if (stars > req) {
            r--;
            stars -= req;
        }
    }

    void lose() {
        if (r == 0) {
            return;
        }

        winstreak = 0;
        if (r > 20) {
            return;
        } else if (r == 20) {
            if (stars == 0) {
                return;
            } else {
                stars--;
            }
        } else {
            if (stars == 0) {
                r++;
                stars = req_stars(r) - 1;
            } else {
                stars--;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    Rank r;
    for (char c: s) {
        if (c == 'W') {
            r.win();
        } else {
            r.lose();
        }
    }  
    
    if (r.r == 0) {
        cout << "Legend\n";
    } else {
        cout << r.r << "\n";
    }
}